#include <stdio.h>
void printGuguDan()     //������ �Լ�
{
	for (int dan = 2; dan <= 9; dan++) {
		printf("[������ %d ��]\n", dan);
		for (int i = 1; i <= 9; i++) {
			printf("%2d x %2d = %2d\n", dan, i, dan*i);
		}
	}
}
void main()
{
	// ����ȭ ���α׷���
	printf("[����ȭ ���α׷���]\n");

	printGuguDan();   //�Լ� ����
}