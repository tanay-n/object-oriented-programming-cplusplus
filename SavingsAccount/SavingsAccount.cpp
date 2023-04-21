
#include "SavingsAccount.h"

/*
Tanay Nagireddy
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
HW #6 - Exercise 9.20 p443
3/4/21

This program allows the user to compare the balances between
two scenarios that involve different savings account balances while
providing an option to modify the interest rate. Once monthly interest
rate is calculated, it is added to the savings balance, and this balance
becomes the current balance used for following calculations (interest is
compounded monthly).
*/

// sets up the savings balance for the saver
// to setup the savings account with an initial value
SavingsAccount::SavingsAccount( double balance )
	: savingsBalance{ balance }
{}

// set the annual interest to an initial value of zero for all savers
double SavingsAccount::annualInterestRate = 0.0;

// retrieve the annual interest rate utilized by all savers
double SavingsAccount::getAnnualInterestRate()
{
	// provide stored annual interest rate
	return annualInterestRate;
}

// retrieve the savings account balance for that particular saver
double SavingsAccount::getSavingsBalance()
{
	// provide the current savings balance for that particular saver
	return savingsBalance;
}

// modify the annual interest rate utilized by all savers
void SavingsAccount::modifyInterestRate(double ir)
{
	// update the annual interest rate 
	annualInterestRate = ir;
}

// compute the monthly interest rate for the current savings balance and
// add it back to the savings balance
void SavingsAccount::calculateMonthlyInterest()
{
	// get the new savings account balance by dividing the annual interest rate
	// by 12 months and multiplying that by the current savings balance, then adding
	// this value back to form the new savings account balance
	savingsBalance = savingsBalance + (savingsBalance * annualInterestRate / 12);
}


// validates the value entered by the user
void validateInput
(
	string& prompt, // pass prompt to display
	string& message, // pass error error message value to display
	double& number, // pass number to store the user input
	double min_,// pass min number of values available to select
	double max_ // pass max number of values available to select
)
{
	bool next = false; // setting condition to exit while loop

	// repeatedly prompt user for a book shop system action until 
	// a valid number is entered
	while (!next)
	{
		string input = ""; // set up to collect user input

		cout << prompt; // displaying prompt
		cin >> input; // collecting user input

		// attempt to store value
		try
		{
			
			number = stod(input); // attempting to store user input

			// check if entry is within bounds of the options available
			if (number < min_ || number > max_)
			{
				// if entry is out of bounds, then display error message
				cout
					<< "Entry for " << message << " is out of bounds.\n"
					<< "Please try again.\n";
			}
			// if value entered is acceptable, the proceed to store the value
			else
			{
				next = true; // exit loop and store setting option from user input
			}
		}

		// display error message if user entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what() // display error message from stod function
				<< " for " << message << ".\n"
				<< "Please try again.\n";
		}
	}
}

// sets up the savings balance for the test saver
// to setup the savings account with an initial value
testSavingsAccount::testSavingsAccount(double balance)
	: savingsBalance{ balance }
{}

// set the annual interest to an initial value of zero for all test savers
double testSavingsAccount::annualInterestRate = 0.0;

// retrieve the annual interest rate utilized by all test savers
double testSavingsAccount::getAnnualInterestRate()
{
	// provide stored annual interest rate
	return annualInterestRate;
}

// retrieve the savings account balance for that particular test saver
double testSavingsAccount::getSavingsBalance()
{
	// provide the current savings balance for that particular test saver
	return savingsBalance;
}

// modify the annual interest rate utilized by all test savers
void testSavingsAccount::modifyInterestRate(double ir)
{
	// update the annual test interest rate 
	annualInterestRate = ir;
}

// compute the monthly interest rate for the current savings balance and
// add it back to the savings balance
void testSavingsAccount::calculateMonthlyInterest()
{
	// get the new test savings account balance by dividing the annual interest rate
	// by 12 months and multiplying that by the current test savings balance, then adding
	// this value back to form the new savings account balance
	savingsBalance = savingsBalance + (savingsBalance * annualInterestRate / 12);
}


// test the SavingsAccount class with pre-assigned savings balances and
// interest rates
void testSavingsAccountClass()
{
	// display header for default scenario test case called in option 4
	cout
		<< "\n\n### Default test scenarios for the user to view ###\n\n"
		;

	// displaying balances for saver 1 and saver 2 scenario
	cout
		<< "Saver 1's starting savings account balance is $2000.00\n"
		<< "Saver 2's starting savings account balance is $3000.00\n\n"
		;

	// storing balance for saver 1 and saver 2 as saving accounts
	testSavingsAccount saver1(2000.00);
	testSavingsAccount saver2(3000.00);

	// display interest rate
	cout
		<< "Annual interest rate is set to 3%\n"
		;

	// set the annual interest rate to 3%
	testSavingsAccount::modifyInterestRate(0.03);

	// calculate the month interest for both saver 1 and saver 2 scenarios
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	// display the new balance
	cout << "Saver 1's updated savings account balance is: $" << saver1.getSavingsBalance() << "\n";
	cout << "Saver 2's updated savings account balance is: $" << saver2.getSavingsBalance() << "\n";

	// display the annual interest rate rate to be used on the updated balance
	cout
		<< "Annual interest rate is set to 4%\n"
		;

	// set the annual interest rate to 4%
	testSavingsAccount::modifyInterestRate(0.04);

	// calculate the month interest for both saver 1 and saver 2 scenarios
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	// display the new balances for saver 1 and saver 2
	cout << "Saver 1's updated savings account balance is: $" << saver1.getSavingsBalance() << "\n";
	cout << "Saver 2's updated savings account balance is: $" << saver2.getSavingsBalance() << "\n";

}
