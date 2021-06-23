#include<cstdio>
#include<cstdlib>
#include<ctime>

class gugugame {
	int NumGames = 0;
	int NumWins = 0;
	double Score = 0;
	bool playGuguOnce()
	{
		int a = rand() % 8 + 2;               //���� 2~9
		int b = rand() % 8 + 2;
		int result;

		NumGames++;
		printf("[����%2d]: %2d x %2d = ", NumGames, a, b);
		scanf_s("%d", &result);
		if (result == a * b)NumWins++;     //���� ���� ���
		return(result == a * b);
	}
	bool playplusOnce(int n)
	{
		int result;
		int a = rand() % ((int)pow(10.0, n) - (int)pow(10.0, n - 1)) + (int)pow(10.0, n - 1);  //�ڸ����� �°� ���� ���� 
		int b = rand() % ((int)pow(10.0, n) - (int)pow(10.0, n - 1)) + (int)pow(10.0, n - 1);



		NumGames++;
		printf("[����%2d]: %d + %d = ", NumGames, a, b);
		scanf_s("%d", &result);
		if (result == a + b)NumWins++;   //���� ���
		return(result == a + b);
	}
public:
	double tElapsed = 0;
	double playSpeedGugu(int nPlay)
	{
		clock_t t0 = clock();
		for (int i = 0; i < nPlay; i++)
		{
			if (playGuguOnce() == false)    //���� Ʋ���� ���
				printf("\tƲ�Ƚ��ϴ�.\n");
		}
		clock_t t1 = clock();
		tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;     //�ð� ���
		Score = (NumGames > NumWins) ? 0.0 : 100 * (5.0*NumGames - tElapsed) / (5.0*NumGames);   //���� ���
		return Score;
	}

	double playplus(int n, int nPlay)
	{
		clock_t t0 = clock();
		for (int i = 0; i < nPlay; i++)
		{
			if (playplusOnce(n) == false)    //Ʋ�� ���
				printf("\tƲ�Ƚ��ϴ�.\n");
		}
		clock_t t1 = clock();
		tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
		Score = (NumGames > NumWins) ? 0.0 : 100 * (3.0*NumGames - tElapsed) / (3.0*NumGames);
		return Score;
	}
};