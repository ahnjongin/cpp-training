#include<stdio.h>
#include<math.h>
void main(void)
{
	
	double pi;             
	double repi=0;
	int input;               //입력할 수
	scanf_s("%d", &input);   //수 입력
	for (int a = 0; a <= input; a++)      //입력한 수 까지 반복
	{
		pi = (pow(-1.0,a)* (1.0 / (2 * a + 1)));   //pi 점화식
		repi+=pi;                                 //repi에 pi값을 더해감
	}
	printf("%lf", repi*4);   //출력

	
}