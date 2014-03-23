
#pragma once

class Stack_double
{
public:
	Stack_double();
	~Stack_double();

	bool isEmptyd();
	void Pushd(double element);
	double Popd();
	double Topd();

private:
	unsigned int size;
	double* dstack;
};

