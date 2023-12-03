/*
 * KPAD_interface.h
 *
 *  Created on: Dec 1, 2023
 *      Author: Nada
 */

#ifndef KPAD_INTERFACE_H_
#define KPAD_INTERFACE_H_


#define NOTPRESSED     0xff

void KPD_Init(void);
u8   KPD_u8GetPressed( void );


/*#define NotPressed      0xff


void KPD_INIT     (void);
u8 KPD_GetPressed (void); */

#endif /* KPAD_INTERFACE_H_ */
