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


void partA10(vector<string> input) {
	
}



void partB10(vector<string> input) {
	
}

int main5() {
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
	partA10(input);
	
	//partB10(input);
	sw.stop();
	cout << sw.duration() << endl;
	system("pause");
	return 0;
}