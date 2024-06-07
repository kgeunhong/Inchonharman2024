/*
 * test04-Timer.c
 *
 * Created: 2024-03-28 오전 10:57:14
 * Author : SYSTEM-00
 */ 
#include "myHeader.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define _delay_t 500

unsigned long cnt = 0, tcnt = 0;
 

int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0xFF;
	DDRC = 0x0F;
	SegPort(&PORTC, &PORTD);
	
//	TIMSK |= 0x01; // 0000 0001b - Timer 0 TCNT overflow interrupt
	TIMSK |= 0x04; // 0000 0100b - Timer 1 TCNT overflow interrupt (16bit)
//	TIMSK |= 0x40; // 0000 0001b - Timer 2 TCNT overflow interrupt
//  TCCR0 = 0x04;  // 분주비 (Pre-scaler) 64
	TCCR1B = 0x04; // 분주비 (Pre-scaler) 64
//	TCCR2 = 0x04;  // 분주비 (Pre-scaler) 64
	SREG |= 0x80; 
	sei(); // interrupt 시작
	while (1) 
    {
		if(cnt >= 0x10000)cnt = 0;
		SegDisp(cnt);
    }
}

ISR(TIMER1_OVF_vect) // 0,2 => 8bit  1,3 =>16bit
{
	tcnt++;
	//if(tcnt >= 100) // 8bit timer 사용시 
	{
		cnt++; tcnt = 0;
	}
}
