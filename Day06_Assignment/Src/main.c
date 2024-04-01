
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "switch.h"
#include "lcd.h"
		// Blink the Led


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	LedInit(LED_ORANGE);
	LcdInit();
	SwitchInit(SWITCH);
	int cnt = 0;

	char str[16];
	while(1) {
		// wait until switch interrupt generated
		while(exti0_flag == 0)
			;

		sprintf(str, "COUNT=%d",cnt);
		LcdPuts(LCD_LINE2 ,str);
		cnt++;

		exti0_flag = 0;
	}
	return 0;
}
