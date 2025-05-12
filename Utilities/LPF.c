/*
 * LPF.c
 *
 *  Created on: May 1, 2025
 *      Author: JeonghWhanPro
 */
#include "LPF.h"

#include <stdlib.h> // For malloc/free
#include <string.h> // For memset

float32_t LPF_coefficients[10] =
{
// Scaled for floating point

    0.14850408501517734, 0.2970081700303547, 0.14850408501517734, 0.6727409111915273, -0.14453519983312102,// b0, b1, b2, a1, a2
    0.125, 0.25, 0.125, 0.8976579400366446, -0.5271869046315973// b0, b1, b2, a1, a2
};

LPFType *LPF_create( void )
{
    LPFType *result = (LPFType *)malloc( sizeof( LPFType ) ); // Allocate memory for the object
    LPF_init( result );  // Initialize it
    return result;    // Return the result
}

void LPF_destroy( LPFType *pObject )
{
    free( pObject );
}

void LPF_init( LPFType * pThis )
{
	arm_biquad_cascade_df1_init_f32(	&pThis->instance, LPF_numStages, LPF_coefficients, pThis->state );
	LPF_reset( pThis );
}

void LPF_reset( LPFType * pThis )
{
	memset( &pThis->state, 0, sizeof( pThis->state ) ); // Reset state to 0
	pThis->output = 0;									// Reset output
}

int LPF_filterBlock( LPFType * pThis, float * pInput, float * pOutput, unsigned int count )
{
	arm_biquad_cascade_df1_f32( &pThis->instance, pInput, pOutput, count );
	return count;
}


