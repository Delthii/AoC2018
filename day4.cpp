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
//[1518-04-22 00:52] wakes up
//[1518-05-16 00:00] Guard #1319 begins shift

void addMin(int sleep, int wakeup, int guard, unordered_map<int, int> &gmap, unordered_map<int, int> &timeslept) {
	for (int i = sleep; i < wakeup; i++) {
		gmap[i]++;
	}
	timeslept[guard] += wakeup - sleep;
}

void partA4(vector<string> input) {
	unordered_map <int, unordered_map<int, int>> minutes;
	unordered_map<int, int> timeslept;
	int guard = -1;
	int wakeup = -1;
	int sleep = -1;
	sort(input.begin(), input.end());

	for (auto s : input) {
		auto ss = splitString(s, "] ");
		auto k = splitString(ss[1], " ");
		auto t = splitString(ss[0], " ")[1];
		auto time = splitString(t, ":");
		if (k[0] == "Guard") guard = stoi(k[1].erase(0,1));
		if (minutes.find(guard) == minutes.end()) {
			minutes[guard] = unordered_map<int, int>();
		}
		if (k[0] == "falls") sleep = stoi(time[1]);
		if (k[0] == "wakes") {
			wakeup = stoi(time[1]);
			addMin(sleep, wakeup, guard, minutes[guard], timeslept);
		}	
	}
	int m = 0;
	for (auto g : timeslept) {
		if (g.second > m) {
			m = g.second;
			guard = g.first;
		}
	}
	int max = 0;
	int min = 0;
	for (auto p : minutes[guard]) {
		if (p.second > max) { 
			max = p.second;
			min = p.first;
		}
	}
	cout << guard*min << endl;

}



void partB4(vector<string> input) {
	unordered_map <int, unordered_map<int, int>> minutes;
	unordered_map<int, int> timeslept;
	int guard = -1;
	int wakeup = -1;
	int sleep = -1;
	sort(input.begin(), input.end());

	for (auto s : input) {
		auto ss = splitString(s, "] ");
		auto k = splitString(ss[1], " ");
		auto t = splitString(ss[0], " ")[1];
		auto time = splitString(t, ":");
		if (k[0] == "Guard") guard = stoi(k[1].erase(0, 1));
		if (minutes.find(guard) == minutes.end()) {
			minutes[guard] = unordered_map<int, int>();
		}
		if (k[0] == "falls") sleep = stoi(time[1]);
		if (k[0] == "wakes") {
			wakeup = stoi(time[1]);
			addMin(sleep, wakeup, guard, minutes[guard], timeslept);
		}
	}
	int m = 0;
	for (auto g : timeslept) {
		if (g.second > m) {
			m = g.second;
			guard = g.first;
		}
	}
	int max = 0;
	int min = 0;
	for (auto p : minutes) {
		for (auto g : p.second) {
			if (g.second > max) {
				max = g.second;
				guard = p.first;
				min = g.first;
			}
		}
	}
	cout << guard*min << endl;
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

	partA4(input);
	partB4(input);
	system("pause");
	return 0;
}