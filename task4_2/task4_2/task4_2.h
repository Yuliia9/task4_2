/*
*@file		task4_2.h
*@brief		header file that defines prototypes of functions used in file task4_2.cpp
*/

#include "stdafx.h"


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);

/*
* @brief					Function for checking if expression entered properly 
							(entered only numbers, putted properly brackets and operation signs)
* @param	[in]			const std::string& expression - a reference to inputed expression
*
*@return	unsigned char	Return ERROR if expression is empty
							Return SUCCESS if expression  meets requirements
							Return FAIL if expression has some mistakes
*/
unsigned char Checking(const std::string& expression);

/*
* @brief					Function for checking if brackets in expression seated properly
* @param	[in]			const std::string& expression - a reference to inputed expression
*
*@return	unsigned char	Return ERROR if expression is empty
							Return SUCCESS if brackets seated properly in expression  
							Return FAIL if expression has some mistakes
*/
unsigned char Brackets_check(const std::string& expression);

/*
* @brief					Function for checking if in expression operands are only numbers
* @param	[in]			const std::string& expression - a reference to inputed expression
*
*@return	unsigned char	Return ERROR if expression is empty or error occurs while trying to allocate memory
							Return SUCCESS if expression consist only of numbers
							Return FAIL if expression has some mistakes
*/
unsigned char Is_number(const std::string& expression);

/*
* @brief					Function for checking if operation signs in expression are only "+*-/"
* @param	[in]			const std::string& expression - a reference to inputed expression
*
*@return	unsigned char	Return ERROR if expression is empty or error occurs while trying to allocate memory
							Return SUCCESS if operation signs are correct
							Return FAIL if expression has some mistakes
*/
unsigned char Check_signs(const std::string& expression);

/*
* @brief					Function for converting expression into reverse polish notation
* @param	[in]			const std::string& expression - a reference to inputed expression
			[in/out]		std::string& expression - a reference to obtained reverse polish notation
*@return	unsigned char	Return ERROR if expression is empty or error occurs while trying to allocate memory
							Return SUCCESS if operation signs are correct
							Return FAIL if expression has some mistakes
*/
unsigned char Convert_to_polish(const std::string& expr, std::string& polish);


/*
* @brief					Function for estimation the result of expression
* @param	[in]			const std::string& expression - a reference to inputed expression
*
*@return	unsigned char	Return ERROR if expression is empty or error occurs while trying to allocate memory
							Otherwise return result of expression
*/
double Calculation(const std::string& polish);