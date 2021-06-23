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

	game.add(new Zombie("������ ����", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Smombi("�밢�ͽ�", "��", rand() % w, rand() % h));
	game.add(new Jianshi("���Ծ��", "��", rand() % w, rand() % h, true));
	game.add(new Jianshi("���Ծ��", "��", rand() % w, rand() % h, false));
	game.add(new Siangshi("���۰���", "��", rand() % w, rand() % h, true));
	game.add(new Siangshi("���۰���", "��", rand() % w, rand() % h, false));
	game.add(new Jongin("¯������", "��", rand() % w, rand() % h));
	game.play(500, 10);
	printf("--------------���� ����----------------\n");

	return 0;
}