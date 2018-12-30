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

void movePath(vector<vector<vector<char>>> &graph, int &x, int &y, string path) {
	for (auto c : path) {
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
		else cout << "Something went wrong  PATH: "<< path << endl;
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
	visisted.insert(x * 7 + y * 11);
	unordered_map<int, int> distance;
	distance[x * 7 + y * 11] = 0;
	while (!q.empty()) {	
		auto n = q.front(); q.pop();
		for (auto &c : graph[n.first][n.second]) {
			pair<int, int> p;
			if (c == 'W') p = pair<int, int>(n.first - 1, n.second);
			else if (c == 'E') p = pair<int, int>(n.first + 1, n.second);
			else if (c == 'S') p = pair<int, int>(n.first, n.second+1);
			else if (c == 'N') p = pair<int, int>(n.first, n.second-1);
			if (visisted.find(p.first * 7 + p.second * 11) == visisted.end()) {
				q.push(p);
				visisted.insert(p.first * 7 + p.second * 11);
				distance[p.first * 7 + p.second * 11] = distance[n.first * 7 + n.second * 11] + 1;
			}
		}
	}
	return distance;
}
//^ESSWWN(E|NNENN(EESS(WNSE|)SSS|WWWSSSSE(SW|NNNE)))$
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
	for (auto d : distance) {
		if (d.second > max) max = d.second;
	}
	cout << max << endl;
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