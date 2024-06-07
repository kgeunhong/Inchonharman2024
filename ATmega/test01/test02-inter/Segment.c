/*
 * CFile1.c
 *
 * Created: 2024-03-28 오전 10:45:34
 *  Author: SYSTEM-00
 */ 

//#include "myHeader.h"
#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>


uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79, 0x71};
char arr[5]; //

void seg(int sel, uint8_t c)
{
	PORTC |= 0x0F;
	PORTC &= ~(1 <<(3-sel));
	PORTD = c;  // 숫자 데이터 출력
	//_delay_ms(100);
}

//int sm = 4;
void FND_4(char *inf)//segment image 배열
{
	for(int i=0; i<4; i++)
	{
		seg(i, *(inf+i));  // = seg(i, inf[i]);
		_delay_ms(5);
	}
}

char* Disp(unsigned long num) // 10진 정수
{
	int n1 = num % 10;         //A 
	int n2 = (num/10) % 10;    //B 
	int n3 = (num/100) % 10;   //C 
	int n4 = (num/1000) % 10;  //D 
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	//sm = (num > 4095) ? 4:(num > 256) ? 3:(num > 16) ? 2 : 1;
	FND_4(arr);
	return arr;
}

