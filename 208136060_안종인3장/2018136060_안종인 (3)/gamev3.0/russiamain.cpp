#include "russia.h"
void main()
{
	int nTurn, nBullets, nGuns;
	srand((unsigned)time(NULL));

	printf("게임 인원 (예:2) => ");
	scanf_s("%d", &nTurn);
	printf("총알 개수(6미만) => ");
	scanf_s("%d", &nBullets);
	printf("연발 개수(예:6)=> ");
	scanf_s("%d", &nGuns);
	getchar();

	int *bang = playrussia(nTurn, nBullets, nGuns);   //함수 호출
	for (int i = 0; i < nBullets; i++) {
		printf("\n----> %d번 참가자가 총에 맞았습니다.\n", bang[i]);    //함수에서 반환한 배열의 인덱스를 출력
	}
}
