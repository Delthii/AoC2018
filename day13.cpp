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


void moveCarts(vector<Cart> &carts) {
	for (auto &c : carts) {
		switch (c.dir)
		{
		case UP:
			c.y--;
			break;
		case DOWN:
			c.y++;
			break;
		case LEFT:
			c.x--;
			break;
		case RIGHT:
			c.x++;
			break;
		default:
			break;
		}
	}
}

void partA13(vector<string> input) {
	
	vector<Cart> carts;
	int track[13][13];
	memset(track, 0, sizeof(track));
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			track[i][j] = input[i][j] == '+' ? 2 : 0;
			track[i][j] = input[i][j] == '/' ? 3 : 0;
			track[i][j] = input[i][j] == '\\' ? 4 : 0;
			track[i][j] = input[i][j] != ' ' ? 1 : 0;
			Cart c;
			switch (input[i][j])
			{
			case '^':
				c = Cart({ i,j, UP, STRAIGHT });
				carts.push_back(c);
				break;
			case '>':
				c = Cart({ i,j, RIGHT, STRAIGHT });
				carts.push_back(c);
				break;
			case '<':
				c = Cart({ i,j, LEFT, STRAIGHT });
				carts.push_back(c);
				break;
			case 'v':
				c = Cart({ i,j, DOWN, STRAIGHT });
				carts.push_back(c);
				break;
			default:
				break;
			}
		}
	}
	bool crash = false;
	while (!crash) {
		for (int i = 0; i < sizeof(track)/sizeof(int); i++) {
			for (int j = 0; j < sizeof(track[i]) / sizeof(int); j++) {
				cout << track[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (auto &c : carts) {
			int x = c.x;
			int y = c.y;
			if (track[x][y] == 2) {
				c.dir = c.intersection == STRAIGHT ? c.dir : c.intersection;
				c.intersection += 1;
				c.intersection %= 3;
			}
			else if (track[x][y] == 3){
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
		moveCarts(carts);
		for (int i = 0; i < carts.size(); i++) {
			for (int j = 0; j < carts.size(); j++) {
				if (i == j) continue;
				auto c1 = carts[i];
				auto c2 = carts[j];
				if (c1.x == c2.x && c1.y == c2.y) {
					cout << c1.x << " " << c2.y << endl;
					crash = true;
				}
			}
		}

	}

	cout << " " << endl;
}

void partB13(vector<string> input) {

}


int main() {
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