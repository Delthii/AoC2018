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

void partA18(vector<string> input) {
	auto m2 = matrix(input.size()+2, input[0].size()+2, ' ');
	auto m1 = matrix(input.size()+2, input[0].size()+2, ' ');
	for (size_t i = 1; i <= input.size(); i++)
	{
		for (size_t j = 1; j <= input[0].size(); j++)
		{
			m1[i][j] = input[i-1][j-1];
		}
	}
	unordered_set<int> ans;
	unordered_map<int, int> map;
	for (int iterations = 1; iterations < 600; iterations++) {
		m2 = matrix(input.size()+2, input[0].size()+2, ' ');
		for (size_t i = 1; i <= input.size(); i++)
		{
			for (size_t j = 1; j <= input[0].size(); j++)
			{
				int acre = 0;
				int open = 0;
				int lumberyard = 0;
				for (int x = -1; x < 2; x++) {
					for (int y = -1; y < 2; y++) {
						if (!x && !y) continue;
						if (m1[i + x][j + y] == '|') acre++;
						if (m1[i + x][j + y] == '.') open++;
						if (m1[i + x][j + y] == '#') lumberyard++;
					}
				}
				switch (m1[i][j])
				{
				case '.':
					m2[i][j] = acre >= 3 ? '|' : '.';
					break;
				case '|':
					m2[i][j] = lumberyard >= 3 ? '#' : '|';
					break;
				case '#':
					m2[i][j] = lumberyard >= 1 && acre >= 1 ? '#' : '.';
					break;
				default:
					break;
				}
			}
		}
		m1 = m2;
		int acre = 0;
		int open = 0;
		int lumberyard = 0;
		for (size_t i = 1; i <= input.size()+1; i++)
		{
			for (size_t j = 1; j <= input[0].size()+1; j++)
			{
				switch (m1[i][j])
				{
				case '.':
					open++;
					break;
				case '|':
					acre++;
					break;
				case '#':
					lumberyard++;
					break;
				default:
					break;
				}
			}
		}
		if (iterations > 500) {
			if (ans.insert(lumberyard * acre).second) {
				map[iterations%28] = lumberyard * acre;
				cout << lumberyard * acre << "  " << iterations<< "   "<< iterations%28 << endl;
			}
		}
	}
	cout << map[(1000000000LL -504LL) % 28LL] << endl;
}



void partB18(vector<string> input) {
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
	partA18(input);
	sw.start();
	//partB5(input);
	sw.stop();
	cout << sw.duration() << endl;
	system("pause");
	return 0;
}