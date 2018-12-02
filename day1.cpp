#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include "Helpers.h"
#include "stopwatch.h"
using namespace std;


int main1() {
	auto sw = Stopwatch();
	sw.start();
	
	string line;
	
	bool found = false;
	int res = 0;
	auto m = unordered_set<int>(150000);
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
			if (!m.insert(res).second) {
				found = true;
				break;
			}
		}
	}

	cout << res <<endl;

	sw.stop();

	cout << "It took " << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}