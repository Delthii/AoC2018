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
	int l2 = 0, l3 = 0;
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
		if (two) l2++;
		if (three) l3++;
	}
	cout << l2*l3 << endl;
}

void part2B(vector<string> input) {
	auto words = vector<unordered_set<string>>(input[0].length());
	bool found = false;
	for (auto a : input) {
		for (string::size_type i = 0; i < a.length(); i++) {
			string ss = string(a);
			ss.erase(i, 1);
			if (!words[i].insert(ss).second) {
				cout << ss << endl;
				found = true;
				break;
			}
		}
		if (found) break;
	}
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

	//part2A(in);
	auto sw = Stopwatch();
	sw.start();
	part2B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
}