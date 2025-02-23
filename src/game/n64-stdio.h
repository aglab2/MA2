#ifndef N64_STDLIB_N64_STDIO_H_
#define N64_STDLIB_N64_STDIO_H_

#include "n64-stddef.h"
#include "n64-stdbool.h"

#ifndef EOF
#define EOF -1
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* IMPORTANT NOTICE
 * The printf family of functions provided have some important deviations from the C standard library:
 * 1. The floating point formats (%f, %e, %g, and %a) expect a (32-bit) float instead of a double. To format a double, use the 'l'
 *    length modifier (ie. %lf, %le, %lg, or %la) to indicate that the argument is double precision. You can still pass in a
 *    double argument, however it will be cast to a float if the 'l', 'll', or 'L' length specifier is not present.
 * 2. Formatting 128-bit long doubles is not supported. The 'L' length specifier is treated the same as 'll'
 * 3. The 'l' length modifier is ignored for characters and strings (wide chars are not supported)
 */

__attribute__((format(printf, 2, 3), nonnull(1)))
int sprintf( char *buffer, const char *format, ... );
int vsprintf( char *buffer, const char *format, __builtin_va_list args );

#ifdef __cplusplus
}
#endif

#endif
