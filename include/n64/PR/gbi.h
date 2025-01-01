#include <PR/ultratypes.h>
#include <config.h>

/*
 * Converts texel coordinates to S and T values
 */
// Bilerp/Average filter
#define TC_B_OFF	-0.5
#define TC_B(p)		(((p) + TC_B_OFF) * 32)
// #define TC_B(p)		((((p) > TC_B_OFF) ? ((p) - TC_B_OFF) : (p)) * 32)
#define ST_B(s, t)	{TC_B(s), TC_B(t)}

// Point filter
#define TX_P_OFF	0.25
#define TC_P(p)		(((p) + TX_P_OFF) * 32)
#define ST_P(s, t)	{TC_P(s), TC_P(t)}

#ifdef F3DEX3
#include "gbi-ex3.h"
#else
#include "gbi-ex2.h"
#endif
