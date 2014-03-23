#include "stdafx.h"
#include "Stack.h"
#include "Const.h"


Stack::Stack()
:size(0)
, stack(NULL)
{
}


Stack::~Stack()
{
	delete(stack);
}


bool Stack::isEmpty()
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

void Stack::Push(char element)
{
	++size;
	char* new_stack = new char[size];
	memcpy(new_stack, stack, size - 1);
	delete(stack);
	stack = new_stack;
	stack[size - 1] = element;
}

char Stack::Pop()
{
	//assert(size);
	if (isEmpty())
	{
		return ERROR;
	}
	char top = stack[size - 1];
	--size;
	char* new_stack = new char[size];
	memcpy(new_stack, stack, size);
	delete(stack);
	stack = new_stack;

	return top;
}

char Stack::Top()
{
	return stack[size - 1];
}

