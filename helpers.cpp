#include "Helpers.h"
#include <iostream>

using namespace std;

vector<string> splitString(string s, string delimiter)
{
	auto start = 0U;
	auto end = s.find(delimiter);
	auto results = vector<string>();
	while (end != string::npos)
	{
		results.push_back(s.substr(start, end - start));
		start = end + delimiter.length();
		end = s.find(delimiter, start);
	}

	results.push_back(s.substr(start, end));

	return results;
}

