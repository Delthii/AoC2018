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
using namespace std;
/*
position=< 5,  9> velocity=< 1, -2>
position=<14,  7> velocity=<-2,  0>
position=<-3,  6> velocity=< 2, -1>
*/

void partA10(vector<string> input) {
	int i = 0;
	unordered_map<int, pair<int, int>> points;
	unordered_map<int, pair<int, int>> vels;
	for (auto row : input) {
		auto ss = splitString(row, "<");
		auto sss = splitString(ss[1], ", ");
		pair<int, int> point = pair<int, int>(stoi(sss[0]), stoi(sss[1]));
		ss = splitString(ss[2], ", ");
		pair<int, int> vel = pair<int, int>(stoi(ss[0]), stoi(ss[1]));
		points[i] = point;
		vels[i] = vel;
		i++;
	}

	int j = 0;
	int time = 0;
	while (true) {
		for (int i = 0; i < points.size(); i++) {
			points[i].first += vels[i].first;
			points[i].second += vels[i].second;
		}
		time++;
		int max = -1110110, min = 1101010;
		for (auto e : points) {
			if (e.second.first > max) max = e.second.first;
			if (e.second.first < min) min = e.second.first;
			if (e.second.second > max) max = e.second.second;
			if (e.second.second < min) min = e.second.second;
		}
		
		if (abs(max) - abs(min) < 75) {
			vector<vector<char>> grid = vector<vector<char>>(500);
			for (int i = 0; i < 500; i++) grid[i] = (vector<char>(500));
			for (auto e : points) {
				int x = e.second.first + 100;
				int y = e.second.second + 100;
				grid[x][y] = 1;
			}
			for (int x = min+100; x < max+101; x++) {
				for (int y = min+100; y < max+101; y++) {
					if (grid[y][x] == 1) cout << "#";
					else cout << ".";
				}
				cout << endl;
			}
			cout << endl << time << endl;
			cout << endl;
		}
	}

}



void partB10(vector<string> input) {
	
}

int main10() {
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
	partA10(input);
	
	//partB10(input);
	sw.stop();
	cout << sw.duration() << endl;
	system("pause");
	return 0;
}