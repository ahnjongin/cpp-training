#include<stdio.h>
#include<math.h>
void main(void)
{
	
	double pi;             
	double repi=0;
	int input;               //�Է��� ��
	scanf_s("%d", &input);   //�� �Է�
	for (int a = 0; a <= input; a++)      //�Է��� �� ���� �ݺ�
	{
		pi = (pow(-1.0,a)* (1.0 / (2 * a + 1)));   //pi ��ȭ��
		repi+=pi;                                 //repi�� pi���� ���ذ�
	}
	printf("%lf", repi*4);   //���

	
}