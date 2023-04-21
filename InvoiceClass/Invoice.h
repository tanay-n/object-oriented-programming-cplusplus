#pragma once

#include <iostream>
#include <string>
#include <exception>
using std::cout;
using std::cin;
using std::string;
using std::stoi;
using std::exception;


/*
Invoice for Lucifer's Hardware Store

The invoice can be run on every individual item in the
store. The inputQuantity and inputPrice member functions
perform additional validation to handle user error. After 
the details of a single item are entered, the total amount
(quantity x price) is returned.
*/

class Invoice
{
public:

	// setting blank default values for invoice parameters
	Invoice(string pn = "", string pd = "", int q = 0, int p = 0);
	
	// retrieving values from the invoice
	string getNumber();
	string getDescription();
	int getQuantity();
	int getPrice();

	// collecting input from user
	int inputQuantity();
	int inputPrice();

	// assigning values to the invoice
	void setNumber(string pn);
	void setDescription(string pd);
	void setQuantity(int q);
	void setPrice(int p);

	// calculate the total invoice amount
	int getInvoiceAmount();

private:

	// invoice values to be entered by the user
	string number;
	string description;
	int quantity;
	int price;
};