#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <stack>
#include "Helpers.h"
#include "Stopwatch.h"
using namespace std;

struct Node {
	int childs;
	int metadata;
};

void partA8(vector<string> input) {
	input = splitString(input[0], " ");
	auto in = vector<int>();
	for (auto &i : input) {
		in.push_back(stoi(i));
	}
	int metadata = 0;
	for (int i = 0; i < in.size();) {
		if (in[i] == 0) {
			int m = i + 2 + in[i + 1];
			for (int j = i + 2; j < i + 2 + in[i + 1]; j++) {
				metadata += in[j];
			}
			in.erase(in.begin() + i, in.begin() + m);
			if (i != 0) {
				in[i - 2]--;
				i -= 2;
			}
		}
		else {
			i++;
		}
	}
	cout << metadata << endl;
}

pair<int, vector<int>> rec2(vector<int> v) {
	int c = v[0];
	int m = v[1];
	v.erase(v.begin(), v.begin() + 2);
	int sum = 0;
	for (int i = 0; i < c; i++) {		
		auto p = rec2(v);
		sum += p.first;
		v = p.second;
	}
	int r = accumulate(v.begin(), v.begin() + m, 0);
	v.erase(v.begin(), v.begin() + m);
	return pair<int, vector<int>>(r+sum, v);
}

void partA82(vector<string> input) {
	input = splitString(input[0], " ");
	auto in = vector<int>();
	for (auto &i : input) {
		in.push_back(stoi(i));
	}
	auto p = rec2(in);
	cout << p.first << endl;
}


pair<int, vector<int>> rec(vector<int> v) {
	int c = v[0];
	int m = v[1];
	v.erase(v.begin(), v.begin() + 2);

	auto scores = vector<int>();

	for (int i = 0; i < c; i++) {
		auto p = rec(v);
		scores.push_back(p.first);
		v = p.second;
	}

	if (c == 0) {
		int sum = accumulate(v.begin(), v.begin() + m, 0);
		v.erase(v.begin(), v.begin() + m);
		return pair<int, vector<int>>(sum, v);
	}
	else {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int meta = v[i];
			if (meta <= scores.size() && meta > 0) {
				sum += scores[meta - 1];
			}
		}
		v.erase(v.begin(), v.begin() + m);
		return pair<int, vector<int>>(sum, v);
	}
}

void partB8(vector<string> input) {
	input = splitString(input[0], " ");
	auto in = vector<int>();
	for (auto &i : input) {
		in.push_back(stoi(i));
	}
	auto p = rec(in);
	cout << p.first << endl;
}

int main8() {
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

	partA82(input);

	//partB8(input);
	system("pause");
	return 0;
}