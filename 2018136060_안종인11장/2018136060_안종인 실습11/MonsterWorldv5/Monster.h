#pragma once
#include<stdio.h>
#include "Canvas.h"
#include "Point.h"
#define INIT_ENERGY 100
#define ITEM_ENERGY 8

class Monster
{
protected:
	string name, icon;
	int x, y, nItem;
	int nEnergy;
	static int MonCount;
	Point q, p;
	int nSleep;
	double dist;
	double total;

	void clip(int maxx, int maxy) { p(maxx, maxy); }

	void eat(int** map)
	{
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
		}
		dist += (double)(p - q);
		total += (double)(p - q);
		q = p;
		if(dist>20){
			dist = 0;
			nSleep = 10;
		}
	}
	bool isSleep() {
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}

public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		:name(n), icon(i), nItem(0), p(px, py), q(px, py), nSleep(0), dist(0.0), total(0.0) {}
	
	virtual ~Monster() {
		cout << icon <<" 먹은 아이템: "<< nItem << " 거리: " << total << endl;
	}
	

	static void PrintCount() { cout << "전체 몬스터 수 : " << MonCount << endl; };
	static int GetMonCount() { return MonCount; }
	string getname() { return name; }
	int getEnergy() { return nEnergy; }
	void draw(Canvas &canvas) { canvas.draw(p.x, p.y, icon); }
	virtual void move(int** map, int maxx, int maxy)
	{
		if (!isSleep()) {
			int num = rand() % 9 + 1;
			p += Point(num % 3 - 1, num / 3 - 1);
			clip(maxx, maxy);
			eat(map);

		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }
};