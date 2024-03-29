//Scroll LCD display to left (repeatedly after 1 second). Stop scrolling after scrolling 16 times

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	LcdInit();
	LcdPuts(LCD_LINE1, "ANIKET PATIL");
	LcdPuts(LCD_LINE2, "9992");

	while(1)
	{
		LcdWrite(LCD_CMD,LCD_SCROLL);
		DelayMs(1000);
	}
	return 0;
}







