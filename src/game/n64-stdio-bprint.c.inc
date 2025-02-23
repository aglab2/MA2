#include "n64-stddef.h"

#include "n64-stdio-format.c.inc"

typedef enum {
	CSI_ALIGNMENT,
	CSI_SIGN,
	CSI_SPACE,
	CSI_ALTERNATE,
	CSI_ZEROPAD,
	CSI_WIDTH,
	CSI_PRECISION,
	CSI_LENGTH,
	CSI_FORMAT
} n64_csi;

enum {
	FMT_CHAR,
	FMT_STRING,
	FMT_DEC,
	FMT_UDEC,
	FMT_HEX,
	FMT_FLOAT,
	FMT_EFLOAT,
};

#define PCS_VARIABLE 0xAAAAAAAAu
#define PCS_DEFAULT 0xBBBBBBBBu

static const char *parse_conversion_specifier( const char *format, n64_format_args *args ) {
	args->width = 0u;
	args->dataSize = 4u;
	args->precision = PCS_DEFAULT;
	args->defaultPrecision = 1u;
	args->leftAligned = false;
	args->alternate = false;
	args->capitalize = false;
	args->padchar = ' ';
	args->poschar = '\0';

	n64_csi csi = CSI_ALIGNMENT;
	while( *format != '\0' ) {
		switch( csi ) {
			case CSI_ALIGNMENT:
				if( *format == '-' ) {
					args->leftAligned = true;
					format++;
				}
				csi = CSI_SIGN;
				__attribute__((fallthrough));
			case CSI_SIGN:
				if( *format == '+' ) {
					args->poschar = '+';
					format++;
				}
				csi = CSI_SPACE;
				__attribute__((fallthrough));
			case CSI_SPACE:
				if( *format == ' ' ) {
					if( args->poschar != '+' ) args->poschar = ' ';
					format++;
				}
				csi = CSI_ALTERNATE;
				__attribute__((fallthrough));
			case CSI_ALTERNATE:
				if( *format == '#' ) {
					args->alternate = true;
					format++;
				}
				csi = CSI_ZEROPAD;
				__attribute__((fallthrough));
			case CSI_ZEROPAD:
				if( *format == '0' ) {
					args->padchar = '0';
					format++;
				}
				csi = CSI_WIDTH;
				__attribute__((fallthrough));
			case CSI_WIDTH:
				if( *format == '-' ) {
					args->leftAligned = true;
					format++;
					continue;
				} else if( *format == '0' ) {
					format++;
					continue;
				} else if( *format == '*' ) {
					args->width = PCS_VARIABLE;
					format++;
				} else if( *format > '0' && *format <= '9' ) {
					int w = 0;
					while( *format >= '0' && *format <= '9' ) {
						w *= 10;
						if( w < 0 ) return NULL;
						w += (int)*format - (int)'0';
						format++;
					}
					args->width = (unsigned int)w;
				}
				csi = CSI_PRECISION;
				__attribute__((fallthrough));
			case CSI_PRECISION:
				if( *format == '.' ) {
					format++;
					if( *format == '-' ) {
						format++;
						while( *format >= '0' && *format <= '9' ) format++;
					} else if( *format == '*' ) {
						args->precision = PCS_VARIABLE;
						format++;
					} else if( *format >= '0' && *format <= '9' ) {
						int p = 0;
						while( *format >= '0' && *format <= '9' ) {
							p *= 10;
							if( p < 0 ) return NULL;
							p += (int)*format - (int)'0';
							format++;
						}
						args->precision = (unsigned int)p;
					} else {
						return NULL;
					}
				}
				csi = CSI_LENGTH;
				__attribute__((fallthrough));
			case CSI_LENGTH:
				switch( *format ) {
					case 'h':
						format++;
						if( *format == 'h' ) {
							args->dataSize = 1u;
							format++;
						} else {
							args->dataSize = 2u;
						}
						break;
					case 'l':
						format++;
						break;
					case 'j':
					case 'L':
						format++;
						break;
					case 'z':
						args->dataSize = __SIZEOF_SIZE_T__;
						format++;
						break;
					case 't':
						args->dataSize = __SIZEOF_PTRDIFF_T__;
						format++;
						break;
					default:
						break;
				}
				csi = CSI_FORMAT;
				__attribute__((fallthrough));
			case CSI_FORMAT:
				switch( *format ) {
					case 'c':
						args->type = FMT_CHAR;
						args->dataSize = 1;
						break;
					case 's':
						args->type = FMT_STRING;
						args->dataSize = 1;
						args->defaultPrecision = 0xFFFFFFFFu;
						break;
					case 'd':
					case 'i':
						args->type = FMT_DEC;
						if( args->precision != PCS_DEFAULT ) args->padchar = ' ';
						break;
#if 0
					case 'o':
						args->type = 'o';
						args->poschar = '\0';
						if( args->precision != PCS_DEFAULT ) args->padchar = ' ';
						break;
#endif
					case 'X':
						args->capitalize = true;
						__attribute__((fallthrough));
					case 'x':
						args->type = FMT_HEX;
						args->poschar = '\0';
						if( args->precision != PCS_DEFAULT ) args->padchar = ' ';
						break;
					case 'B':
						args->capitalize = true;
						__attribute__((fallthrough));
#if 0
					case 'b':
						args->type = 'b';
						args->poschar = '\0';
						if( args->precision != PCS_DEFAULT ) args->padchar = ' ';
						break;
#endif
					case 'u':
						args->type = FMT_UDEC;
						args->poschar = '\0';
						if( args->precision != PCS_DEFAULT ) args->padchar = ' ';
						break;
					case 'F':
						args->capitalize = true;
						__attribute__((fallthrough));
					case 'f':
						args->type = FMT_FLOAT;
						args->dataSize = 4u;
						args->defaultPrecision = 6u;
						break;
					case 'E':
						args->capitalize = true;
						__attribute__((fallthrough));
					case 'e':
						args->type = FMT_EFLOAT;
						args->dataSize = 4u;
						args->defaultPrecision = 6u;
						break;
					case 'A':
						args->capitalize = true;
						__attribute__((fallthrough));
#if 0
					case 'a':
						args->type = 'a';
						args->dataSize = 4u;
						args->defaultPrecision = 0xffffffffu;
						break;
					case 'G':
						args->capitalize = true;
						__attribute__((fallthrough));
					case 'g':
						args->type = 'g';
						args->dataSize = 4u;
						args->defaultPrecision = 6u;
						break;
					case 'n':
						args->type = 'n';
						break;
					case 'p':
						args->type = 'p';
						args->dataSize = 4u;
						break;
#endif
					default:
						return NULL;
				}
				return ++format;
			default:
				return NULL;
		}
	}

	return NULL;
}

