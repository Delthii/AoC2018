#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <algorithm>
#include <stack>
#include "Helpers.h"
#include "Stopwatch.h"
using namespace std;



void partA9(vector<string> input) {
	const int players = 441;
	const int last = 71032;
	vector<long> circle = vector<long>();
	long scores[players+1];
	memset(scores,0, sizeof(scores));
	circle.push_back(0);

	int current = 0;
	for (int i = 1; i <= last; i++) {
		if (i % 23 == 0) {
			scores[i % players] += i;
			current = (current - 7);
			if (current < 0) {
				current += circle.size();
			}
			scores[i % players] += circle[current];
			circle.erase(circle.begin() + current, circle.begin() + current + 1);
		}
		else {
			current = (current + 2) % (circle.size());
			if (current == 0) {
				circle.push_back(i);
				current = circle.size() - 1;
			}
			else {
				circle.insert(circle.begin() + current, i);
			}
		}
	}

	int max = 0;
	for (auto i : scores) {
		if (i > max) max = i;
	}
	cout << max << endl;
}




void partB9(vector<string> input) {
	const long long players = 441;
	const long long last = 71032*100;
	list<long long> circle = list<long long>();
	long long scores[players + 1];
	memset(scores, 0, sizeof(scores));
	circle.push_back(0);

	long long current = 0;
	auto it = circle.begin();
	for (long long i = 1; i <= last; i++) {
		if (i % 23 == 0) {
			scores[i % players] += i;
			for (int j = 0; j < 7; j++) {
				if (it == circle.begin()) {
					it = circle.end();
				}
				it--;
			}
			scores[i % players] += *it;
			circle.erase(it);
			it++;
			if (it == circle.end()) {
				it = circle.begin();
			}
		}
		else {
			for (int j = 0; j<2; j++) {
				it++;
				if (it == circle.end()) {
					it = circle.begin();
				}
			}
			circle.insert(it, i);
			it--;
		}
	}

	long long max = 0;
	for (auto i : scores) {
		if (i > max) max = i;
	}
	cout << max << endl;
}

int main9() {
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

	//partA9(input);
	partB9(input);
	system("pause");
	return 0;
}