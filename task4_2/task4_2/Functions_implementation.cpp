/*
*@file		Functions_implementation.cpp
*@brief		implements functions declared in file task4_2.h and used in file task4_2.cpp
*/
#include "stdafx.h"
#include "Const.h"
#include "task4_2.h"
#include "Stack.h"
#include <conio.h>
#include <iostream>
#include <string.h>

using std::cin;
using std::string;

void Interface(void)
{
	puts("------------------------------------------------------------------------");
	puts("Welcome to the genius calculator\".");
	puts("Enter expression and program will estimate it for you . ");
	puts("Please enter expression without spaces and put negative value into brackets. ");
	puts("Program made by Yuliia Lyubchik.");
	puts("------------------------------------------------------------------------\n");
}



unsigned char Checking(const string& expression)
{
	if (expression.length() == 0)
	{
		puts("There is no expression to check.");
		return ERROR;
	}
	unsigned char retCode;

	retCode = Brackets_check(expression);
	if (retCode == FAIL)
	{
		puts("Please check the brackets in expression.");
		return FAIL;
	}

	retCode = Is_number(expression);
	if (retCode == FAIL)
	{
		puts("Please check if you entered numbers properly.");
		return FAIL;
	}

	retCode = Check_signs(expression);
	if (retCode == FAIL)
	{
		puts("Please check the if you properly put arithmetic operations.\n");
		return FAIL;
	}
	return SUCCESS;
}


unsigned char Brackets_check(const string& expression)
{
	if (expression.length() == 0)
	{
		puts("There is no expression to check brackets.");
		return ERROR;
	}
	Stack<char> brackets;

	unsigned int i;
	char retCode;

	for (i = 0; i < expression.length(); ++i)
	{
		switch (expression[i])
		{
		case '(':
			brackets.Push('(');
			break;

		case ')':
			retCode = brackets.Pop();
			if (retCode != '(')
			{
				return FAIL;
			}
			break;
		}
	}

	if (!brackets.isEmpty())
	{
		return FAIL;
	}
	return SUCCESS;
}


unsigned char Is_number(const string& expression)
{
	if (expression.length() == 0)
	{
		puts("There is no expression to check.");
		return ERROR;
	}
	char* token;
	char* copy = new char[expression.length() + 1];
	if (copy == NULL)
	{
		puts("Error occurs while trying to allocate memory.");
		exit(ERROR);
	}
	strcpy(copy, expression.c_str());

	char delimiters[] = { '+', '-', '/', '*', '(', ')' };

	token = strtok(copy, delimiters);
	while (token != NULL)
	{
		unsigned int i;
		unsigned char krapka = 0;
		for (i = 0; i < strlen(token); ++i)
		{
			if (token[i] >= '0' && token[i] <= '9')
			{
				continue;
			}
			else if (token[i] == '.')
			{
				if (krapka == 0)
				{
					krapka = 1;
				}
				else
				{
					delete[] copy;
					return FAIL;
				}
			}
			else
			{
				delete[] copy;
				return FAIL;
			}
		}
		token = strtok(NULL, delimiters);
	}
	delete[] copy;
	return SUCCESS;
}


unsigned char Check_signs(const string& expression)
{
	if (expression.length() == 0)
	{
		puts("There is no expression to check.");
		return ERROR;
	}
	char* sign;
	char delimiters[] = { '+', '-', '/', '*' };
	unsigned int length = expression.length(), templen, i;
	char* copy = new char[expression.length() + 1];
	if (copy == NULL)
	{
		puts("Error occurs while trying to allocate memory.");
		exit(ERROR);
	}
	strcpy(copy, expression.c_str());

	sign = strpbrk(copy, delimiters);
	while (sign != NULL)
	{

		templen = strlen(sign);
		i = length - templen;

		if (i == 0)
		{
			delete[] copy;
			return FAIL;
		}

		if (expression[i - 1] < '0' || expression[i - 1] > '9')
		{
			if (expression[i - 1] != ')')
			{
				if (expression[i] == '-')
				{
					if (expression[i - 1] == '(')
					{
						/*NULL*/
					}
					else
					{
						delete[] copy;
						return FAIL;
					}
				}
				else
				{
					delete[] copy;
					return FAIL;
				}
			}
		}


		if (expression[i + 1] < '0' || expression[i + 1]>'9')
		{
			if (expression[i + 1] != '(')
			{
				delete[] copy;
				return FAIL;
			}
		}
		sign = strpbrk(sign + 1, delimiters);
	}
	delete[] copy;
	return SUCCESS;
}


