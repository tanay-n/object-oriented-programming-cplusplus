/*
Tanay Nagireddy
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
HW #2 - Exercise 4.14 p150-151
2/11/21
This program takes in a customer's credit account details such
as outstanding balance, pending charges, applicable credits,
credit limits, and account number to either update the customer's
balance or print an alert stating that the account is delinquent.
*/

#include "CreditLimit.h"

Customer::Customer(int an, double b, double ch, double cr, double l)
	: account_number{ an }, balance{ b }, charge{ ch }, credit{ cr }, limit{ l }
{}


// retrieving customer values

int Customer::getAccountNumber()
{
	return account_number;
}

double Customer::getBalance()
{
	return balance;
}

double Customer::getCharge()
{
	return charge;
}

double Customer::getCredit()
{
	return credit;
}

double Customer::getLimit()
{
	return limit;
}


// assigning customer values

void Customer::setAccountNumber(int x)
{
	account_number = x;
}

void Customer::setBalance(double x)
{
	balance = x;
}

void Customer::setCharge(double x)
{
	charge = x;
}

void Customer::setCredit(double x)
{
	credit = x;
}

void Customer::setLimit(double x)
{
	limit = x;
}


// calculating and assinging the customer's new balance

void Customer::calculateBalance()
{
	balance = (balance + charge) - credit;	
}


// collecting customer account number
void Customer::inputAccountNumber()
{
	bool check = false;

	// repeatedly prompt user for account number
	// until valid entry is entered
	while (check == false)
	{
		string input;

		// prompt user for account number
		cout << "Enter account number (or -1 to quit): ";
		cin >> input;

		// attempt to store account number entry
		try
		{
			setAccountNumber(stoi(input));
			check = true;
		}
		
		// display error message if entry is invalid
		catch (exception& e)
		{
			cout 
				<< e.what()
				<< " for account number."
				<< "Please re-enter valid acount number.\n";
		}

	}

}


// collecting customer account balance
void Customer::inputBalance()
{
	bool check = false;

	// repeatedly prompt user for beginning account
	// balance until valid entry is entered
	while (check == false)
	{
		string input;

		// prompt user for beginning account balance
		cout << "Enter beginning balance: ";
		cin >> input;

		// attempt to store account balance entry
		try
		{
			setBalance(stod(input));
			check = true;
		}
		
		// display error message if entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what()
				<< " for beginnig balance."
				<< "Please re-enter valid beginnig balance.\n";
		}

	}

}

// collecting customer's total charges
void Customer::inputCharge()
{
	bool check = false;

	// repeatedly prompt user for total charges
	// until valid entry is entered
	while (check == false)
	{
		string input;

		// prompt user for total pending charges
		cout << "Enter total charges: ";
		cin >> input;

		// attempt to store total charges entry
		try
		{
			setCharge(stod(input));

			// validate entry for invalid entries below zero
			if (charge <= 0)
			{
				cout
					<< "Charge cannot be less than zero.\n"
					<< "Please enter a valid charge.\n";
			}
			else
			{
				check = true;
			}
		}
		
		// display error message if entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what()
				<< " for charges."
				<< "Please re-enter valid charges.\n";
		}

	}

}

// collecting customer's total credits
void Customer::inputCredit()
{
	bool check = false;

	// repeatedly prompt user for total credits
	// until valid entry is entered
	while (check == false)
	{
		string input;

		// prompt user for total applicable credits
		cout << "Enter total credits: ";
		cin >> input;

		// attempt to store total credits entry
		try
		{
			setCredit(stod(input));

			// validate entry for invalid entries below zero
			if (credit <= 0)
			{
				cout
					<< "Credit cannot be less than zero.\n"
					<< "Please enter a valid credit.\n";
			}
			else
			{
				check = true;
			}
		}

		// display error message if entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what()
				<< " for credits."
				<< "Please re-enter valid credits.\n";
		}

	}

}

// collecting customer's credit line limit
void Customer::inputLimit()
{
	bool check = false;

	// repeatedly prompt user for credit line limit
	// until valid entry is entered
	while (check == false)
	{
		string input;

		// prompt user for credit line limit
		cout << "Enter credit line limit: ";
		cin >> input;

		// attempt to store credit line limit entry
		try
		{
			setLimit(stod(input));

			// validate entry for invalid entries below zero
			if (limit <= 0)
			{
				cout 
					<< "Limit cannot be less than zero.\n"
					<< "Please enter a valid limit.\n";
			}
			else
			{
				check = true;
			}
		}

		// display error message if entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what()
				<< " for limits."
				<< "Please re-enter valid limits.\n";
		}

	}

}
