#include "MonsterWorld.h"
#include <time.h>


int main(void)
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 12;

	MonsterWorld game(w, h);
	
	game.add(new Monster("몬스터", "※", rand() % w, rand() % h));
	game.add(new Monster("도깨비", "§", rand() % w, rand() % h));
	game.add(new Monster("별그대", "★", rand() % w, rand() % h));
	game.add(new Monster("도깨비", "♥", rand() % w, rand() % h));
	game.play(500, 10);
	printf("--------------게임 종료----------------\n");

	return 0;
}