/*

 * main.c
 *
 *  Created on: Dec 3, 2023
 *      Author: Nada
 */


#include "CLCD_Config.h"
#include "CLCD_interface.h"
#include "CLCD_Private.h"

#include "DIO_interface.h"

#include "LED_interface.h"

#include "KPAD_interface.h"
#include "KPAD_Config.h"

#include "BUZZ_interface.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <util/delay.h>

LED_Adjusting LEDs [8] = {{LED_PORTD, LED_PIN0, Active_High },
		                  {LED_PORTD, LED_PIN1, Active_High },
						  {LED_PORTD, LED_PIN2, Active_High },
						  {LED_PORTD, LED_PIN3, Active_High },
						  {LED_PORTD, LED_PIN4, Active_High },
						  {LED_PORTD, LED_PIN5, Active_High },
						  {LED_PORTD, LED_PIN6, Active_High },
						  {LED_PORTD, LED_PIN7, Active_High }};

BUZZ_Adjusting Buzz1 = {BUZZ_PORTB, BUZZ_PIN4, Active_High};

int i;
u8 KPD_Status = 0;

static void Leds_off(){


	for(i = 0; i < 8; i++){

		LED_VoidOf(LEDs[i]);

	}

}

static void App_init (){

	CLCD_Init ();
	KPD_Init  ();
	BUZZ_VoidInit(Buzz1);

	for(i=0; i<8; i++){

		LED_VoidInit(LEDs[i]);
	}
}

int main (){

	App_init();

	while (1){
		KPD_Status = KPD_u8GetPressed();
		if (KPD_Status != 0xff){
			CLCD_SendData  (KPD_Status);
		switch (KPD_Status){
		case '1':
			Leds_off();
			LED_VoidOn(LEDs[0]);
			break;
		case '2':
			Leds_off();
			LED_VoidOn(LEDs[1]);
			break;
		case '3':
			Leds_off();
			LED_VoidOn(LEDs[2]);
			break;
		case '4':
			Leds_off();
			LED_VoidOn(LEDs[3]);
			break;
		case '5':
			Leds_off();
			LED_VoidOn(LEDs[4]);
			break;
		case '6':
			Leds_off();
			LED_VoidOn(LEDs[5]);
			break;
		case '7':
			Leds_off();
			LED_VoidOn(LEDs[6]);
			break;
		case '8':
			Leds_off();
			LED_VoidOn(LEDs[7]);
			break;
		case '?':
			Leds_off();
			CLCD_Undo();
			break;
		case '=':
			Leds_off();
			CLCD_ClearScreen ();
			CLCD_SetPosition  (1,1);
			CLCD_SendString ("Ringing...");
			BUZZ_VoidOn(Buzz1);
			_delay_ms(1000);
			break;
		case '+':
			Leds_off();
			CLCD_ClearScreen ();
			CLCD_SetPosition  (1,1);
			CLCD_SendString ("Call Ended");
			BUZZ_VoidOf(Buzz1);
			_delay_ms(1000);
			break;
		default:
			Leds_off();
			break;
		}

		}
	}
	return 0;

	}

