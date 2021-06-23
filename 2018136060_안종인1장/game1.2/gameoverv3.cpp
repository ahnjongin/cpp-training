#include <stdio.h>
void main()
{
	// 절차적인 프로그래밍
	
	int dan = 2;  //2단부터 시작
	
	printf("[절차적 프로그래밍]\n");
loop2:
	int i = 1;   //단에 곱해질 변수    //다시 1로 초기화를 해야 함
	if (dan <= 9) {
		printf("[구구단 %d 단]\n", dan);
		loop1:
		if (i <= 9) {
			printf("%2d x %2d = %2d\n", dan, i, dan*i);   //*9까지 반복
			i++;
			goto loop1;  //*1부터 *9까지 하기 위한 
		}
		dan = dan + 1;   //다음 단으로 넘어가기 위해
		goto loop2;      //단을 반복 하기 위한
			
	}
	
	return;
}
