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

/*
y=1230, x=524..528
y=977, x=460..462
y=1757, x=566..584
*/
bool stream(char**, int, int);

int maxy = 0;
vector<pair<int, int>> overflows;
int left(char ** map, int x, int y){
	x--;
	while (map[y][x] == '.') {
		map[y][x] = 'w';
		if (map[y + 1][x] == '.') {
			return x;
		}
		x--;
	}
	return false;
}

int right(char ** map, int x, int y){
	x++;
	while (map[y][x] == '.') {
		map[y][x] = 'w';
		if (map[y + 1][x] == '.') {
			return x;
		}
		x++;
	}
	return false;
}

bool stream(char** map, int x, int y) {
	while (true) {
		if (map[y][x] == 'w') return false;
		while (map[y][x] == '.') {
			if (y > maxy) return false;
			map[y++][x] = 'w';
		}
		y--;
		int r = false;
		int l = false;
		while (!r && !l) {
			r = right(map, x, y);
			l = left(map, x, y);
			int temp = x;
			if (!r && !l) {
				while (map[y][temp] == 'w') map[y][temp++] = '~';
				temp = x - 1;
				while (map[y][temp] == 'w') map[y][temp--] = '~';
			}
			y--;
		}
		if (r) overflows.push_back(pair<int, int>(r, y+2));
		if (l) overflows.push_back(pair<int, int>(l, y+2));
		break;
	}
	pair<int, int> p;
	while (overflows.size() > 0) {
		p = overflows.back();
		overflows.pop_back();

		stream(map, p.first, p.second);
	}
}

void part17A(vector<string> input) {
	auto m = matrix(2000, 2000, '.');
	maxy = 0;
	int maxx = 0;
	int minx = 10000;
	int miny = 10000;
	for  (auto e : input)
	{
		auto ss = splitString(e, ", ");
		auto f = splitString(ss[0], "=");
		auto s = splitString(ss[1].substr(2), "..");
		if (f[0] == "y") {
			for (int i = stoi(s[0]); i <= stoi(s[1]); i++) {
				m[stoi(f[1])][i] = '#';
				miny = min(stoi(f[1]), miny);
				maxy = max(stoi(f[1]), maxy);
				minx = min(i, minx);
				maxx = max(i, maxx);
			}
		}
		else if (f[0] == "x") {
			for (int i = stoi(s[0]); i <= stoi(s[1]); i++) {
				m[i][stoi(f[1])] = '#';	
				miny = min(i, miny);
				maxy = max(i, maxy);
				minx = min(stoi(f[1]), minx);
				maxx = max(stoi(f[1]), maxx);
			}
		}
	}
	stream(m, 500, 0);
	for (int y = miny; y <= maxy+2; y++) {
		for (int x = minx-2;  x <= maxx +2 ; x++) {
			cout << m[y][x];
		}
		for (int i = 0; i < 10000000; i++);
		cout << endl;
	}
}

void part17B(vector<string> input) {


}

int main() {
	string line;
	ifstream myfile("in.txt");
	vector<string> in;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			in.push_back(line);
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	auto sw = Stopwatch();
	sw.start();

	part17A(in);
	//part16B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}