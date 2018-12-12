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
#include <cmath>
using namespace std;

void partA12(vector<string> input) {
	string initial = splitString(input[0], ": ")[1];
	unordered_map<string, bool> patterns;
	for (int i = 2; i < input.size(); i++) {
		auto ss = splitString(input[i], " => ");
		patterns[ss[0]] = ss[1][0] == '#';
	}
	initial = "........" + initial + "...........................................";
	int c = count(initial.begin(), initial.end(), '#');
	for (int s = 0; s < 20; s++) {
		string newState = string(initial);
		cout << newState << endl;
		for (int i = 0; i < initial.size() - 5; i++) {
			string substring = initial.substr(i, i + 5);
			for (auto &p : patterns) {
				if (p.first == substring) {
					newState[i + 2] = p.second ? '#' : '.';
				}
			}
		}
		initial = newState;
		c += count(initial.begin(), initial.end(), '#');
	}
	cout << c << endl;
}

void partB12(vector<string> input) {

}

long long L[21][21];
long long rec(int x, int y) {
	if (L[x][y] == 0) {
		if (x == 0 || y == 0) {
			L[x][y] = 1;
			L[y][x] = 1;
		}
		else {
			L[y][x] = L[x][y] = rec(x - 1, y) + rec(x, y - 1);
		}
	}
	return L[x][y];
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
	auto sw = Stopwatch();
	sw.start();
	partA12(input);
	//partB12(input);
	

	sw.stop();

	cout << sw.duration() << endl;
	system("pause");
	return 0;
}