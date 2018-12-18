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
#include <chrono>
#include <thread>
using namespace std;

/*
y=1230, x=524..528
y=977, x=460..462
y=1757, x=566..584
*/
void stream(char**, int, int);

int maxy = 0;

void stillWater(char ** map, int x, int y, int xl, int xr) {
	for (int i = x; i > xl; i--) {
		map[y][i] = '~';
	}

	for (int i = x; i < xr; i++) {
		map[y][i] = '~';
	}
}

int left(char ** map, int x, int y){
	int start = x;
	x--;
	while (map[y][x] == '.' || map[y][x] == 'w') {
		map[y][x] = 'w';
		if (map[y + 1][x] == '.') {
			stream(map, x, y+1);
			return 0;
		}
		x--;
	}
	return x;
}

int right(char ** map, int x, int y){
	int start = x;
	while (map[y][x] == '.' || map[y][x] == 'w') {
		map[y][x] = 'w';
		if (map[y + 1][x] == '.') {
			stream(map, x, y+1);
			return 0;
		}
		x++;
	}
	return x;
}

void stream(char** map, int x, int y) {
	while (map[y][x] == '.') {
		if (y > maxy) return;
		if (map[y][x] == 'w' || map[y][x] == '~') {
			return;
		}
		map[y++][x] = 'w';
	}
	if (map[y][x] == 'w') return;
	y--;
	int r = 1, l = 1;
	while (r && l) {
		r = right(map, x, y);
		l = left(map, x, y);
		if (r && l) {
			stillWater(map, x, y, l, r);
		}
		y--;
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
	int water = 0;
	int still = 0;
	for (int y = miny; y <= maxy+2; y++) {
		for (int x = minx-2;  x <= maxx +2 ; x++) {
			if (m[y][x] == '.') {
				cout << ' ';
				continue;
			}
			if (m[y][x] == 'w') water++;
			if (m[y][x] == '~') still++;
			cout << m[y][x];
		}
		this_thread::sleep_for(std::chrono::milliseconds(100));
		cout << endl;
	}
	cout << still + water << endl;
	cout << still << endl;
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