/*
 * LPF.h
 *
 *  Created on: May 1, 2025
 *      Author: JeonghWhanPro
 */

// Begin header file, LPF.h

#ifndef LPF_H_ // Include guards
#define LPF_H_

#define ARM_MATH_CM4  // Use ARM Cortex M4
#include <arm_math.h>    // Include CMSIS header

// Link with library: libarm_cortexM4l_math.a (or equivalent)
// Add CMSIS/Lib/GCC to the library search path
// Add CMSIS/Include to the include search path
/*
Generated code is based on the following filter design:
<micro.DSP.FilterDocument sampleFrequency="#100" arithmetic="float" biquads="Direct1" classname="LPF" inputMax="#1" inputShift="#15" >
  <micro.DSP.IirButterworthFilter N="#4" bandType="l" w1="#0.15" w2="#0.41100000000000003" stopbandRipple="#undefined" passbandRipple="#undefined" transitionRatio="#undefined" >
    <micro.DSP.FilterStructure coefficientBits="#0" variableBits="#0" accumulatorBits="#0" biquads="Direct1" >
      <micro.DSP.FilterSection form="Direct1" historyType="Double" accumulatorBits="#0" variableBits="#0" coefficientBits="#0" />
      <micro.DSP.FilterSection form="Direct1" historyType="Double" accumulatorBits="#0" variableBits="#0" coefficientBits="#0" />
    </micro.DSP.FilterStructure>
    <micro.DSP.PoleOrZeroContainer >
      <micro.DSP.PoleOrZero i="#0.5707358936530007" r="#0.4488289700183223" isPoint="#true" isPole="#true" isZero="#false" symmetry="c" N="#1" cascade="#1" />
      <micro.DSP.PoleOrZero i="#0.17717256118095545" r="#0.3363704555957637" isPoint="#true" isPole="#true" isZero="#false" symmetry="c" N="#1" cascade="#0" />
      <micro.DSP.PoleOrZero i="#0" r="#-1" isPoint="#true" isPole="#false" isZero="#true" symmetry="r" N="#1" cascade="#0" />
      <micro.DSP.PoleOrZero i="#0" r="#-1" isPoint="#true" isPole="#false" isZero="#true" symmetry="r" N="#1" cascade="#0" />
      <micro.DSP.PoleOrZero i="#0" r="#-1" isPoint="#true" isPole="#false" isZero="#true" symmetry="r" N="#1" cascade="#1" />
      <micro.DSP.PoleOrZero i="#0" r="#-1" isPoint="#true" isPole="#false" isZero="#true" symmetry="r" N="#1" cascade="#1" />
    </micro.DSP.PoleOrZeroContainer>
    <micro.DSP.CMSIS.CodeGenerator cpu="M4" generateTestCases="#false" />
    <micro.DSP.GainControl magnitude="#1" frequency="#0" peak="#true" />
  </micro.DSP.IirButterworthFilter>
</micro.DSP.FilterDocument>

*/

extern float32_t LPF_coefficients[10];
static const int LPF_numStages = 2;

typedef struct
{
	arm_biquad_casd_df1_inst_f32 instance;
	float32_t state[8];
	float32_t output;
} LPFType;

//==========  Not Used! ====================================
LPFType *LPF_create( void );  			// malloc기능은 사용하지 않음.
void LPF_destroy( LPFType *pObject );	// Not Used!...
void LPF_init( LPFType * pThis );
//==========================================================

void LPF_reset( LPFType * pThis );
#define LPF_writeInput( pThis, input )  \
	arm_biquad_cascade_df1_f32( &pThis->instance, &input, &pThis->output, 1 );

#define LPF_readOutput( pThis )  \
	pThis->output

int LPF_filterBlock( LPFType * pThis, float * pInput, float * pOutput, unsigned int count );
#define LPF_outputToFloat( output )  \
    (output)

#define LPF_inputFromFloat( input )  \
    (input)

#endif // LPF_H_

