#include"russia.h"
int* playrussia(int nTurns, int nBullets, int nGuns)
{

	int start = rand() % nTurns;   //�����ڿ� �°�
	int *array = (int*)malloc(sizeof(int)*nBullets);   //�Ѿ˿� ���� ��ŭ �迭�� ����
	int a = 0;
	printf("\n���� ���Ƚ��ϴ�. %d������ �����մϴ�.\n", start + 1);
	while (true)
	{
		int pos = rand() % nGuns;
		printf("[%d��]\tźâ�� �������� ���Ƚ��ϴ�\n", start + 1);
		printf("\t���͸� ������ �ݹߵ˴ϴ�");
		getchar();
		
		if (pos < nBullets)       //�ѿ� �´� �ڵ�
			
		{
			array[a] = start+1;
			a++;
			nBullets--;
			printf("\t��~~~!\n");
		}
		else            //�ѿ� ���� �ʴ� �ڵ�
		{
			printf("\t�� ~ ��ҽ��ϴ�!\n");
		}
		if (nBullets == 0)break;     //�Ѿ� �� ���� break �Ѵ�
		
				start = (start + 1) % nTurns;
	}
	return array;    //�迭�� ��ȯ
}
 