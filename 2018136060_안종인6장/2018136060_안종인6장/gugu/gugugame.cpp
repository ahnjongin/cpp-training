#include "gugugame.h"

int main()
{
	srand((unsigned)time(NULL));
	int nPlay = 10;                      //����Ƚ��
	int n = 0;                           //������ �����ϱ� ���� ����
	printf("������ �����ϼ���\n");
	printf("1: ���ǵ� ������ ����\n");
	printf("3~9�ڸ��� ���� ������ �Է��ϼ���\n");
	scanf_s("%d", &n);
	if (n == 1) {
		printf("[���ǵ� ������ ����]\n\n");
		printf("����� ������ �Ƿ��� �׽�Ʈ�ϼ���!\n");
		printf("%d�� �׽�Ʈ �ϰڽ��ϴ�\n", nPlay);
		printf("ũ�� ��ȣ���� �Ͻð�...\n �غ�Ǹ� ���͸� ��������..");
		getchar();
		system("cls");                               //ȭ�� �ʱ�ȭ
		gugugame game;
		double score = game.playSpeedGugu(nPlay);         //�Լ� �ҷ�����
		printf("\n����=%4.1f��(�� %4.1f��)\n", score, game.tElapsed);
	}
	else
	{
		printf("[%d�ڸ��� ���� ����]\n\n", n);
		printf("����� ���� �Ƿ��� �׽�Ʈ�ϼ���!\n");
		printf("%d�� �׽�Ʈ �ϰڽ��ϴ�\n", nPlay);
		printf("ũ�� ��ȣ���� �Ͻð�...\n �غ�Ǹ� ���͸� ��������..");
		getchar();
		system("cls");
		gugugame game;
		double score = game.playplus(n, nPlay);              //���� �Լ� �ҷ�����
		printf("\n����=%4.1f��(�� %4.1f��)\n", score, game.tElapsed);


	}


}