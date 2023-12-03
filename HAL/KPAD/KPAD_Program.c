/*
 *
 KPAD_Program.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Nada
 */

#include "DIO_interface.h"


#include "KPAD_interface.h"
#include "KPAD_Config.h"


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

u8 KPD_u8Buttons [4][4] = {{'7','8','9','/'},
	                   	   {'4','5','6','*'},
						   {'1','2','3','-'},
						   {'?','0','=','+'}};


void KPD_Init   (void){

	DIO_enumSetPinDirection    (KPD_PORT, KPD_R0, DIO_PIN_INPUT);
	DIO_enumSetPinDirection    (KPD_PORT, KPD_R1, DIO_PIN_INPUT);
	DIO_enumSetPinDirection    (KPD_PORT, KPD_R2, DIO_PIN_INPUT);
	DIO_enumSetPinDirection    (KPD_PORT, KPD_R3, DIO_PIN_INPUT);

	DIO_enumSetPinValue        (KPD_PORT, KPD_R0, DIO_PIN_HIGH);
	DIO_enumSetPinValue        (KPD_PORT, KPD_R1, DIO_PIN_HIGH);
	DIO_enumSetPinValue        (KPD_PORT, KPD_R2, DIO_PIN_HIGH);
	DIO_enumSetPinValue        (KPD_PORT, KPD_R3, DIO_PIN_HIGH);



	DIO_enumSetPinDirection    (KPD_PORT, KPD_C0, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection    (KPD_PORT, KPD_C1, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection    (KPD_PORT, KPD_C2, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection    (KPD_PORT, KPD_C3, DIO_PIN_OUTPUT);

	DIO_enumSetPinValue        (KPD_PORT, KPD_C0, DIO_PIN_HIGH);
	DIO_enumSetPinValue        (KPD_PORT, KPD_C1, DIO_PIN_HIGH);
	DIO_enumSetPinValue        (KPD_PORT, KPD_C2, DIO_PIN_HIGH);
	DIO_enumSetPinValue        (KPD_PORT, KPD_C3, DIO_PIN_HIGH);


}


u8 KPD_u8GetPressed (void){

u8 LOC_u8ReturnData = NOTPRESSED;
u8 LOC_u8GetPressed;

u8 LOC_u8Row;
u8 LOC_u8Col;

   for (LOC_u8Col= 0 + KPD_COL_INIT; LOC_u8Col < KPD_COL_END +1; LOC_u8Col++)
   {

	   DIO_enumSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_LOW);

	   for (LOC_u8Row = 0 + KPD_ROW_INIT; LOC_u8Row < KPD_ROW_END + 1 ; LOC_u8Row ++)
	   {

		   DIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);

		   if (LOC_u8GetPressed == 0)
		   {
			   _delay_ms(50);

			   DIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);

			   if(LOC_u8GetPressed == 0)
			   {

				   LOC_u8ReturnData = KPD_u8Buttons [LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT ];
			   }

			   DIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);

			   while (DIO_PIN_LOW == LOC_u8GetPressed )
			   {
				   DIO_enumGetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);

			   }

			   break;

		   }




	   }

	   DIO_enumSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_HIGH);

   }


return LOC_u8ReturnData;
}
