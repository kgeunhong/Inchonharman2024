/*
 * test02-7seg.c
 *
 * Created: 2024-03-21 오후 3:34:31
 * Author : SYSTEM-00
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define _delay_t 500

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79, 0x71};
char arr[5]; //세그먼트 이미지 정보를 담을 안전 영역

void TogglepinA(int n, double dl)// n:번째 비트, dl: delay in mili-second
{
	char b = 1 << n;
	PORTA |= b; //PORTA의 n번째 비트를 HIGH로 출력
	_delay_ms(_delay_t );
	PORTA &= ~b; //PORTA의 n번째 비트를 LOW로 출력
	_delay_ms(_delay_t );
}


void LED(char*p, int n)// p:PORTx의 포인터, n:번째 비트
{
	char b = 1 << n;
	*p |= b; //PORTA의 n번째 비트를 HIGH로 출력
	_delay_ms(_delay_t );
	*p &= ~b; //PORTA의 n번째 비트를 LOW로 출력
	_delay_ms(_delay_t );
}

void seg(int sel, uint8_t c)
{
	PORTC |= 0x0F;
	PORTC &= ~(1 <<(3-sel));
	PORTD = c;  // 숫자 데이터 출력
	_delay_ms(100);
}

void FND_4(char *inf)//segment image 배열
{
	for(int i=0; i<4; i++)
	{
		seg(i, *(inf+i));  // = seg(i, inf[i]);
	}
}

char* Trans(int num) // 10진 정수 ==> 16진수 문자열 : 65535 ==> 0xFFFF,  56506 ==> 0xDCBA

{
	int n1 = num % 16;       //A (10) : 문자가 아닌 숫자
	int n2 = (num/16) % 16;  //B (11)
	int n3 = (num/256) % 16; //C (12)
	int n4 = (num/4096);     //D (13)
	arr[0] = digit[n1];
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	
	//FND_4(arr);
	return arr;
}

int main(void)
{
	int i, j = 0;
	DDRB = 0x07;
	DDRD = 0xFF;
	DDRC = 0x0F;
	
	while(1)
	{
		FND_4(Trans(j++));
		_delay_ms(10);
		//LED(&PORTD, 1); //PORTD의 1번째 비트 점멸
		//for(i = 0; i < 4; i++)
		//{
		//PORTC |=0x0F;
		//PORTC &= ~(1 << (3-i));
		//for(j = 0; j < 16; j++)
		//{
		//PORTD = digit[j];
		//_delay_ms(500);
		//}
		//	}
	}
	return 0;
}

/*while(1)
{
	if(!(PINB & 0x01 == 1))
	{
		mode++;
		if(mode >= 3) mode = 0;
		j = 0;
	}
	switch(mode)
	{
		case 0:
		PORTC & = ~0x0F;
		PORTD = 0x40;
		break;
		case 1:
		FND_4(Trans(j++));
		_delay_ms(10);
		break;
		case 2:
		FND_4(Trans(j));
		break;
		default: mode = 0;
		j = 0;
	}
}
*/

