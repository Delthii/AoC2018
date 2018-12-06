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


void partA6(vector<string> input) {
	auto m = matrix(3000, 3000, -1);
	auto co = unordered_map<int,pair<int, int>>();
	int i = 0;
	for (auto s : input) {
		auto ss = splitString(s, ", ");
		int x = stoi(ss[0]), y = stoi(ss[1]);
		co[i] = pair<int, int>(x, y);
		m[x][y] = i;
		i++;
	}
	
	auto finit = unordered_set<int>();
	auto occ = unordered_map<int, int>();
	for (int layer = 1; layer < 400; layer++) {
		for (auto p : co) {
			bool changed = false;
			for (int xx = -layer; xx <= layer; xx++) {
				for (int yy = -layer; yy <= layer; yy++) {
					int x = p.second.first;
					int y = p.second.second;
					if (m[x + xx+1000][y + yy+1000] < 0) {
						m[x + xx+1000][y + yy+1000] = p.first;
						changed = true;
						occ[p.first]++;
					}						
				}
			}
			if (!changed) { 
				finit.insert(p.first);
			}
			else {
				cout << p.first << endl;
			}
		}
	}
	

}



void partB6(vector<string> input) {
	
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

	partA6(input);

	//partB6(input);
	system("pause");
	return 0;
}