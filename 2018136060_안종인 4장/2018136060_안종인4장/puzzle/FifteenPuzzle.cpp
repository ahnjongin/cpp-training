#define _CRT_SECURE_NO_WARNINGS
#include"Ranking.h"
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#define DIM 3

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };    //방향키 아스키 코드
static int DirKey[4] = { Left, Right, Up, Down };
static int map[DIM][DIM];
static int x, y;
static int nMove;
static clock_t tStart;

static void init()      //초기화 시키는 함수
{
	for (int i = 0; i < DIM*DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
		map[DIM - 1][DIM - 1] = 0;
		x = DIM - 1; y= DIM - 1;

		srand(time(NULL));
		tStart = clock();
		nMove = 0;
}

static void display()        //퍼즐과 이동횟수 소요시간 등을 출력시키는 함수
{
	system("cls");
	printf("\tFifteen Puzzle\n\t");
	printf("--------------\n\t");
	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			if (map[r][c] > 0)
				printf("%3d", map[r][c]);
			else printf("   ");
		}
		printf("\n\t");
	}
	printf("------------\n\t");
	clock_t t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	printf("\n\t이동 횟수:%6d\n\t소요시간:%6.1f\n\n", nMove, d);
}

static bool move(int dir)       //화살표 키의 아스키코드를 받아 퍼즐조각을 움직이는 함수
{
	if (dir == Right && x > 0)
	{
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1)
	{
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1)
	{
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0)
	{
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;

	nMove++;
	return true;
}

static void shuffle(int nShuffle)       //난수를 이용하여 랜덤으로 섞는 함수
{
	for (int i = 0; i < nShuffle; i++)
	{
		int Key = DirKey[rand() % 4];
		if (move(Key) == false) { i--; continue; }
		display();
		Sleep(50);
	}
}

static bool isDone()            //퍼즐을 완성했는지 검사
{
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] != r * DIM + c + 1)
				return(r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}

static int getDirKey() { return _getche() == 224 ? _getche() : 0; }    //방향키를 받는 함수
int playFifteenPuzzle() {    //퍼즐 주 함수
	init();
	display();
	printRanking();
	printf("\n 퍼즐을 섞어주세요(엔터)...");
	_getche();
	shuffle(100);
	printf("\n게임이 시작됩니다...");
	_getche();

	nMove = 0;
	tStart = clock();
	while (!isDone())
	{
		move(getDirKey());
		display();
	}
	clock_t t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	return addRanking(nMove, d);
}
