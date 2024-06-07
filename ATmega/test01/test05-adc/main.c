/*
 * test05-adc.c
 *
 * Created: 2024-05-31 오후 4:34:03
 * Author : user
 */ 

#define F_CPU 16000000L
#include "myHeader.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define _delay_t 500

int cnt = 0, tcnt = 0;

void initADC(int ch)
{
	ADMUX | = 1 << REFS0; //기준전압 VCC 0100 0000
	
	ADCSRA | = 0x07; // pre-scaler 분주비 설정
	ADCSRA | = 1 << ADEN; //ADC 활성화 
	ADCSRA | = 1 << ADFR; // free - running mode 설정
	ADMUX  | = (ADMUX & 0xE0) | ch;
	ADCSRA | = 1 << ADSC; // ADC 시작 
}

int main(void)
{
	DDRD = 0xFF;
	DDRC = 0x0F;
	SegPort(&PORTC, &PORTD);
	SegType(1);
	
	initADC(1); // 1: ch number
    while (1) 
    {
		while(!(ADCSRA & (1<< ADIF)));
	    int cnt = ADC;
	    SegDisp(cnt);
    }
}

