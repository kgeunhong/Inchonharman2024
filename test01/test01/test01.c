#include <stdio.h>

int test01();
void test02(int a);

//깃허브 테스트

int main()
{
	//test01;
	test02(1);
}

int test01()
{
	char* star[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

	printf("숫자 키를 입력하세요.해당하는 영단어를 알려드리겠습니다.\n");
	printf("프로그램을 끝내려면'Q'를 입력하시오.\n\n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch(); // no echo : 키값을 출력하지 않음
		//int n = c - 0x30; //ASKII --> num
		printf("%c : %s\n", c, star[c - 0x30]);


		/*if (c == '1') printf("%c : one\n, c");
		else if (c == '2') printf("%c : two\n, c");
		else if (c == '3') printf("%c : three\n, c");
		else if (c == '4') printf("%c : four\n, c");
		else if (c == '5') printf("%c : five\n, c");
		else if (c == '6') printf("%c : six\n, c");
		else if (c == '7') printf("%c : seven\n, c");
		else if (c | 0x20 == 'q') break;
	} 

	switch (c)
	{
	case '1': printf("%c :One \n") break;
	case '2': printf("%c :two \n") break;
	case '3': printf("%c :three \n") break;*/
	}

}
void test02(int a) //문자열과 문자배열
{
	char ca[] = "Hello"; // ca[0] : 'H' ... ca[4]:'0' ca[5]:\0
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c (%02x)\n", i, ca[i], ca[i]);
	}
	ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c (%02x)\n", i, ca[i], ca[i]);
	}

}
