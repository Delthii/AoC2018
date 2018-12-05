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


void partA5(vector<string> input) {
	string in = input[0];
	string temp = string(in);
	int m = 100000;
	
	in = string(temp);
	for (int i = 0; i < in.length() - 1; i++) {
		if (abs(in[i] - in[i + 1]) == 32) {
			in.erase(i, 2);
			i -= 2;
			if (i < -1) i = -1;
		}
	}
	if (in.size()  < m) m = in.size();
	
	cout << m << endl;
}



void partB5(vector<string> input) {
	string in = input[0];
	string temp = string(in);
	int m = 100000;
	for (char c = 'a'; c <= 'z'; c++) {
		in = string(temp);
		in.erase(remove(in.begin(), in.end(), c), in.end());
		in.erase(remove(in.begin(), in.end(), c - 32), in.end());
		for (int i = 0; i < in.length() - 1; i++) {
			if (abs(in[i] - in[i + 1]) == 32) {
				in.erase(i, 2);
				i -= 2;
				if (i < -1) i = -1;
			}
		}
		if (in.size()  < m) m = in.size();
	}
	cout << m << endl;
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

	partA5(input);
	partB5(input);
	system("pause");
	return 0;
}