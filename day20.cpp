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
#include <stack>
using namespace std;

int H(int i1, int i2) {
	return i1*256*128 + i2;
}

void movePath(vector<vector<vector<char>>> &graph, int &x, int &y, char c) {
	bool in = false;
	for (auto &C : graph[x][y]) {
		if (C == c) {
			in = true;
			break;
		}
	}
	if(!in) graph[x][y].push_back(c);
	if (graph[x][y].size() > 4) cout << "ERROR TOMANY NEIGHBOURS" << endl;
	if (c == 'W') { x--; c = 'E'; }
	else if (c == 'E') { x++; c = 'W'; }
	else if (c == 'N') { y--; c = 'S'; }
	else if (c == 'S') { y++; c = 'N'; }
	else cout << "Something went wrong  PATH: " << c << endl;
	in = false;
	for (auto &C : graph[x][y]) {
		if (C == c) {
			in = true;
			break;
		}
	}
	if(!in) graph[x][y].push_back(c);
	if (graph[x][y].size() > 4) cout << "ERROR TOMANY NEIGHBOURS" << endl;
}

auto BFS(vector<vector<vector<char>>> &graph, int x, int y) {
	unordered_set<int> visisted;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visisted.insert(H(x,y));
	unordered_map<int, int> distance;
	distance[H(x,y)] = 0;
	while (!q.empty()) {	
		auto n = q.front(); q.pop();
		for (auto &c : graph[n.first][n.second]) {
			pair<int, int> p;
			if (c == 'W') p = pair<int, int>(n.first - 1, n.second);
			else if (c == 'E') p = pair<int, int>(n.first + 1, n.second);
			else if (c == 'S') p = pair<int, int>(n.first, n.second+1);
			else if (c == 'N') p = pair<int, int>(n.first, n.second-1);
			if (visisted.find(H(p.first, p.second)) == visisted.end()) {
				q.push(p);
				visisted.insert(H(p.first, p.second));
				distance[H(p.first, p.second)] = distance[H(n.first, n.second)] + 1;
			}
		}
	}
	return distance;
}

void parse(string in, vector<vector<vector<char>>> &graph, string path, int x, int y) {
	auto coords = stack<pair<int, int>>();
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == '(') {
			coords.push(pair<int, int>(x, y));
		}
		else if (in[i] == '|') {
			auto p = coords.top();
			x = p.first, y = p.second;
		}
		else if (in[i] == ')') {
			coords.pop();
		}
		else {
			movePath(graph, x, y, in[i]);
		}
	}
}

void part20A(vector<string> input) {
	auto in = input[0].substr(1, input[0].size()-2);
	auto graph = vector<vector<vector<char>>>(1000, vector<vector<char>>(1000,vector<char>()));
	int x = 500, y = 500;
	parse(in, graph, "", 500,500);
	auto distance = BFS(graph, 500, 500);
	int max = 0;
	int count = 0;
	for (auto d : distance) {
		if (d.second > max) max = d.second;
		if (d.second >= 1000) count++;
	}
	cout << max << endl;
	cout << count << endl;
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