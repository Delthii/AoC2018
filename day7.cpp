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
	while (!pre.empty()) {

	}
	cout << ans << endl;
}




void partB7(vector<string> input) {
	
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

	partA7(input);

	//partB7(input);
	system("pause");
	return 0;
}