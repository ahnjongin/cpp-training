#pragma once
#include "Monster.h"
#include <conio.h>

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
class Human : public Monster {
public:
	Human(string n = "미래인류", string i = "우", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Human() { cout << "Human"; }

	int getDirkey() { return _getche() == 224 ? _getche() : 0; }

	void move(int** map, int maxx, int maxy) override {
		if (_kbhit()) {
			char ch = getDirkey();
			if (ch == Left) p[0]--;
			else if (ch == Right) p[0]++;
			else if (ch == Up) p[1]--;
			else if (ch == Down) p[1]++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Tuman : public Human {
public:
	Tuman(string n = "미래투맨", string i = "좌", int x = 0, int y = 0)
		:Human(n, i, x, y) {}
	~Tuman() { cout << "Tuman"; }

	int getDirkey() { return _getche() == 224 ? _getche() : 0; }

	void move(int** map, int maxx, int maxy, int ch) {
		if (ch == 224) {
			ch = _getch();
			if (ch == 'w' || ch == Up) p[1]--;
			else if (ch == 'a' || ch == Left) p[0]--;
			else if (ch == 'd' || ch == Right) p[0]++;
			else if (ch == 's' || ch == Down) p[1]++;
		}
		else {
			if (ch == 'w' || ch == Up) p[1]--;
			else if (ch == 'a' || ch == Left) p[0]--;
			else if (ch == 'd' || ch == Right) p[0]++;
			else if (ch == 's' || ch == Down) p[1]++;
		}

		clip(maxx, maxy);
		eat(map);
	}
};