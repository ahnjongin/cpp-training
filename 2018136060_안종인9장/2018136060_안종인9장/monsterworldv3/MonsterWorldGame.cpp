#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int Siangshi::count = 0;
int Jongin::dir = rand() % 4;
int main(void)
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);

	game.add(new Zombie("허접한 좀비", "§", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Smombi("대각귀신", "☆", rand() % w, rand() % h));
	game.add(new Jianshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.add(new Jianshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.add(new Siangshi("슈퍼강시", "〓", rand() % w, rand() % h, true));
	game.add(new Siangshi("슈퍼강시", "〓", rand() % w, rand() % h, false));
	game.add(new Jongin("짱안종인", "㈜", rand() % w, rand() % h));
	game.play(500, 10);
	printf("--------------게임 종료----------------\n");

	return 0;
}