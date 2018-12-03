#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <numeric>
#include <functional>
#include <vector>
#include <unordered_map>
#include "Helpers.h"
#include "Stopwatch.h"
using namespace std;

void part2A(vector<string> input) {
	int numberOfTwos = 0, numberOfThrees = 0;
	for (auto s : input) {
		unordered_map<char, int> lettercount;
		for (auto c : s) {
			lettercount[c]++;
		}
		bool two = false, three = false;
		for (auto k : lettercount) {
			if (k.second == 2)two = true;
			else if (k.second == 3)three = true;
		}
		if (two) numberOfTwos++;
		if (three) numberOfThrees++;
	}
	cout << numberOfTwos*numberOfThrees << endl;
}

void part2B(vector<string> input) {
	auto wordsWithCertainIndexRemoved = vector<unordered_set<string>>(input[0].length());
	bool found = false;
	for (auto id : input) {
		for (string::size_type i = 0; i < id.length(); i++) {
			string partialString = string(id);
			partialString.erase(i, 1);
			if (!wordsWithCertainIndexRemoved[i].insert(partialString).second) {
				cout << partialString << endl;
				found = true;
				break;
			}
		}
		if (found) break;
	}
}

int main2() {
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

	//part2A(in);
	auto sw = Stopwatch();
	sw.start();
	part2B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}