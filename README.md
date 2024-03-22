# Inchonharman2024
##인천 하만과정 2024년 3월

```
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
```