static int n64_vbprintf( char *_buffer, void *state, const char *format, __builtin_va_list args ) {
	n64_bprint_buffer buff = {
		/* start */ _buffer,
		/* head */ _buffer,
		state,
		0u
	};

	while( *format != '\0' ) {
		if( *format != '%' ) {
			n64_putc( &buff, *format );
			format++;
			continue;
		}

		if( format[1] == '%' ) {
			n64_putc( &buff, '%' );
			format += 2;
			continue;
		}

		n64_format_args fmt;
		format = parse_conversion_specifier( ++format, &fmt );
		if( !format ) return -1;

		if( fmt.width == PCS_VARIABLE ) {
			const int w = __builtin_va_arg( args, int );
			if( w < 0 ) {
				fmt.leftAligned = true;
				fmt.width = (unsigned int)-w;
			} else {
				fmt.width = (unsigned int)w;
			}
		}

		if( fmt.precision == PCS_VARIABLE ) {
			const int p = __builtin_va_arg( args, int );
			fmt.precision = (p < 0) ? fmt.defaultPrecision : (unsigned int)p;
		} else if( fmt.precision == PCS_DEFAULT ) {
			fmt.precision = fmt.defaultPrecision;
		}

		switch( fmt.type ) {
			case FMT_CHAR: {
				const char c = (char)__builtin_va_arg( args, int );
				n64_format_char( &buff, &fmt, c );
				break;
			}
			case FMT_STRING: {
				const char *str = (const char*)__builtin_va_arg( args, const char* );
				n64_format_string( &buff, &fmt, str );
				break;
			}
			case FMT_DEC: {
				{
					int val = __builtin_va_arg( args, int );
					if( fmt.dataSize == 2 ) {
						val = (int)(short)val;
					} else if( fmt.dataSize == 1 ) {
						val = (int)(signed char)val;
					}
					n64_format_sdec32( &buff, &fmt, val );
				}
				break;
			}
			case FMT_UDEC: {
				{
					unsigned int val = __builtin_va_arg( args, unsigned int );
					if( fmt.dataSize == 2 ) {
						val &= 0xFFFFu;
					} else if( fmt.dataSize == 1 ) {
						val &= 0xFFu;
					}
					n64_format_udec32( &buff, &fmt, val );
				}
				break;
			}
#if 0
			case 'o': {
				{
					unsigned int val = __builtin_va_arg( args, unsigned int );
					if( fmt.dataSize == 2 ) {
						val &= 0xFFFFu;
					} else if( fmt.dataSize == 1 ) {
						val &= 0xFFu;
					}
					n64_format_oct32( &buff, &fmt, val );
				}
				break;
			}
#endif
			case FMT_HEX: {
				{
					unsigned int val = __builtin_va_arg( args, unsigned int );
					if( fmt.dataSize == 2 ) {
						val &= 0xFFFFu;
					} else if( fmt.dataSize == 1 ) {
						val &= 0xFFu;
					}
					n64_format_hex32( &buff, &fmt, val );
				}
				break;
			}
			case FMT_FLOAT:
			case FMT_EFLOAT: {
				const double val = __builtin_va_arg( args, double );
				n64_format_float( &buff, &fmt, (float)val );
				break;
			}
			default:
				return -1;
		}
	}

	_buffer[buff.head - buff.start] = '\0';
	return (int)buff.total;
}

static int n64_bprintf( char *buffer, void *state, const char *format, ... ) {
	__builtin_va_list args;
	__builtin_va_start( args, format );
	register const int result = n64_vbprintf( buffer, state, format, args );
	__builtin_va_end( args );
	return result;
}
