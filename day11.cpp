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
/*
6878
*/

int powerlevel(int x, int y, int snr) {
	int rack = (x + 10);
	int cell = (rack*y + snr)*rack;
	string c = to_string(cell);
	cell = c.size() > 2 ? c[c.size() - 3]- '0' : 0;
	cell -= 5;
	return cell;
}

void partA11(vector<string> input) {
	auto m = matrix(301, 301, 0);
	for (int y = 1; y <= 300; y++) {
		for (int x = 1; x <= 300; x++) {
			m[x][y] = powerlevel(x, y, 6878);
		}
	}
	int max = 0;
	for (int y = 2; y < 300; y++) {
		for (int x = 2; x < 300; x++) {
			int sum = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					sum += m[x + i][y + j];
				}
			}
			if (sum > max) {
				max = sum;
				cout << x-1 << "," << y-1 << endl;
			}
		}
	}
}



void partB11(vector<string> input) {

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
	partA11(input);

	//partB11(input);
	sw.stop();
	cout << sw.duration() << endl;
	system("pause");
	return 0;
}