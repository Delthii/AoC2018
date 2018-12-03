#pragma once
#include <vector>
using namespace std;


vector<string> splitString(string delimiter, string);

template<class T>
T ** matrix(int x, int y, T f)
{
	T ** m = new T*[x];
	for (int i = 0; i < x; i++) {
		m[i] = new T[y];
		fill(m[i], m[i] + y, f);
	}
	return m;
}

