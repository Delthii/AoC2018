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

void stream(char** map, int x, int y) {
	while (map[y][x] == '.') map[y++][x] = 'w';
	y--;
	bool closed = true;
	while (closed) {
		closed = false;
		while (map[y + 1][x] != '.' && map[y][x+1] == '.') map[y][x++] = 'w';
		if (map[y + 1][x] == '.') {
			stream(map, x, y);
		}
		else if (map[y][x+1] == '#') {
			closed = true;
		}
		//Seems to work until here atm
		while (map[y + 1][x--] != '.' && map[y - 1][x] == '.') map[y][x] = 'w';
		if (map[y + 1][x] != '.') {
			stream(map, x, y);
			closed = false;
		}
		else if (map[y][x] == '#') {
			if (closed) {
				y--;
				x++;
			}
		}
	}
}

void part17A(vector<string> input) {
	auto m = matrix(2000, 2000, '.');
	int maxy = 0, miny = 10000;
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
			}
		}
		else if (f[0] == "x") {
			for (int i = stoi(s[0]); i <= stoi(s[1]); i++) {
				m[i][stoi(f[1])] = '#';	
				miny = min(i, miny);
				maxy = max(i, maxy);
			}
		}
	}
	stream(m, 500, 0);
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