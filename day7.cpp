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
Step C must be finished before step D can begin.
Step W must be finished before step N can begin.
Step S must be finished before step N can begin.
Step O must be finished before step S can begin.*/

void partA7(vector<string> input) {
	unordered_map<char, unordered_set<char>> pre;
	unordered_set<char> nodes;
	for (auto l : input) {
		auto ss = splitString(l, " ");
		pre[ss[7][0]].insert( ss[1][0]);
		nodes.insert(ss[7][0]);
		nodes.insert(ss[1][0]);
	}

	string ans;
	
	while (!nodes.empty()) {
		unordered_set<char> notready = unordered_set<char>();
		for (auto p : pre) {
			if (p.second.size() > 0) {
				notready.insert(p.first);
			}
		}
		vector<char> cand;
		for (auto &n : nodes) {
			if (notready.find(n) == notready.end()) {
				cand.push_back(n);
			}
		}
		sort(cand.begin(), cand.end());
		nodes.erase(cand[0]);
		pre.erase(cand[0]);
		ans += cand[0];
		for (auto &p : pre) {
			p.second.erase(cand[0]);
		}
	}
	cout << ans << endl;
}



void partB7(vector<string> input) {
	unordered_map<char, unordered_set<char>> pre;
	unordered_set<char> nodes;
	for (auto l : input) {
		auto ss = splitString(l, " ");
		pre[ss[7][0]].insert(ss[1][0]);
		nodes.insert(ss[7][0]);
		nodes.insert(ss[1][0]);
	}
	int workers = 5;
	int ticks = 0;
	auto working = unordered_map<char, int>();
	while (!nodes.empty()) {
		for (auto it = working.begin(); it != working.end();) {
			if (it->second <= ticks) {
				nodes.erase(it->first);
				pre.erase(it->first);
				for (auto &p : pre) {
					p.second.erase(it->first);
				}
				it = working.erase(it);
				workers++;
			}
			else {
				it++;
			}
		}

		vector<char> cand;
		unordered_set<char> notready = unordered_set<char>();
		for (auto p : pre) {
			if (p.second.size() > 0) {
				notready.insert(p.first);
			}
		}
		
		for (auto &n : nodes) {
			if (notready.find(n) == notready.end()) {
				cand.push_back(n);
			}
		}
		sort(cand.begin(), cand.end());
		for (int i = 0; workers > 0 && i < cand.size(); i++) {
			if(working.find(cand[i]) == working.end()){
				working[cand[i]] = cand[i] - 'A' + 60 + 1 + ticks;
				workers--;
			}
		}
		ticks++;
	}
	cout << --ticks << endl;
}

int main7() {
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

	//partA7(input);

	partB7(input);
	system("pause");
	return 0;
}