unsigned char Convert_to_polish(const string& expr, string& polish_notation)
{
	if (expr.length() == 0)
	{
		puts("There is no expression to check.");
		return ERROR;
	}
	Stack<char> signs;
	char* polish = new char[2 * expr.length()];
	if (polish == NULL)
	{
		puts("Error occurs while trying to allocate memory.");
		exit(ERROR);
	}
	unsigned int n_expr = 0, n_polish = 0;
	do
	{
		if ((expr[n_expr] >= '0' && expr[n_expr] <= '9') || expr[n_expr] == '.')
		{
			do
			{
				polish[n_polish] = expr[n_expr];
				++n_expr, ++n_polish;
			} while ((expr[n_expr] >= '0' && expr[n_expr] <= '9') || expr[n_expr] == '.');

			polish[n_polish] = ' ';
			++n_polish;
		}

		if ((expr[n_expr] >= '(' && expr[n_expr] <= '+') || expr[n_expr] == '-' || expr[n_expr] == '/')
		{
			if (signs.isEmpty())
			{
				signs.Push(expr[n_expr]);
				++n_expr;
			}
			else
			{
				if (expr[n_expr] == '(')
				{
					signs.Push(expr[n_expr]);
					++n_expr;
				}
				else if (expr[n_expr] == ')')
				{
					char tempsign;
					tempsign = signs.Pop();
					while (tempsign != '(')
					{
						polish[n_polish] = tempsign;
						++n_polish;
						polish[n_polish] = ' ';
						++n_polish;
						tempsign = signs.Pop();
					}
					++n_expr;
				}
				else if (expr[n_expr] == '/' || expr[n_expr] == '*')
				{
					char tempsign;
					tempsign = signs.Peek();
					while (tempsign == '*' || tempsign == '/')
					{
						tempsign = signs.Pop();
						polish[n_polish] = tempsign;
						++n_polish;
						polish[n_polish] = ' ';
						++n_polish;
						tempsign = signs.Peek();
					}
					signs.Push(expr[n_expr]);
					++n_expr;
				}
				else if (expr[n_expr] == '+' || expr[n_expr] == '-')
				{
					if (expr[n_expr] == '-' && expr[n_expr - 1] == '(')
					{
						signs.Push(expr[n_expr]);
						polish[n_polish] = '0';
						++n_polish;
						polish[n_polish] = ' ';
						++n_polish;
						++n_expr;
						polish[n_polish] = expr[n_expr];
						++n_expr;
						++n_polish;
						polish[n_polish] = ' ';
						++n_polish;
					}
					else
					{
						char tempsign;
						tempsign = signs.Peek();
						while (tempsign != '(' && tempsign != ')')
						{
							tempsign = signs.Pop();
							polish[n_polish] = tempsign;
							++n_polish;
							polish[n_polish] = ' ';
							++n_polish;
							if (!signs.isEmpty())
							{
								tempsign = signs.Peek();
							}
							else
							{
								break;
							}
						}
						signs.Push(expr[n_expr]);
						++n_expr;
					}

				}

			}

		}
	} while (expr[n_expr] != '\0');
	while (!signs.isEmpty())
	{
		polish[n_polish] = signs.Pop();
		++n_polish;
		polish[n_polish] = ' ';
		++n_polish;
	}
 	polish[n_polish - 1] = '\0';
 	polish_notation.assign(polish);
	//cout << polish_notation << "\n";

	delete[] polish;
	return SUCCESS;
}


double Calculation(const std::string& polish)
{
	if (polish.length() == 0)
	{
		puts("There is no expression to check.");
		return ERROR;
	}

	char* copy = new char[polish.length() + 1];
	if (copy == NULL)
	{
		puts("Error occurs while trying to allocate memory.");
		exit(ERROR);
	}
	strcpy(copy, polish.c_str());
	char* token;
	Stack<double> numbers;
	double temp;

	token = strtok(copy, " ");
	while (token != NULL)
	{
		if (token[0] >= '0' && token[0] <= '9')
		{
			temp = atof(token);
			numbers.Push(temp);
		}
		else
		{
			if (!numbers.isEmpty())
			{
				double oper1, oper2;
				oper2 = numbers.Pop();
				oper1 = numbers.Pop();
				switch (token[0])
				{
				case '+':
					temp = oper1 + oper2;
					numbers.Push(temp);
					break;
				case '-':
					temp = oper1 - oper2;
					numbers.Push(temp);
					break;
				case '*':
					temp = oper1 * oper2;
					numbers.Push(temp);
					break;
				case '/':
					if (oper2 != 0)
					{
						temp = oper1 / oper2;
						numbers.Push(temp);
					}
					else
					{
						puts("You can't divide by zero.");
					}
					break;
				default:
					puts("Sorry, can't estimate the result. Unknown  operation.");
					delete[] copy;
					return FAIL;
					break;
				}
			}
			else
			{
				puts("Can't calculate the result.");
				delete[] copy;
				return ERROR;
			}
		}
		token = strtok(NULL, " ");
	}
	if (!numbers.isEmpty())
	{
		delete[] copy;
		return numbers.Pop();
	}
	else
	{
		puts("Fail to estimate.");
		delete[] copy;
		return FAIL;
	}
}
