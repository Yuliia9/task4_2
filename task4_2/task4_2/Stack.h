/*
*@file		Stack.h
*@brief		describes and implements class stack for storing data
*/
#include "Const.h"

template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	bool isEmpty(void);
	void Push(T element);
	T Pop(void);
	T Peek(void);

private:
	struct data
	{
		T element;
		data* prev;
	};
	data* stack;
};


/***************************IMPLEMENTATION**************************/


template <class T>
Stack<T>::Stack()
:stack(NULL)
{
}

template <class T>
Stack<T>::~Stack()
{
	while (stack != NULL)
	{
		data* current = stack;
		stack = stack->prev;
		delete current;
	}
}


/**
* @brief				This function checks if stack is empty
* @param	void
* @return	bool		Return true if stack is empty, otherwise return false
*/
template <class T>
bool Stack<T>::isEmpty(void)
{
	if (stack == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
* @brief				Function put the element into stack
* @param	char		Element you want to push into stack
* @return	void
*/
template <class T>
void Stack<T>::Push(T el)
{
	data* new_stack = new data;
	if (new_stack == NULL)
	{
		puts("Error occurs while trying to allocate memory.");
		exit(ERROR);
	}
	new_stack->element = el;
	new_stack->prev = stack;
	stack = new_stack;
}


/**
* @brief				This function returns element that is on the top of stack and decrease the size of stack on 1
* @param	void		
* @return	char		Returns ERROR if stack is empty
						Otherwise: returns the element that is on the top of stack
*/
template <class T>
T Stack<T>::Pop(void)
{
	if (isEmpty())
	{
		return ERROR;
	}
	T top = stack->element;
	data* new_stack = new data;
	if (new_stack == NULL)
	{
		puts("Error occurs while trying to allocate memory.");
		exit(ERROR);
	}
	new_stack = stack->prev;
	stack = new_stack;
	return top;
}

/**
* @brief				This function returns element that is on the top of stack 
						and do nothing with the size of stack
* @param	void		
* @return	char		Returns NULL if stack is empty
						Otherwise: returns the element that is on the top of stack
*/
template <class T>
T Stack<T>::Peek(void)
{
	if (stack == NULL)
	{
		puts("Stack is empty.");
		return NULL;
	}
	else
	{
		return stack->element;
	}
}

