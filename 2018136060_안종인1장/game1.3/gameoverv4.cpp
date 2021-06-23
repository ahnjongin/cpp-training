#include <stdio.h>
void printGuguDan()     //구구단 함수
{
	for (int dan = 2; dan <= 9; dan++) {
		printf("[구구단 %d 단]\n", dan);
		for (int i = 1; i <= 9; i++) {
			printf("%2d x %2d = %2d\n", dan, i, dan*i);
		}
	}
}
void main()
{
	// 구조화 프로그래밍
	printf("[구조화 프로그래밍]\n");

	printGuguDan();   //함수 실행
}