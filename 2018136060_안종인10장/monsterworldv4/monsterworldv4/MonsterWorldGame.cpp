#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int Jongin::dir = rand() % 4;
int main(void)
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);

	game.add(new Zombie("������ ����", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Smombi("�밢�ͽ�", "��", rand() % w, rand() % h));
	game.add(new Jongin("¯������", "��", rand() % w, rand() % h));
	game.add(new Tuman("�̷�����", "��", rand() % w, rand() % h));
	game.add(new Tuman("�̷��η�", "��", rand() % w, rand() % h));
	

	game.play(500, 10);
	printf("--------------���� ����----------------\n");

	return 0;
}