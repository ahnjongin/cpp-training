#define _CRT_SECURE_NO_WARNINGS
#include"Ranking.h"
#define NUM_MVP 10
static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

static void initRanking()               //��� ��ŷ ���� �����ϰ� �ʱ�ȭ
{
	PlayInfo noname = { "C++",1000,1000.0 };
	for (int i = 0; i < nMVP; i++)
		MVP[i] = noname;
}
void loadRanking(const char*fname)        //���Ͽ��� ��ŷ ������ �о� ��ŷ �迭�� �ʱ�ȭ�ϴ� �Լ� 
{
	FILE*fp = fopen(fname, "r");
	if (fp == NULL)             //������ ������ init�Լ��� ȣ��
		initRanking();
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
}
void storeRanking(const char*fname)        //������ ��ŷ ������ �������Ͽ� �����ϴ� �Լ�
{
	FILE*fp = fopen(fname, "w");
	if (fp == NULL) {
		printf("�۵����� ����");
		return;
	}
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
	fclose(fp);
}
void printRanking()             //������ ��ŷ������ ȭ�鿡 ����ϴ� �Լ�
{
	for (int i = 0; i < nMVP; i++)
		printf("[%2d��] %4d %-16s %5.1f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
}
int addRanking(int nMove, double tElap)   //��ŷ�� ���� ����ϴ� �Լ�
{
	if (tElap < MVP[nMVP - 1].tElapsed)    
	{
		int pos = nMVP - 1;
		for (; pos > 0; pos--)
		{
			if (tElap >= MVP[pos - 1].tElapsed)break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		printf("%d���Դϴ� .�̸��� �Է��ϼ���:", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}