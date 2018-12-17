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

/*

auto addr(int a, int b, int c, int d, vector<int> registers) {


}

auto addi(int a, int b, int c, int d, vector<int> registers) {


}

auto mulr(int a, int b, int c, int d, vector<int> registers) {


}

auto muli(int a, int b, int c, int d, vector<int> registers) {


}

auto banr(int a, int b, int c, int d, vector<int> registers) {


}

auto bani(int a, int b, int c, int d, vector<int> registers) {


}

auto borr(int a, int b, int c, int d, vector<int> registers) {


}

auto bori(int a, int b, int c, int d, vector<int> registers) {


}

auto setr(int a, int b, int c, int d, vector<int> registers) {


}

auto seti(int a, int b, int c, int d, vector<int> registers) {


}

auto gtir(int a, int b, int c, int d, vector<int> registers) {


}

auto gtri(int a, int b, int c, int d, vector<int> registers) {


}

auto gtrr(int a, int b, int c, int d, vector<int> registers) {


}

auto eqir(int a, int b, int c, int d, vector<int> registers) {


}

auto eqri(int a, int b, int c, int d, vector<int> registers) {


}

auto eqrr(int a, int b, int c, int d, vector<int> registers) {


}


void part16A(vector<string> input) {

}

void part16B(vector<string> input) {


}
 */
int main16() {
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

	//part16A(in);
	//part16B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}
