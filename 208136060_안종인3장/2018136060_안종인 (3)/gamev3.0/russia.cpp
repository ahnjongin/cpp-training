#include"russia.h"
int* playrussia(int nTurns, int nBullets, int nGuns)
{

	int start = rand() % nTurns;   //참가자에 맞게
	int *array = (int*)malloc(sizeof(int)*nBullets);   //총알에 갯수 만큼 배열을 만듬
	int a = 0;
	printf("\n총을 돌렸습니다. %d번부터 시작합니다.\n", start + 1);
	while (true)
	{
		int pos = rand() % nGuns;
		printf("[%d번]\t탄창을 무작위로 돌렸습니다\n", start + 1);
		printf("\t엔터를 누르면 격발됩니다");
		getchar();
		
		if (pos < nBullets)       //총에 맞는 코드
			
		{
			array[a] = start+1;
			a++;
			nBullets--;
			printf("\t빵~~~!\n");
		}
		else            //총에 맞지 않는 코드
		{
			printf("\t휴 ~ 살았습니다!\n");
		}
		if (nBullets == 0)break;     //총알 다 쓰면 break 한다
		
				start = (start + 1) % nTurns;
	}
	return array;    //배열을 반환
}
 