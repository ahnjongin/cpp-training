#include "gugugame.h"

int main()
{
	srand((unsigned)time(NULL));
	int nPlay = 10;                      //게임횟수
	int n = 0;                           //게임을 선택하기 위한 변수
	printf("게임을 선택하세요\n");
	printf("1: 스피드 구구단 게임\n");
	printf("3~9자릿수 덧셈 게임을 입력하세요\n");
	scanf_s("%d", &n);
	if (n == 1) {
		printf("[스피드 구구단 게임]\n\n");
		printf("당신의 구구단 실력을 테스트하세요!\n");
		printf("%d번 테스트 하겠습니다\n", nPlay);
		printf("크게 심호흡을 하시고...\n 준비되면 엔터를 누르세요..");
		getchar();
		system("cls");                               //화면 초기화
		gugugame game;
		double score = game.playSpeedGugu(nPlay);         //함수 불러오기
		printf("\n점수=%4.1f점(총 %4.1f초)\n", score, game.tElapsed);
	}
	else
	{
		printf("[%d자릿수 덧셈 게임]\n\n", n);
		printf("당신의 덧셈 실력을 테스트하세요!\n");
		printf("%d번 테스트 하겠습니다\n", nPlay);
		printf("크게 심호흡을 하시고...\n 준비되면 엔터를 누르세요..");
		getchar();
		system("cls");
		gugugame game;
		double score = game.playplus(n, nPlay);              //덧셈 함수 불러오기
		printf("\n점수=%4.1f점(총 %4.1f초)\n", score, game.tElapsed);


	}


}