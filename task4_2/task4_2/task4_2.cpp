/*
* @file			task4_2.cpp
* @brief		Program estimates the result of inputed expression

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/
#include "stdafx.h"
#include "Const.h"
#include "task4_2.h"
#include <iostream>
#include <string.h>


using std::cin;
using std::cout;
using std::string;

int main(void)
{
	Interface();

	unsigned char retCode;
	string expression, polish_notation;
	double result;
	do 
	{
		do 
		{ 		
			printf("Enter expression: ");
			cin >> expression;
			if (cin.fail())
			{
				cin.clear();
				expression.clear();
			}
		} 
		while (expression.empty());

		retCode = Checking(expression);
		if (retCode == FAIL)
		{
			puts("Try again!.");
		}
	} 
	while (retCode == FAIL);
	
	retCode = Convert_to_polish(expression, polish_notation);
	if (retCode == FAIL)
	{
		puts("Fail to convert string to do the calculation.");
		return ERROR;
	}

	result = Calculation(polish_notation);
	printf("Result: %lf. \n", result);
	

	system("pause");
	return MAIN_SUCCESS;
}


