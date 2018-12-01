#pragma once
#include <chrono>
using namespace std;
class Stopwatch
{
public:
	Stopwatch();
	~Stopwatch();
	void start();
	void stop();
	double duration();
private:
	chrono::time_point<chrono::steady_clock> begin;
	chrono::time_point<chrono::steady_clock> end;
};

