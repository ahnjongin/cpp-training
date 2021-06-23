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
		if (!isSleep()) {
			int dir = rand() % 4;
			if (dir == 0) p[0]--;
			else if (dir == 1) p[0]++;
			else if (dir == 2) p[1]--;
			else p[1]++;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "ó��ͽ�", string i = "��", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~KGhost() { cout << "KGhost"; }

	void move(int **map, int maxx, int maxy)override
	{
		if (!isSleep())
		{
			p = Point(rand() % maxx, rand() % maxy);
			clip(maxx, maxy);
			eat(map);
		}
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
		if (dir == 0) p[0]--, p[1]--;
		else if (dir == 1) p[0]++, p[1]++;
		else if (dir == 2) p[0]++, p[1]--;
		else p[0]--, p[1]++;
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
		p[0] = p[0] + dx[dir];
		p[1] = p[1] + dy[dir];
		int bufx = p[0];
		int bufy = p[1];
		clip(maxx, maxy);
		if (bufx != p[0] || bufy != p[1]) dir = rand() % 4;
		eat(map);
	}
};

