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

// setting up to begin storing entry values
Graph::Graph()
	: numbers()
{}

// retrieving stored values based on entry
int Graph::getNumbers(int pos)
{
	return numbers[pos];
}

// storing value entered
void Graph::setNumber(int pos, int num)
{
	numbers[pos] = num;
}

// collecting values for each entry
void Graph::inputNumbers(int start, int end)
{
	// collect entries from user one by one
	for (int i = start; i <= end; i++)
	{
		bool next = false;

		// repeatedly prompt user for input until
		// value integer is entered
		while (!next)
		{
			string input;

			// prompt user for integer
			cout 
				<< "Please enter a number between 1 and 30 (inclusive) #"
				<< i+1
				<< ": ";
			cin >> input;

			// attempt to store integer
			try
			{
				setNumber(i, stoi(input));

				int number = numbers[i];

				// check if entry is within bounds
				if (number < 1 || number > 30)
				{
					cout 
						<< "Number is out of bounds.\n"
						<< "Please try again.\n";
				}
				else
				{
					next = true;
				}
			}

			// display error message if entry is invalid
			catch (exception& e)
			{
				cout
					<< e.what()
					<< " for number.\n"
					<< "Please try again.\n";
			}
		}

	}
	
}