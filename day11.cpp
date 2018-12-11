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
	for (int size = 0; size <= 300; size++) {
		cout << size <<"  " << max << endl;
		for (int y = 0; y <= 300; y++) {
			for (int x = 0; x <= 300; x++) {
				int sum = 0;
				for (int i = 0; i <= size; i++) {
					if (sum == -99999999) break;
					for (int j = 0; j <= size; j++) {
						if (x + i < 0 || x + i > 300 || y + j < 0 || y + j > 300) {
							sum = -99999999;
							break;
						}
						sum += m[x + i][y + j];
					}
				}
				if (sum > max) {
					max = sum;
					cout << x << "," << y << "," << size+1 << endl;
				}
			}
		}
	}	
}

void partB11(vector<string> input) {

}

int main11() {
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
	//partA11(input);
	int sum[301][301];
	int bx, by, bs, best = INT_MIN;
	for (int y = 1; y <= 300; y++) {
		for (int x = 1; x <= 300; x++) {
			int p = powerlevel(x, y, 6878);
			sum[y][x] = p + sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
		}
	}
	for (int s = 1; s <= 300; s++) {
		for (int y = s; y <= 300; y++) {
			for (int x = s; x <= 300; x++) {
				int total = sum[y][x] - sum[y - s][x] - sum[y][x - s] + sum[y - s][x - s];
				if (total > best) {
					best = total, bx = x, by = y, bs = s;
				}
			}
		}
	}
	cout << bx - bs + 1 << "," << by - bs + 1 << "," << bs << endl;


	//partB11(input);
	sw.stop();
	cout << sw.duration() << endl;
	system("pause");
	return 0;
}