#include<stdio.h>
void main(void)
{
	for (int k = 1; k < 6; k++) {		  //����ĭ
		for (int i = 1; i <= k ; i++) {   //���ںκ�
			printf("%d ", i);
			}
		printf("\n");
		}

	printf("\n");

	for (int k = 1; k < 6; k++) {             //����ĭ 
		for (int i = 5; i >= k; i--)          //���ںκ�
		{
			printf("%d ", i);
		}
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)      //����ĭ �ѱ��
	{
		for (int j = 5; j > i; j--)   //����κ�
		{
				printf(" ");
		}
		for (int k = i; k > 0; k--)    //���ںκ�
		{
			printf("%d", k);
		}
		printf("\n");
	}

	
		
	
for (int i = 1; i <= 5; i++)      //����ĭ �ѱ��
{
	for (int j = 5; j > i; j--)   //����κ�
	{
		printf(" ");
	}
	for (int k = i; k > 0; k--)    //���ںκ�
	{
		printf("%d", k);
	}
	for (int k = 2; k <= i; k++)    //���ںκ�
	{
		printf("%d", k);
	}
	printf("\n");
}

	}
