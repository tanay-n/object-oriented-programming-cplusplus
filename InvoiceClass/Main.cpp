/*
Tanay Nagireddy
CIS 554 - M401 Object Oriented Programming in C++
Syracuse University
HW #1 - Exercise 3.10 p100
1 / 28 / 21
This program prints out an invoice for a particular
hardware store item and returns an error if the quantity
or price of the item is invalid.
*/

#include "Invoice.h"

int main()
{
	// build invoice for hardware store
	string number = "";
	string description = "";
	int quantity = 0;
	int price = 0;

	// setting up a blank invoice
	Invoice invoice(number, description, quantity, price);
	cout 
		<< "\n### Tanay Nagireddy's Hardware Store ###\n"
		<< "Enter a valid item number, description, quantity, and \n"
		<< "price to view the total cost of the item.\n";

	// customer makes a purchase request with item and description
	cout << "Item number: ";
	cin >> number;
	invoice.setNumber(number);

	cout << "Item description: ";
	cin >> description;
	invoice.setDescription(description);

	// validating bad entries in quantity and price
	if (invoice.inputQuantity() == -1)
	{
		return(-1);
	}
	invoice.setQuantity(invoice.getQuantity());
	
	if (invoice.inputPrice() == -1)
	{
		return(-1);
	}
	invoice.setPrice(invoice.getPrice());

	// printing the total amount the customer has to pay
	cout 
		<< "Total for " 
		<< description
		<< "#"
		<< number
		<< " is: $"
		<< invoice.getInvoiceAmount()
		<< ".00\n\n";
}	