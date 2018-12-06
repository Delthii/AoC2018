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


void partA6(vector<string> input) {
	auto co = unordered_map<int,pair<int, int>>();
	int i = 0;
	auto occ = unordered_map<int, int>();
	for (auto s : input) {
		auto ss = splitString(s, ", ");
		int x = stoi(ss[0]), y = stoi(ss[1]);
		co[i] = pair<int, int>(x, y);
		i++;
	}
	

	
	for (int i = -900; i < 1000; i++) {
		for (int j = -900; j < 1000; j++) {
			unordered_map<int, int> distance;
			for (auto c : co) {
				int m = abs(c.second.first - i) + abs(c.second.second - j);
				distance[c.first] = m;
			}
			int minc = -1;
			int mindis = 1000000;
			unordered_set<int> candidates;
			for (auto d : distance) {
				if (d.second < mindis) {
					mindis = d.second;
					minc = d.first;
					candidates.clear();
					candidates.insert(minc);
				}
				else if (d.second == mindis) {
					candidates.insert(d.first);
				}
			}
			if (candidates.size() == 1) {
				occ[*candidates.begin()]++;
			}
		}
		
	}
	vector<int> l;
	for (auto c : occ) {
		l.push_back(c.second);
	}
	sort(l.begin(), l.end());
	for (auto e : l) {
		cout << e << endl;
	}
}




void partB6(vector<string> input) {
	auto co = unordered_map<int, pair<int, int>>();
	int i = 0;
	auto occ = unordered_map<int, int>();
	for (auto s : input) {
		auto ss = splitString(s, ", ");
		int x = stoi(ss[0]), y = stoi(ss[1]);
		co[i] = pair<int, int>(x, y);
		i++;
	}

	int sum = 0;

	for (int i = -4100; i < 4100; i++) {
		for (int j = -4100; j < 4100; j++) {
			unordered_map<int, int> distance;
			int all = 0;
			for (auto c : co) {
				int m = abs(c.second.first - i) + abs(c.second.second - j);
				all += m;
			}
			if (all < 10000) sum++;
		}

	}
	cout << sum << endl;
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

	//partA6(input);

	partB6(input);
	system("pause");
	return 0;
}