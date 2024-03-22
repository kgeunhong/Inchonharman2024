# Inchonharman2024
##인천 하만과정 2024년 3월 21일
```

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define _delay_t 500

void TogglepinA(int n, double dl)// n:번째 비트, dl: delay in mili-second
{
	char b = 1 << n;
	PORTA |= b; //PORTA의 n번째 비트를 HIGH로 출력
	_delay_ms(_delay_t );
	PORTA &= ~b; //PORTA의 n번째 비트를 LOW로 출력
	_delay_ms(_delay_t );
}

int main(void)
{
    // Replace with your application code 
	DDRA |= 0x07; // portA의 0,1,2번째 비트를 출력용으로 사용, 나머지는 입력
	DDRB &= ~0x01; // PortB의 0번째 비트를 입력용으로 사용, 나머지는 그대로 유지
	 
	int mode = 0; // mode1 : red,  mode2 : green,  mode3 : blue 
    while (1) //무한 루프가 기본
    {
		//if(PINB & 0x01 == 1) // 스위치 안눌렸을때 : true 
		if(!(PINB & 0x01 == 1)) // 스위치 눌렸을때 : true
		{
			mode++;
			if(mode >= 3) mode = 0;
		}
		switch(mode)
		{
			case 0:
			TogglepinA(0,_delay_t); //PORTA의 0번째 비트를 점멸
			break;
			case 1:
			TogglepinA(1,_delay_t); //PORTA의 1번째 비트를 점멸
			break;
			case 2:
			TogglepinA(2,_delay_t); //PORTA의 2번째 비트를 점멸
			break;
			default: mode = 0;
		}
    }
}

```
##인천 하만과정 2024년 3월 22일
```
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define _delay_t 500

void TogglepinA(int n, double dl)// n:번째 비트, dl: delay in mili-second
{
	char b = 1 << n;
	PORTA |= b; //PORTA의 n번째 비트를 HIGH로 출력
	_delay_ms(_delay_t );
	PORTA &= ~b; //PORTA의 n번째 비트를 LOW로 출력
	_delay_ms(_delay_t );
}

int main(void)
{
    // Replace with your application code 
	DDRA |= 0x07; // portA의 0,1,2번째 비트를 출력용으로 사용, 나머지는 입력
	DDRB &= ~0x01; // PortB의 0번째 비트를 입력용으로 사용, 나머지는 그대로 유지
	 
	int mode = 0; // mode1 : red,  mode2 : green,  mode3 : blue 
    while (1) //무한 루프가 기본
    {
		//if(PINB & 0x01 == 1) // 스위치 안눌렸을때 : true 
		if(!(PINB & 0x01 == 1)) // 스위치 눌렸을때 : true
		{
			mode++;
			if(mode >= 3) mode = 0;
		}
		switch(mode)
		{
			case 0:
			TogglepinA(0,_delay_t); //PORTA의 0번째 비트를 점멸
			break;
			case 1:
			TogglepinA(1,_delay_t); //PORTA의 1번째 비트를 점멸
			break;
			case 2:
			TogglepinA(2,_delay_t); //PORTA의 2번째 비트를 점멸
			break;
			default: mode = 0;
		}
    }
}
```
