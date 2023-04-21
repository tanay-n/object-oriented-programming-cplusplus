
/*
Tanay Nagireddy
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
HW #5 - "a real-world, meaningful program, and
show me how creative you can be in this 'Student Challenge'"
3/3/21

This program manages the operations of a small bookshop by
allowing staff to add books to the store's inventory, add books
for purchase by a customer using a cart system, and finally, print
a receipt with the total amount payable by the customer.
*/

#include "PageTurner.h"

// validates the option entered by staff for store operation
void validateInput
(
	string& prompt, // passing prompt to display
	int& number, // passing number to store the user input
	int options // passing number of options available to select
)
{
	bool next = false; // setting condition to exit while loop

	// repeatedly prompt user for a book shop system action until 
	// a valid integer is entered
	while (!next)
	{
		string input = ""; // set up to collect user input

		cout << prompt; // displaying prompt
		cin >> input; // collecting user input

		// attempt to store integer
		try
		{

			number = stoi(input); // attempting to store user input

			// check if entry is within bounds of the options available
			if (number < 1 || number > options)
			{
				cout
					<< "Setting is out of bounds.\n"
					<< "Please try again.\n";
			}
			else
			{
				next = true; // exit loop and store setting option from user input
			}
		}

		// display error message if user entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what() // display error message from stoi function
				<< " for setting.\n"
				<< "Please try again.\n";
		}
	}
}

// set up book shop class
PageTurner::PageTurner() {}


// validate the number of copies of the book being entered by staff
void PageTurner::validateCopies
(
	string& prompt, // passing prompt to display
	string& message, // message to display if there is an error
	int& number // passing number to store the user input
)
{
	bool next = false; // setting condition to exit while loop

	// repeatedly prompt user for a book shop system action until
	// a valid integer is entered
	while (!next)
	{
		string input = ""; // set up to collect user input
		
		cout << prompt; // displaying prompt
		cin >> input; // collecting user input

		// attempt to store integer
		try
		{
			number = stoi(input); // attempting to store staff input

			// check if entry is within bounds of the min and max number of copies allowed
			if (number < 1 || number > 100)
			{
				cout
					<< message << "\n"
					<< "Please check entry and try again.\n";
			}
			else
			{
				next = true; // exit loop and store number of copies from staff input
			}
		}

		// display error message if user entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what() // display error message from stoi function
				<< message << "\n"
				<< "Please check entry and try again.\n";
		}
	}
}

// validate the price of a single copy of the book being entered by staff
void PageTurner::validatePrice
(
	string& prompt, // passing prompt to display
	string& message, // message to display if there is an error
	double& number // passing number to store the user input
)
{
	bool next = false; // setting condition to exit while loop

	// repeatedly prompt user for a book shop system action until
	// a valid integer is entered
	while (!next)
	{
		string input = ""; // set up to collect user input

		cout << prompt; // displaying prompt
		cin >> input; // collecting user input

		// attempt to store integer
		try
		{
			number = stod(input); // attempting to store staff input

			// check if entry is within bounds of the min and max prices
			if (number < 0 || number > 1000.00)
			{
				cout
					<< message << "\n"
					<< "Please check entry and try again.\n";
			}
			else
			{
				next = true; // exit loop and store price from staff input
			}
		}

		// display error message if user entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what() // display error message from stod function
				<< message << "\n"
				<< "Please check entry and try again.\n";
		}
	}
}

// add a book to the book shop database
void PageTurner::addBook(string a, string t, int c, double p)
{
	authors.push_back(a); // add author of book
	titles.push_back(t); // add title of book
	counts.push_back(c); // add copies of book
	prices.push_back(p); // add price of a single copy
}

// set the initial cart total amount to zero
Cart::Cart() {}

// add items to cart
void Cart::addToCart(string a, string t, double p)
{
	authors.push_back(a); // add author of book
	titles.push_back(t); // add title of book
	prices.push_back(p); // add price of a single copy
}

// store customer details
void Cart::addCustomerDetails(string* name, string* email, string* membership)
{
	receipt[0] = *name; // store name of customer
	receipt[1] = *email; // store email of customer
	receipt[2] = *membership; // store membership ID of customer
}

// empty all contents in the cart
void Cart::emptyCart()
{
	authors.clear(); // removes all author names currently in the cart
	titles.clear(); // removes all title names currently in the cart
	prices.clear(); // removes all prices currently in the cart
}