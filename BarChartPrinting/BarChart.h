#pragma once

/*
Tanay Nagireddy
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
HW #3 - Exercise 5.16 p206 Bar-Chart Printing Program
2/11/21
This program reads five numbers provided by the user, and
once all five numbers collected are validated to be integers
between 1 and 30 inclusive, the program will display a bar chart
with each entry and it's corresponding value in asterisks.
*/

#include "BarChart.h"
#include <iostream>
#include <string>
#include <exception>
#include <array>
#include <iomanip>
using std::stoi;
using std::cout;
using std::cin;
using std::string;
using std::exception;
using std::array;
using std::setw;
using std::left;
using std::right;

/*
The following represents a graph that displays the
entries and their corresponding values as asterisks.
*/

class Graph
{
public:

	// setting up to store entry values
	Graph();

	// retrieving stored values based on entry
	int getNumbers(int pos);

	// collecting values for each entry
	void inputNumbers(int start, int end);

	// storing value entered
	void setNumber(int pos, int num);

private:
	
	// stored values for each of the five entries
	static const size_t arraySize{ 5 };
	array<int, arraySize> numbers{ 0 };

};