#define _CRT_SECURE_NO_WARNINGS
#include"Ranking.h"
#define NUM_MVP 10
static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

static void initRanking()               //모든 랭킹 값을 동일하게 초기화
{
	PlayInfo noname = { "C++",1000,1000.0 };
	for (int i = 0; i < nMVP; i++)
		MVP[i] = noname;
}
void loadRanking(const char*fname)        //파일에서 랭킹 정보를 읽어 랭킹 배열을 초기화하는 함수 
{
	FILE*fp = fopen(fname, "r");
	if (fp == NULL)             //파일이 없으면 init함수를 호출
		initRanking();
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
}
void storeRanking(const char*fname)        //현재의 랭킹 정보를 이진파일에 저장하는 함수
{
	FILE*fp = fopen(fname, "w");
	if (fp == NULL) {
		printf("작동되지 않음");
		return;
	}
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
	fclose(fp);
}
void printRanking()             //현재의 랭킹정보를 화면에 출력하는 함수
{
	for (int i = 0; i < nMVP; i++)
		printf("[%2d위] %4d %-16s %5.1f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
}
int addRanking(int nMove, double tElap)   //랭킹에 새로 등록하는 함수
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
		printf("%d위입니다 .이름을 입력하세요:", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}