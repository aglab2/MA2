#include "n64-stdio.h"

#include "n64-util.h"

#include "n64-stdio-bprint.c.inc"

int vsprintf( char *buffer, const char *format, __builtin_va_list args ) {
	return n64_vbprintf( buffer, buffer, format, args );
}

int sprintf( char *buffer, const char *format, ... )
{
	__builtin_va_list args;
	__builtin_va_start( args, format );
	const int result = vsprintf( buffer, format, args );
	__builtin_va_end( args );
	return result;
}
