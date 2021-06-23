#include<stdio.h>
void main(void)
{
	for (int k = 1; k < 6; k++) {		  //다음칸
		for (int i = 1; i <= k ; i++) {   //숫자부분
			printf("%d ", i);
			}
		printf("\n");
		}

	printf("\n");

	for (int k = 1; k < 6; k++) {             //다음칸 
		for (int i = 5; i >= k; i--)          //숫자부분
		{
			printf("%d ", i);
		}
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)      //다음칸 넘기기
	{
		for (int j = 5; j > i; j--)   //공백부분
		{
				printf(" ");
		}
		for (int k = i; k > 0; k--)    //숫자부분
		{
			printf("%d", k);
		}
		printf("\n");
	}

	
		
	
for (int i = 1; i <= 5; i++)      //다음칸 넘기기
{
	for (int j = 5; j > i; j--)   //공백부분
	{
		printf(" ");
	}
	for (int k = i; k > 0; k--)    //숫자부분
	{
		printf("%d", k);
	}
	for (int k = 2; k <= i; k++)    //숫자부분
	{
		printf("%d", k);
	}
	printf("\n");
}

	}
