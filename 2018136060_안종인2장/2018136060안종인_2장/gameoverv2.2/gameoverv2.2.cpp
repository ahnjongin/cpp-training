#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n=0, input=0, i=0;
	int num;
	char number[100];
	printf("원하는 수 입력:");
	while (true) {
		char ch = _getch();      //수 입력
		
			number[i] = ch;     //배열에 입력된 수를 저장 
			i++;                //반복해서 다음칸에 저장하기 위해
		if (ch == 13) {         //아스키코드로 13은 엔터이기때문에 엔터를 눌렀을때 break
			break;
		}
		printf("*");
	}
	num = atoi(number);         //char로 저장된 것을 int형으로 바꾸기 위한 코드
	printf("\n");

	int k = i - 1;           //점수메길때 사용하기 위한 변수
	int min = 0, max = pow(10, i-1);     //시도횟수를 자릿수에 맞게 늘리기위해 설정
		
	int score = max;    //점수를 메기기위해 저장해놓음
	int j = 0;
	
	for (j = 0; j <max ; j++)
	{
		printf("[%2d회] %2d ~ %2d 사이의 값 예측 =>", j + 1, min, max);
		scanf_s("%d", &input);
		

		if (num == input)break;       //숫자를 맞췄을 때 break
		else if (num > input) {
			printf("더 큰 숫자입니다\n");
			min = input;
		}
		else {
			printf("더 작은 숫자입니다\n");
			max = input;
		}
	}
	
	printf("%s!!! 정답은 %d\n", (num == input) ? "성공" : "실패", num);  //맞추면 성공이 뜨게하기위한 삼항연산자
	
	if (k == 2) {                                 //두자리수일때 점수
		printf("최종점수 = %d\n",10*(10-j ));
	}
	else if (k == 3)                            //세자리수일때 점수
	{
		printf("최종점수 = %d\n", 100- (3*j));
	}
	else if (k == 4)                            //네자리수일때 점수
	{
		printf("최종점수 = %d\n", 100 - 2 * j);
	}
	else                                       //다섯자리수 이상일때 점수
	{
		printf("최종점수 = %d\n", 100 -  j);
	}
}