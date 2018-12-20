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
auto addr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] + reg[instruction[2]];
	return reg;
}

auto addi(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] + instruction[2];
	return reg;
}

auto mulr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] * reg[instruction[2]];
	return reg;
}

auto muli(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] * instruction[2];
	return reg;
}

auto banr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] & reg[instruction[2]];
	return reg;
}

auto bani(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] & instruction[2];
	return reg;
}

auto borr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] | reg[instruction[2]];
	return reg;
}

auto bori(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] | instruction[2];
	return reg;
}

auto setr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]];
	return reg;
}

auto seti(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = instruction[1];
	return reg;
}

auto gtir(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = instruction[1] > reg[instruction[2]];
	return reg;
}

auto gtri(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] > instruction[2];
	return reg;
}

auto gtrr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] > reg[instruction[2]];
	return reg;
}

auto eqir(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = instruction[1] == reg[instruction[2]];
	return reg;
}

auto eqri(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] == instruction[2];
	return reg;
}

auto eqrr(vector<long long> reg, vector<long long> instruction) {
	reg[instruction[3]] = reg[instruction[1]] == reg[instruction[2]];
	return reg;
} 

void part19A(vector<string> input) {
	vector<vector<string>> testprogram;
	for (auto& r : input) {
		vector<string> instruction;
		auto ss = splitString(r, " ");
		for (auto &i : ss) {
			instruction.push_back(i);
		}
		testprogram.push_back(instruction);
	}
	long long c = 0;
	vector<long long> regis = vector<long long>({ 0,0,0,0,0,0 });
//	int a, b, c;
	while (regis[1] < testprogram.size()) {

		auto ins = testprogram[regis[1]];
		string op = ins[0];
		vector<long long> i = vector<long long>({ 0,stoi(ins[1]), stoi(ins[2]), stoi(ins[3]) });
		if (op == "addr") {
			regis = addr(regis, i);
		}
		else if (op == "addi") {
			regis = addi(regis, i);
		}
		else if (op == "mulr") {
			regis = mulr(regis, i);
		}
		else if (op == "muli") {
			regis = muli(regis, i);
		}
		else if (op == "banr") {
			regis = banr(regis, i);
		}
		else if (op == "bani") {
			regis = bani(regis, i);
		}
		else if (op == "borr") {
			regis = borr(regis, i);
		}
		else if (op == "bori") {
			regis = bori(regis, i);
		}
		else if (op == "setr") {
			regis = setr(regis, i);
		}
		else if (op == "seti") {
			regis = seti(regis, i);
		}
		else if (op == "gtri") {
			regis = gtri(regis, i);
		}
		else if (op == "gtir") {
			regis = gtir(regis, i);
		}
		else if (op == "gtrr") {
			regis = gtrr(regis, i);
		}
		else if (op == "eqri") {
			regis = eqri(regis, i);
		}
		else if (op == "eqir") {
			regis = eqir(regis, i);
		}
		else if (op == "eqrr") {
			regis = eqrr(regis, i);
		}
		regis[1]++;
	}
	cout << regis[0] << endl;
}

void part16B(vector<string> input) {
	long long a = 0; int b = 0;
	for (int j = 1; j <= 10551296; j++) {
		if (10551296%j == 0) {
			a += j;
			cout << a << endl;
		}
	}
}
 int main19() {
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

	part19A(in);
	//part19B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}
