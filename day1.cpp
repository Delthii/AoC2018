#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include "Helpers.h"
using namespace std;


int main() {
	string line;
	
	bool found = false;
	int res = 0;
	auto m = unordered_set<int>();
	auto numbers = vector<int>();
	ifstream myfile("in.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			numbers.push_back(stoi(line));
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	while (!found) {
		for (auto i : numbers) {
			res += i;
			if (m.find(res) == m.end()) m.insert(res);
			else {
				found = true;
				break;
			}
		}
	}

	cout << res;
	system("pause");
	return 0;
}