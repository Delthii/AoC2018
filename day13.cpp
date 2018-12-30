#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include "Helpers.h"
#include "Stopwatch.h"
#include <cmath>
using namespace std;


static const int LEFT = 0;
static const int UP = 1;
static const int STRAIGHT = 1;
static const int RIGHT = 2;
static const int DOWN = 3;

struct Cart {
	int x;
	int y;
	int dir;
	int intersection;
};

void moveCarts(vector<Cart> &carts, bool &crash) {
	sort(carts.begin(), carts.end(),
		[](const Cart& a, const Cart &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	for (auto &c : carts) {
		switch (c.dir)
		{
		case UP:
			c.x--;
			break;
		case DOWN:
			c.x++;
			break;
		case LEFT:
			c.y--;
			break;
		case RIGHT:
			c.y++;
			break;
		default:
			break;
		}

		for (int i = 0; i < carts.size() && !crash; i++) {
			for (int j = 0; j < carts.size() && !crash; j++) {
				if (i == j) continue;
				auto c1 = carts[i];
				auto c2 = carts[j];
				if (c1.x == c2.x && c1.y == c2.y) {
					cout << c1.y << " " << c2.x << endl;
					crash = true;
				}
			}
		}


	}
}

bool inVector(vector<int> v, int i) {
	for (auto e : v) if (e == i) {
		return true;
	}
	return false;
}

void moveCarts(vector<Cart> &carts) {
	sort(carts.begin(), carts.end(),
		[](const Cart& a, const Cart &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	for (auto it = carts.begin(); it != carts.end();) {
		switch (it->dir)
		{
		case UP:
			it->x--;
			break;
		case DOWN:
			it->x++;
			break;
		case LEFT:
			it->y--;
			break;
		case RIGHT:
			it->y++;
			break;
		default:
			break;
		}
		bool inc = true;
		for (auto itc = carts.begin(); itc != carts.end(); itc++) {
			if (itc->x == it->x && itc->y == it->y) {
				if (it == itc) continue;
				it = min(itc, it);
				it = carts.erase(it);
				it = carts.erase(it);
				inc = false;
				break;
			}
		}
		if (inc) it++;
	}
}

void parse13(std::vector<std::string> &input, int  track[151][151], std::vector<Cart> &carts);

void update(std::vector<Cart> &carts, int  track[151][151]);

void partA13(vector<string> input) {
	
	vector<Cart> carts;
	int track[151][151];
	memset(track, 0, sizeof(track));
	parse13(input, track, carts);
	while (carts.size() > 1) {
		update(carts, track);
		moveCarts(carts);
	}
	cout << carts[0].y << "," << carts[0].x << endl;
	cout << " " << endl;
}

void update(std::vector<Cart> &carts, int  track[151][151])
{
	for (auto &c : carts) {
		int x = c.x;
		int y = c.y;
		if (track[x][y] == 2) {
			if (c.intersection == RIGHT) {
				switch (c.dir)
				{
				case UP:
					c.dir = RIGHT;
					break;
				case DOWN:
					c.dir = LEFT;
					break;
				case LEFT:
					c.dir = UP;
					break;
				case RIGHT:
					c.dir = DOWN;
					break;
				default:
					break;
				}
			}
			else if (c.intersection == LEFT) {
				switch (c.dir)
				{
				case UP:
					c.dir = LEFT;
					break;
				case DOWN:
					c.dir = RIGHT;
					break;
				case LEFT:
					c.dir = DOWN;
					break;
				case RIGHT:
					c.dir = UP;
					break;
				default:
					break;
				}
			}
			c.intersection += 1;
			c.intersection %= 3;
		}
		else if (track[x][y] == 3) {
			if (c.dir == UP) c.dir = RIGHT;
			else if (c.dir == LEFT) c.dir = DOWN;
			else if (c.dir == RIGHT) c.dir = UP;
			else if (c.dir == DOWN) c.dir = LEFT;
		}
		else if (track[x][y] == 4) {
			if (c.dir == RIGHT) c.dir = DOWN;
			else if (c.dir == UP) c.dir = LEFT;
			else if (c.dir == LEFT) c.dir = UP;
			else if (c.dir == DOWN) c.dir = RIGHT;
		}
	}
}

void parse13(std::vector<std::string> &input, int  track[151][151], std::vector<Cart> &carts)
{
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			switch (input[i][j])
			{
			case '+':
				track[i][j] = 2;
				break;
			case '/':
				track[i][j] = 3;
				break;
			case '\\':
				track[i][j] = 4;
				break;
			case ' ':
				track[i][j] = 0;
				break;
			default:
				track[i][j] = 1;
				break;
			}

			Cart c;
			switch (input[i][j])
			{
			case '^':
				c = Cart({ i,j, UP, LEFT });
				carts.push_back(c);
				break;
			case '>':
				c = Cart({ i,j, RIGHT, LEFT });
				carts.push_back(c);
				break;
			case '<':
				c = Cart({ i,j, LEFT, LEFT });
				carts.push_back(c);
				break;
			case 'v':
				c = Cart({ i,j, DOWN, LEFT });
				carts.push_back(c);
				break;
			default:
				break;
			}
		}
	}
}

int main13() {
	string line;
	ifstream myfile("in.txt");
	vector<string> input;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			input.push_back(line);
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	auto sw = Stopwatch();
	sw.start();
	partA13(input);
	//partB12(input);


	sw.stop();

	cout << sw.duration() << endl;
	system("pause");
	return 0;
}