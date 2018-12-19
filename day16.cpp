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
Before: [2, 1, 1, 0]
5 1 0 1
After:  [2, 0, 1, 0]

Before: [3, 0, 3, 3]
13 0 3 1
After:  [3, 1, 3, 3]
*//*
auto addr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] + reg[instruction[2]];
	return reg;
}

auto addi(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] + instruction[2];
	return reg;
}

auto mulr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] * reg[instruction[2]];
	return reg;
}

auto muli(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] * instruction[2];
	return reg;
}

auto banr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] & reg[instruction[2]];
	return reg;
}

auto bani(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] & instruction[2];
	return reg;
}

auto borr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] | reg[instruction[2]];
	return reg;
}

auto bori(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] | instruction[2];
	return reg;
}

auto setr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]];
	return reg;
}

auto seti(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = instruction[1];
	return reg;
}

auto gtir(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = instruction[1] > reg[instruction[2]];
	return reg;
}

auto gtri(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] > instruction[2];
	return reg;
}

auto gtrr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] > reg[instruction[2]];
	return reg;
}

auto eqir(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = instruction[1] == reg[instruction[2]];
	return reg;
}

auto eqri(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] == instruction[2];
	return reg;
}

auto eqrr(vector<int> reg, vector<int> instruction) {
	reg[instruction[3]] = reg[instruction[1]] == reg[instruction[2]];
	return reg;
} 

void part16A(vector<string> input) {
	vector<vector<int>> allBefore;
	vector<vector<int>> allAfter;
	vector<vector<int>> allInstruction;
	vector<vector<int>> testprogram;
	for (auto& r : input) {
		if (r.size() <= 1) continue;
		vector<int> before;
		vector<int> after;
		vector<int> instruction;
		if (allAfter.size() == 806) {
			auto ss = splitString(r, " ");
			for (auto &i : ss) {
				instruction.push_back(stoi(i));
			}
			testprogram.push_back(instruction);
			continue;
		}
		if (r[0] == 'B') {
			auto ss = splitString(r, "[")[1];
			ss = ss.substr(0, ss.size() - 1);
			auto rb = splitString(ss, ", ");
			for (auto &e : rb) {
				before.push_back(stoi(e));
			}
			allBefore.push_back(before);
		}
		else if (r[0] == 'A') {
			auto ss = splitString(r, "[")[1];
			ss = ss.substr(0, ss.size() - 1);
			auto ra = splitString(ss, ", ");
			for (auto &e : ra) {
				after.push_back(stoi(e));
			}
			allAfter.push_back(after);
		}
		else {
			auto ss = splitString(r, " ");
			for (auto &i : ss) {
				instruction.push_back(stoi(i));
			}
			allInstruction.push_back(instruction);
		}
	}
	int ans = 0;
	unordered_map<int, unordered_set<string>> opcodes;

	for (size_t i = 0; i < allBefore.size(); i++) {
		auto b = allBefore[i];
		auto a = allAfter[i];
		auto in = allInstruction[i];
		bool count = 0;
		if (a == addr(b, in)) opcodes[in[0]].insert("addr");
		if (a == addi(b, in)) opcodes[in[0]].insert("addi");
		if (a == mulr(b, in)) opcodes[in[0]].insert("mulr");
		if (a == muli(b, in)) opcodes[in[0]].insert("muli");
		if (a == banr(b, in)) opcodes[in[0]].insert("banr");
		if (a == bani(b, in)) opcodes[in[0]].insert("bani");
		if (a == borr(b, in)) opcodes[in[0]].insert("borr");
		if (a == bori(b, in)) opcodes[in[0]].insert("bori");
		if (a == setr(b, in)) opcodes[in[0]].insert("setr");
		if (a == seti(b, in)) opcodes[in[0]].insert("seti");
		if (a == gtri(b, in)) opcodes[in[0]].insert("gtri");
		if (a == gtrr(b, in)) opcodes[in[0]].insert("gtrr");
		if (a == gtir(b, in)) opcodes[in[0]].insert("gtir");
		if (a == eqir(b, in)) opcodes[in[0]].insert("eqir");
		if (a == eqri(b, in)) opcodes[in[0]].insert("eqri");
		if (a == eqrr(b, in)) opcodes[in[0]].insert("eqrr");
	}
	unordered_map<int, string> mapping;
	while (mapping.size() < 16) {
		for (auto &c : opcodes) {
			if (c.second.size() == 1) {
				mapping[c.first] = *c.second.begin();
				for (auto &t : opcodes) {
					if (t.second.find(mapping[c.first]) != t.second.end()) {
						t.second.erase(t.second.find(mapping[c.first]));
					}
				}
				break;
			}
		}
	}
	vector<int> regis = vector<int>({0,0,0,0});
	for (auto &i : testprogram) {
		string op = mapping[i[0]];
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
		else {
			cout << "lol";
		}
	}
	cout << regis[0] << endl;
}

void part16B(vector<string> input) {


}
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

	part16A(in);
	//part16B(in);
	sw.stop();
	cout << sw.duration() << " seconds" << endl;
	system("pause");
	return 0;
}*/
