/*
 * test02-inter.c
 *
 * Created: 2024-03-27 오후 12:25:39
 * Author : SYSTEM-00
 */ 
#define F_CPU 16000000L

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define _delay_t 500
#define OPMODEMAX 3
#define STATE_MAX 3

extern char* Disp(unsigned long num);

volatile int opmode =0, timer = 0, reset = 0; //최적화 금지

int main(void)
{
	/* Replace with your application code */
	// 7-Segment 사용 : 4Module ~ C type
	// Pin assign : PAx - Segment img, PBx -module sel
	// Interrupt 사용 : INT4 ~ INT6 (Ext Int)
	// Pin assign : PE4 ~ PE6
	
	DDRD = 0xFF;
	DDRC = 0x0F;
	DDRE = 0x00;
	DDRA = 0x01;
	
	// 인터럽트 설정
	EIMSK = 0x70; // 0111 0000b
	EICRB = 0x2a; // 0010 1010b
	
	SREG |= 0x80; // status Register -인터럽트 허용
	sei(); // set interrupt - 인터럽트 시작
	
	int t = 0;
	int tled = 100000;
	
	while (1)
	{
		switch(opmode)
		{
			case 0: //reset & wait
			t = 0; break;
			case 1: // counter start
			t++; break;
			case 2: // count stop
			break;
			default: break;
		}
		Disp(t);
	
		if (t > tled)
		{
			PORTA |= 0x01;	//   LED 켜기
			_delay_ms(20);
			
			PORTA &= ~0X01;	//  LED 끄기
			t++;
		}
	}
	if(reset) //리셋
	{
		opmode = 0;
		timer = 0;
		reset = 0;
		tled = 10000;
		t = 0;
	}
}

ISR(INT4_vect) // INT4 인터럽트 처리루틴 : sw1
{
	opmode++;
	if(opmode >= OPMODEMAX)opmode = 0;
}

ISR(INT5_vect) // INT5 인터럽트 처리루틴 : sw2
{
	timer++;
}
ISR(INT6_vect) // INT6 인터럽트 처리루틴 : sw3
{
	reset++;
}