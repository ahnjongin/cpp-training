#include <stdio.h>
void main()
{
	// �������� ���α׷���
	
	int dan = 2;  //2�ܺ��� ����
	
	printf("[������ ���α׷���]\n");
loop2:
	int i = 1;   //�ܿ� ������ ����    //�ٽ� 1�� �ʱ�ȭ�� �ؾ� ��
	if (dan <= 9) {
		printf("[������ %d ��]\n", dan);
		loop1:
		if (i <= 9) {
			printf("%2d x %2d = %2d\n", dan, i, dan*i);   //*9���� �ݺ�
			i++;
			goto loop1;  //*1���� *9���� �ϱ� ���� 
		}
		dan = dan + 1;   //���� ������ �Ѿ�� ����
		goto loop2;      //���� �ݺ� �ϱ� ����
			
	}
	
	return;
}
