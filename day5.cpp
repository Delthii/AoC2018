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
	for (int i = 0; i <= in.length(); i++) {
		if (abs(in[i] - in[i + 1]) == 32) {
			in.erase(i, 2);
			i--;
			i--;
		}
	}
	cout << in.size() << endl;
}



void partB5(vector<string> input) {
	
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
	//partB4(input);
	system("pause");
	return 0;
}