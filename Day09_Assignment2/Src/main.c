/*
 * main.c
 *
 *  Created on: Apr 4, 2024
 *      Author: hp
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "i2c.h"
#include "i2c_lcd.h"
#include "uart.h"
#include "spi.h"
#include "lis3dsh.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32];
	int ret;
	LIS_Data val;
	//LcdInit();
	SystemInit();
	LedInit(LED_BLUE);
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);

	UartInit(BAUD_9600);
	UartPuts("LIS3DSH Accel Demo!\r\n");

	//LcdPuts(LCD_LINE1, "ORIENTATION");
	LIS_Init();
	DelayMs(1000);
	while(1) {
		ret = LIS_DRdy();
		if(ret) {
			val = LIS_GetData();
			sprintf(str, "x %d y %d z %d\r\n", val.x, val.y, val.z);

			if(val.y<-4000)
				LedBlink(LED_BLUE, 100);

				if(val.y>4000)
					LedBlink(LED_ORANGE,100);

				if(val.x<-6000)
						LedBlink(LED_GREEN,100);

					if(val.x>6000)
						LedBlink(LED_RED,100);
			UartPuts(str);
			DelayMs(100);
		}
	}
	return 0;
}


