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
	bool fabric[1000][1000];
	for (auto s : input) {
		auto ss = splitString(s, " ");
		auto dim = splitString(ss[3], "x");
		auto pos = splitString(ss[2], ",");
		auto x = stoi(pos[0]);
		auto y = stoi(pos[1]);
		auto xr = stoi(dim[0]);
		auto yr = stoi(dim[1]);


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
	return 0;
}