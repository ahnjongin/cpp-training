#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n=0, input=0, i=0;
	int num;
	char number[100];
	printf("���ϴ� �� �Է�:");
	while (true) {
		char ch = _getch();      //�� �Է�
		
			number[i] = ch;     //�迭�� �Էµ� ���� ���� 
			i++;                //�ݺ��ؼ� ����ĭ�� �����ϱ� ����
		if (ch == 13) {         //�ƽ�Ű�ڵ�� 13�� �����̱⶧���� ���͸� �������� break
			break;
		}
		printf("*");
	}
	num = atoi(number);         //char�� ����� ���� int������ �ٲٱ� ���� �ڵ�
	printf("\n");

	int k = i - 1;           //�����ޱ涧 ����ϱ� ���� ����
	int min = 0, max = pow(10, i-1);     //�õ�Ƚ���� �ڸ����� �°� �ø������� ����
		
	int score = max;    //������ �ޱ������ �����س���
	int j = 0;
	
	for (j = 0; j <max ; j++)
	{
		printf("[%2dȸ] %2d ~ %2d ������ �� ���� =>", j + 1, min, max);
		scanf_s("%d", &input);
		

		if (num == input)break;       //���ڸ� ������ �� break
		else if (num > input) {
			printf("�� ū �����Դϴ�\n");
			min = input;
		}
		else {
			printf("�� ���� �����Դϴ�\n");
			max = input;
		}
	}
	
	printf("%s!!! ������ %d\n", (num == input) ? "����" : "����", num);  //���߸� ������ �߰��ϱ����� ���׿�����
	
	if (k == 2) {                                 //���ڸ����϶� ����
		printf("�������� = %d\n",10*(10-j ));
	}
	else if (k == 3)                            //���ڸ����϶� ����
	{
		printf("�������� = %d\n", 100- (3*j));
	}
	else if (k == 4)                            //���ڸ����϶� ����
	{
		printf("�������� = %d\n", 100 - 2 * j);
	}
	else                                       //�ټ��ڸ��� �̻��϶� ����
	{
		printf("�������� = %d\n", 100 -  j);
	}
}