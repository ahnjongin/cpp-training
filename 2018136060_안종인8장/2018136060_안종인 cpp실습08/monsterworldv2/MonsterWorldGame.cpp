#include "MonsterWorld.h"
#include <time.h>


int main(void)
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 12;

	MonsterWorld game(w, h);
	
	game.add(new Monster("����", "��", rand() % w, rand() % h));
	game.add(new Monster("������", "��", rand() % w, rand() % h));
	game.add(new Monster("���״�", "��", rand() % w, rand() % h));
	game.add(new Monster("������", "��", rand() % w, rand() % h));
	game.play(500, 10);
	printf("--------------���� ����----------------\n");

	return 0;
}