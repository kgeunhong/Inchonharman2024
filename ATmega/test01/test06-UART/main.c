/*
 * test06-UART.c
 *
 * Created: 2024-06-07 오전 10:36:21
 * Author : user
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


void initUART0()
{ //9600 N81
	UBRR0H = 0;
	UBRR0L = 207; // Baud rate : 9600
	
	UCSR0A |= (1 << U2X)0; // 0000 0010b 2배속 설정
	
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0); // Rx/Tx Enable
	UCSR0C |= 0x06; //Data bit : 8 x11x   0000 0110b N81
	                 //Stop bit : 1 0xxx 
}


void uPutc (char c)
{
	//while(1)
	//{
	//	if( UCSR0A & (1<<UDRE0) == 1) break ; // Wait until data empty bit test 1
	//}
	while(!(UCSR0A & (1<<UDRE0))); // Wait until data empty bit test 1
	UDR0 = c; // Send 
}
void uPuts(char *str)
{
	while(*str) uPutc(*str++);
	
	//while(1)
	//{
	//	if(*str == 0) break; 
	//	uPutc(*str);
	//	str++;
	//}
}

unsigned char buf[1024];
void bprint()

{
	uPuts(buf);
}

int main(void)
{
    /* Replace with your application code */
    initUART0();
	char a = '0';
	int i = 0;
	uPuts("안녕하세요...?\r\n");
	while (1) 
    {
		//uPutc(a++);
		sprintf(buf, "ATmega 터미널 출력 테스트...#%d", i++); bprint();
		_delay_ms(1000);
		//if(a >'9')a = '0';
		
    }
}

