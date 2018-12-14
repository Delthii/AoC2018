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

bool matchIt(short int seq[], vector<short int> &recipes) {
	int k = 1;
	for (size_t j = recipes.size() - 2; k < 6; j--) {
		if (recipes[j] != seq[k++]) {
			return false;
		}
	}
	return true;
}

void part14A(vector<string> input) {
	short int seq[6] = { 1,9,6,0,9,8 };
	vector<short int> recipes = vector<short int>({ 3,7 });
	int elf1 = 0;
	int elf2 = 1;
	bool match = false;
	for (; !match;) {
		string n = to_string(recipes[elf1] + recipes[elf2]);
		recipes.push_back(n[0]-'0');
		if (recipes.back() == seq[0]) match = matchIt(seq, recipes);
		if (match) break;
		if (n.size() > 1) recipes.push_back(n[1] - '0');
		elf1 += recipes[elf1] + 1;
		elf1 %= recipes.size();
		elf2 += recipes[elf2] + 1;
		elf2 %= recipes.size();
		if (recipes.back() == seq[0]) match = matchIt(seq, recipes);
	}
	cout << recipes.size() - 6LL << endl;
}

void part14B(vector<string> input) {
	
	
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

	auto sw = Stopwatch();
	sw.start();

	part14A(in);
	//part14B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}