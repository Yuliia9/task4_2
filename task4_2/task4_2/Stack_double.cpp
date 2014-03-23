#include "stdafx.h"
#include "Stack_double.h"
#include "Const.h"
#include <stdio.h>

#include <iostream>
using std::copy;


Stack_double::Stack_double()
:size(0)
, dstack(NULL)
{
}


Stack_double::~Stack_double()
{
	delete(dstack);
}


bool Stack_double::isEmptyd()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack_double::Pushd(double element)
{
	++size;
	double* new_stackd = new double[size];
/*	memcpy(new_stackd, dstack, size - 1);*/
	for (int i = 0; i < size - 1; ++i)
	{
		new_stackd[i] = dstack[i];
	}
 	delete(dstack);
 	dstack = new_stackd;
	dstack[size - 1] = element;
}

double Stack_double::Popd()
{
	//assert(size);
	if (isEmptyd())
	{
		return ERROR;
	}
	double top = dstack[size - 1];
	--size;
	double* new_stackd = new double[size];
	for (int i = 0; i < size; ++i)
	{
		new_stackd[i] = dstack[i];
	}
	delete(dstack);
	dstack = new_stackd;

	return top;
}

double Stack_double::Topd()
{
	return dstack[size - 1];
}

