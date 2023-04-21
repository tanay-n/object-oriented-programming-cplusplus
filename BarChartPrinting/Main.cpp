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

int main()
{
	// the entry/number labels
	int const start = 0;
	int const end = 4;

	// prompt user for an integer value
	cout
		<< "Please enter five numbers between 1 and\n"
		<< "30 (inclusive) to have the application display\n"
		<< "a bar-chart of the numbers entered.\n\n";

	Graph graph; // set up an empty graph

	// collect values for each entry
	graph.inputNumbers(start, end);

	// display bar graph headers
	cout
		<< "\n"
		<< right
		<< setw(9)
		<< "Numbers";
	cout
		<< left
		<< " Bars\n";

	// display each collected entry one by one
	for (int i = start; i <= end; i++)
	{
		// set column width for entry labels
		cout
			<< right
			<< setw(7)
			<< "#"
			<< i + 1
			<< ": ";
		cout
			<< right;

		// display the entry value in asterisks for each entry label
		for (int ast = 1; ast <= graph.getNumbers(i); ast++)
		{
			cout << "*";
		}

		// display the total number of asterisks for that entry
		// at the end of the bar
		cout
			<< " ("
			<< graph.getNumbers(i)
			<< ")\n";
	}

	// display complete message
	cout 
		<< left
		<< "\n---END---\n";
}