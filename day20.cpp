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
#include <set>
#include <queue>
using namespace std;

void movePath(vector<vector<vector<char>>> &graph, int x, int y, string path) {
	for (auto &c : path) {
		bool in = false;
		for (auto C : graph[x][y]) {
			if (C == c) {
				in = true;
				break;
			}
		}
		if(!in) graph[x][y].push_back(c);
		if (graph[x][y].size() > 4) cout << "ERROR TOMANY NEIGHBOURS" << endl;
		if (c == 'W') x--;
		else if (c == 'E') x++;
		else if (c == 'N') y--;
		else if (c == 'S') y++;
		else cout << "Something went wrong  PATH: "<< path << endl;
	}
}
//ENNWSWW(NEWS|)SSSEEN(WNSE|)EE(SWEN|)NNN
//WSSEESWWWNW(S|NENNEEEENN(ESSSSW(NWSW|SSEN)|WSWWN(E|WWS(E|SS))))
vector<string> parsed;
void parse(string in, string end) {
	vector<string> allCombos;
	if (in.find(')') == string::npos) {
		parsed.push_back(in + end);
		return;
	}
	if (in[in.size() - 1] != ')') {
		for (int i = in.size() - 1; i >= 0; i--) {
			if (in[i] == ')') {
				auto s = in.substr(i + 1);
				in.erase(in.begin() + i + 1, in.end());
				parse(in, s + end);
				return;
			}
		}
	}
	int rp = -1, lp = -1;
	for (int i = in.size()-1; i >= 0; i--) {
		if (in[i] == ')') rp = i;
		if (in[i] == '(') {
			auto ss = in.substr(i + 1, rp - i-1);
			for (auto &s : splitString(ss, "|")) {
				allCombos.push_back(s+end);
			}
			in.erase(in.begin()+i,in.begin()+rp+1);
			break;
		}
	}
	
	for (auto it = allCombos.begin(); it != allCombos.end();it++) {
		parse(in, *it);
	}
}

int BFS(vector<vector<vector<char>>> &graph, int x, int y) {
	unordered_set<int> visisted;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visisted.insert(x * 7 + y * 11);
	int distance = 0;
	while (!q.empty()) {
		distance++;
		auto n = q.front(); q.pop();
		for (auto &c : graph[n.first][n.second]) {
			pair<int, int> p;
			if (c == 'W') p = pair<int, int>(x - 1, y);
			else if (c == 'E') p = pair<int, int>(x + 1, y);
			else if (c == 'S') p = pair<int, int>(x, y+1);
			else if (c == 'N') p = pair<int, int>(x, y-1);
			if (visisted.find(p.first * 7 + p.second * 11) == visisted.end()) {
				q.push(p);
				visisted.insert(p.first * 7 + p.second * 11);
			}
		}
	}
	return distance;
}

void part20A(vector<string> input) {
	auto in = input[0].substr(1, input[0].size()-2);
	auto graph = vector<vector<vector<char>>>(1000, vector<vector<char>>(1000,vector<char>()));
	int x = 500, y = 500;
	parse(in, "");
	for (auto &path : parsed) {
		movePath(graph, x, y, path);
	}
	cout << BFS(graph, x, y) << endl;
}

void part20B(vector<string> input) {
	
	
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

	part20A(in);
	//part14B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}