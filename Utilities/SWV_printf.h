/*
 * SWV_printf.h
 *
 *  Created on: Jan 22, 2025
 *      Author: JeonghWhanPro
 */

#ifndef INC_SWV_PRINTF_H_
#define INC_SWV_PRINTF_H_

#include "main.h"
#include <stdio.h>


int _write(int file, char *ptr, int len) {
int DataIdx;
	for (DataIdx = 0; DataIdx < len; DataIdx++){
		ITM_SendChar( *ptr++ );
	}
	return len;
}


#endif /* INC_SWV_PRINTF_H_ */
