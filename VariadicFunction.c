/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    VariadicFunction.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "stdarg.h"

//motivo de uso de stdarg:
//no se encontró manera de resolverlo sin dicha librería, y lo más cercano
//a poder realizarlo sin ella, se refuta en esta liga: https://stackoverflow.com/questions/24173499/accessing-variadic-function-arguments-without-stdarg/24173521
//donde básicamente se menciona que no resultaría portable realizarlo sin dicha librería

//ejemplo tomado de: https://en.wikipedia.org/wiki/Variadic_function#Example_in_C
uint32_t sum(uint8_t size_of_list, ...) {
	va_list ap;
	uint32_t suma = 0;
	va_start(ap, size_of_list);
	int index;
	for (index = 0; index < size_of_list; index++) {
		suma += va_arg(ap, int);
	}
	va_end(ap);
	return suma;
}

int main(void) {

	uint8_t value = sum(5,1,2,3,6,1);
	printf("%d",value);

	/* Enter an infinite loop, just incrementing a counter. */
	while (1) {

	}
	return 0;
}
