/*
 * main.c
 *
 * Created: 2012-04-09 4:35:26 PM
 *  Author: Justin
 * 1.0.0.0		-			CW		First Release
 */ 

#include <avr32/io.h>
#include <stdio.h>
#include <string.h>
#include "font.h"
#include "color.h"
#include "h2framework.h"
#include "h2core.h"
#include "util.h"
#include "ledring.h"
//
// START:
//
void (*entry)(void);
int main(void)
{
	int iRet = 0, i;
	int iRespLen = 0;
	unsigned char ucKeyValue;
	
	//
	// Init all hardware
	//
	h2core_init(0);

	//Clear Screen
	lcd_draw_fillrect(0, 0, LCD_WIDTH, LCD_HEIGHT, BLUE);
	lcd_draw_string("Hello World", font_Fixesys16, 100, 120, GREEN, BLACK);
	 
	beepstd();//Beep
	
	int count = 0;
	
	while(count<20)
	{
		//Mandatory task for USB driver
		h2core_task();
		
		beepstd();
		
		sleep(500);
		ledring_set(LEDRING_LED1|LEDRING_LED5, 0xFF, 0x00, 0x00);
		led_on(LED_1);
		led_off(LED_2|LED_3|LED_4);
		sleep(500);
		
		ledring_set(LEDRING_LED2|LEDRING_LED6, 0x00, 0xFF, 0x00);
		led_on(LED_2);
		sleep(500);
		
		ledring_set(LEDRING_LED3|LEDRING_LED7, 0x00, 0x00, 0xFF);
		led_on(LED_3);
		sleep(500);
		
		ledring_set(LEDRING_LED4|LEDRING_LED8, 0xFF, 0xFF, 0xFF);
		led_on(LED_4);
		sleep(500);
		
		ledring_off(LEDRING_LEDALL);
		led_off(LED_1|LED_2|LED_3|LED_4);
		sleep(500);
		ledring_on(LEDRING_LEDALL,0x1234);
		led_on(LED_1|LED_2|LED_3|LED_4);
		sleep(500);
		ledring_off(LEDRING_LEDALL);
		led_off(LED_1|LED_2|LED_3|LED_4);
		sleep(500);
		ledring_on(LEDRING_LEDALL,0x1234);
		led_on(LED_1|LED_2|LED_3|LED_4);
		beepstd();
		sleep(100);
		ledring_off(LEDRING_LEDALL);
		led_off(LED_1|LED_2|LED_3|LED_4);
		count++;
	}

}