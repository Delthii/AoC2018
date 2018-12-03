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

void partA3(vector<string> input) {
	auto matrix = new int*[1200];
	for (int i = 0; i < 1200; i++) {
		matrix[i] = new int[1200];
		fill(matrix[i], matrix[i]+1200, 0);
	}

	int res = 0;
	int id = 1;
	unordered_set<int> ids;
	for (auto s : input) {
		auto ss = splitString(s, " ");
		auto dim = splitString(ss[3], "x");
		auto pos = splitString(ss[2], ",");
		auto x = stoi(pos[0]);
		auto y = stoi(pos[1]);
		auto xr = stoi(dim[0]);
		auto yr = stoi(dim[1]);
		ids.insert(id);
		for (int xi = x; xi < x + xr; xi++) {
			for (int yi = y; yi < y + yr; yi++) {
				if (matrix[xi][yi] == 0) matrix[xi][yi] = id;
				else {
					ids.erase(matrix[xi][yi]);
					ids.erase(id);
				}
			}
		}
		id++;
	}
	for (auto i : ids) {
		cout << i << endl;
	}
}

void partB3(vector<string> input) {

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

	partA3(input);
	//partB3(input);
	system("pause");
	return 0;
}