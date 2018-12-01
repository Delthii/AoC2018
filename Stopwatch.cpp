#include "Stopwatch.h"

Stopwatch::Stopwatch()
{
}


Stopwatch::~Stopwatch()
{
}

void Stopwatch::start()
{
	begin = chrono::high_resolution_clock::now();
	
}

void Stopwatch::stop()
{
	end = chrono::high_resolution_clock::now();
}

double Stopwatch::duration()
{
	return chrono::duration_cast<chrono::duration<double>>(end - begin).count();
}
