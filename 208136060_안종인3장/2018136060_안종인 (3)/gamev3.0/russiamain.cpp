#include "russia.h"
void main()
{
	int nTurn, nBullets, nGuns;
	srand((unsigned)time(NULL));

	printf("���� �ο� (��:2) => ");
	scanf_s("%d", &nTurn);
	printf("�Ѿ� ����(6�̸�) => ");
	scanf_s("%d", &nBullets);
	printf("���� ����(��:6)=> ");
	scanf_s("%d", &nGuns);
	getchar();

	int *bang = playrussia(nTurn, nBullets, nGuns);   //�Լ� ȣ��
	for (int i = 0; i < nBullets; i++) {
		printf("\n----> %d�� �����ڰ� �ѿ� �¾ҽ��ϴ�.\n", bang[i]);    //�Լ����� ��ȯ�� �迭�� �ε����� ���
	}
}
