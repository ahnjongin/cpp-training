#pragma once
#include "Monster.h"

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

class Zombie : public Monster
{
public:
	Zombie(string n = "��������", string i = " ��", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Zombie() { cout << "Zombie"; }
};
class Vampire : public Monster {
public:
	Vampire(string n = "�����̾�", string i = "��", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Vampire() { cout << "Vampire"; }

	void move(int **map, int maxx, int maxy) override
	{
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "ó��ͽ�", string i = "��", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~KGhost() { cout << "KGhost"; }

	void move(int **map, int maxx, int maxy)override
	{
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};



class Smombi : public Monster
{
public:
	Smombi(string n = "�밢�ͽ�", string i = "��", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Smombi() { cout << "Smombi"; }

	void move(int **map, int maxx, int maxy) override
	{
		int dir = rand() % 4;
		if (dir == 0) x--, y--;
		else if (dir == 1) x++, y++;
		else if (dir == 2) x++, y--;
		else x--, y++;
		clip(maxx, maxy);
		eat(map);
	}
};



class Jongin :public Vampire
{
	static int dir;
public:
	Jongin(string n = "¯������", string i = "��", int x = 0, int y = 0)
		:Vampire(n, i, x, y) {}
	~Jongin() { cout << "Jongin"; }
	void move(int **map, int maxx, int maxy)override
	{
		x = x + dx[dir];
		y = y + dy[dir];
		int bufx = x;
		int bufy = y;
		clip(maxx, maxy);
		if (bufx != x || bufy != y) dir = rand() % 4;
		eat(map);
	}
};

