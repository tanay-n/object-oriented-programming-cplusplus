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
#include <iomanip>
using std::setprecision;
using std::fixed;
using std::defaultfloat;

int main() 
{
	// print user instructions
	cout
		<< "\n### Tanay Nagireddy's Department Store ###\n"
		<< "Please enter your account information to "
		<< "view outstanding credit balance.\n"
		<< "Please note that any text typed after "
		<< "entries is ignored.\n\n";

	Customer customer; // setup a blank customer form

	int quit = 0;

	// request for customer input and display account info until user quits
	while (quit != -1)
	{
		// collect customer's account number
		customer.inputAccountNumber();

		// check account number input for user request to quit the program
		if (customer.getAccountNumber() == -1)
		{
			cout << "--- END ---\n";
			quit = -1;
		}
		
		// display error message if account number is less than -1
		else if (customer.getAccountNumber() < -1)
		{
			cout
				<< "Account number cannot be less than -1.\n"
				<< "Please enter a valid account number.\n";
		}

		// display customer account info
		else
		{
			// collect customer account info
			customer.inputBalance();
			customer.inputCharge();
			customer.inputCredit();
			customer.inputLimit();

			// compute customer outstanding credit balance
			customer.calculateBalance();

			// check if account if overdrawn
			if (customer.getBalance() > customer.getLimit())
			{
				// display account number
				cout
					<< "Account:      "
					<< customer.getAccountNumber()
					<< "\n";

				// display credit limit and balance
				cout
					<< setprecision(2) 
					<< fixed
					<< "Credit limit: "
					<< customer.getLimit()
					<< "\n"
					<< "Balance:      "
					<< customer.getBalance()
					<< "\n"
					<< defaultfloat;

				// display account error message
				cout << "Credit Limit Exceeded.\n\n";
				
			}

			// since account is not overdrawn, just
			// display outstanding customer balance
			else
			{
				cout
					<< setprecision(2)
					<< fixed
					<< "New balance is "
					<< customer.getBalance()
					<< "\n\n"
					<< defaultfloat;
			}

		}

	}
	
}