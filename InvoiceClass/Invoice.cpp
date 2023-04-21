#include "Invoice.h"


Invoice::Invoice (string pn, string pd, int q, int p)
	: number { pn }, description{ pd }, quantity{ q }, price{ p }
{}

// retrieving values from the invoice
string Invoice::getNumber()
{
	return number;
}

string Invoice::getDescription()
{
	return description;
}

int Invoice::getQuantity()
{
	return quantity;
}

int Invoice::getPrice()
{
	return price;
}

// collecting input from user
int Invoice::inputQuantity()
{
	string q = "";

	cout << "Quantity of item: ";
	cin >> q;

	try
	{
		quantity = stoi(q);
	}
	catch (exception& e)
	{
		cout
			<< e.what()
			<< " for item quantity.\n"
			<< "Please re-enter invoice with valid quantity.\n";
		return(-1);
	}
	return(0);
}

int Invoice::inputPrice()
{
	string p = "";

	cout << "Price of item: ";
	cin >> p;

	try
	{
		price = stoi(p);
	}
	catch (exception& e)
	{
		cout
			<< e.what()
			<< " for item price.\n"
			<< "Please re-enter invoice with valid price.\n";
		return(-1);
	}
	return(0);
}

// assigning values to the invoice
void Invoice::setNumber(string pn)
{
	number = pn;
}

void Invoice::setDescription(string pd)
{
	description = pd;
}

void Invoice::setQuantity(int q)
{

	if (q < 0)
	{
		cout << "Quantity cannot be less than zero. Check item quantity.\n";
		quantity = 0;
	}
	else
	{
		quantity = q;
	}

}

void Invoice::setPrice(int p)
{
	if (p < 0)
	{
		cout << "Price cannot be less than zero. Check item price.\n";
		price = 0;
	}
	else
	{
		price = p;
	}

}

// computing the invoice
int Invoice::getInvoiceAmount()
{
	return quantity * price;
}