#pragma once

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

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <exception>
#include <sstream>
#include <iomanip>
using std::cout;
using std::cin;
using std::vector;
using std::array;
using std::string;
using std::find;
using std::exception;
using std::getline;
using std::ws;
using std::setprecision;
using std::defaultfloat;
using std::fixed;

// represents the page-turner book store system 
class PageTurner
{
public:

	PageTurner();

	// add a book with to the page-turner store system
	void addBook(string a, string t, int c, double p);

	// validate the staff entries for the number of copies
	void validateCopies(string& prompt, string& message, int& number);
	
	// validate the staff entries for the price of a single copy 
	void validatePrice(string& prompt, string& message, double& number);

	// vectors to store details on each of the books in the store's inventory
	// collection of authors
	vector<string> authors;
	// collection of titles
	vector<string> titles;
	// collection of copies of each unique title
	vector<int> counts;
	// colleciton of prices for a single copy of each unique title
	vector<double> prices;

};

// validate staff option input every time a new store operation is entered
void validateInput(string& prompt, int& number, int options);

// represents a customer's shopping cart
class Cart
{
public:

	Cart();

	// add desired book to shopping cart
	void addToCart(string a, string t, double p);

	// store customer details for billing purposes
	void addCustomerDetails(string* name, string* email, string* membership);

	// store the details of the books being purchased
	vector<string> authors; // collection of author names
	vector<string> titles; // collection of book titles 
	vector<double> prices; // collection of the price of a single copy of each of the books being purchased

	static const size_t arraySizeReceipt{ 3 }; // customer details for receipt info
	array<string, arraySizeReceipt> receipt{ "" }; // collecting receipt customer info
	
	// empty carts, remove all of it's contents 
	void emptyCart();

};
