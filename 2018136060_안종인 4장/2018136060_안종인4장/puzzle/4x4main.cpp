#define _CRT_SECURE_NO_WARNINGS
#include"Ranking.h"
extern int playFifteenPuzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = playFifteenPuzzle();
	printRanking();
	storeRanking("ranking.txt");
}