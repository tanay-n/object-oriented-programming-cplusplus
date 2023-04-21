
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

int main()
{
	// display header for user
	cout
		<< "### Compare Savings Account Scenarios ###" << "\n\n"
		;
	
	// set savings balanace initial value, error message to be displayed, and
	// an initial prompt string that will be changed based on the question being
	// asked to the user
	double savings_balance = 0.0;
	string message = "savings balance";
	string prompt = "";

	// set the formating for numbers displayed to have at most 2 decimal places
	cout << fixed << setprecision(2);

	// request the user for savings balance scenario 1
	prompt = "Please enter your savings account balance to "
		"view the updated balance with added monthly interest: ";
	
	// for saver 1, validate the user input provided by making sure that it is
	// wihtin bounds and is an acceptable entry (not string)
	validateInput(prompt, message, savings_balance, 1.0, 1000000000.0);
	SavingsAccount saver1(savings_balance);

	// request the user for savings balance scenario 2
	prompt = "To compare, please enter another savings account balance to "
		"view the updated balance with added monthly interest: ";

	// for saver 2, validate the user input provided by making sure that it is
	// wihtin bounds and is an acceptable entry (not string)
	validateInput(prompt, message, savings_balance, 1.0, 1000000000.0);
	SavingsAccount saver2(savings_balance);

	// display the starting balances for saver 1 and saver 2 scenarios
	cout << "Saver 1's starting savings account balance is: $" << saver1.getSavingsBalance() << "\n";
	cout << "Saver 2's starting savings account balance is: $" << saver2.getSavingsBalance() << "\n";

	// set condition for when user decides to quit the scenario viewer
	bool quit = false;

	// repeat options until user decides to quit the scenario viewer
	while (!quit)
	{
		// display options requesting user to select one of them
		cout
			<< "\nPlease choose from the following options:\n"
			<< "1. enter or update annual interest rate (initially set to 0%)\n"
			<< "2. calculate monthly interest on current balance\n"
			<< "3. quit the scenario viewer\n"
			<< "4. view default test scenarios\n\n"
			;

		// set the initial option that the user selects to zero, and ask the user for
		// a valid option
		double option = 0;
		prompt = "Please enter an option (1, 2, 3, or 4): ";
		message = "available option";

		// pass the prompt above along with the error message to display to the user and 
		// validate the input making sure that it's within bounds and is an acceptable entry
		validateInput(prompt, message, option, 1, 4);

		// proceed to enter a new interest rate or update an existing rate if the user selects
		// option 1
		if (option == 1)
		{
			// set the annual interest rate to an initial value of zero
			double annual_int_rate = 0.0;

			// set the question to be asked
			prompt = "Please enter the annual interest rate: ";
			
			// set the error message value to display to the user
			message = "interest rate";

			// display current interest rate
			cout
				<< "The current interest rate is: " << SavingsAccount::getAnnualInterestRate() << "\n"
				;

			// validate the user input provided by making sure that it is
			// wihtin bounds of an expected interest rate and that it is 
			// an acceptable entry (not string)
			validateInput(prompt, message, annual_int_rate, 0.01, 0.99);

			// update the annual interest for both scenarios (saver 1 and saver 2)
			SavingsAccount::modifyInterestRate(annual_int_rate);

			// display updated interest rate
			cout
				<< "The updated annual interest rate is now: " << SavingsAccount::getAnnualInterestRate() << "\n"
				;

		}
		// proceed to calculate the monthly interest if the user selects option 2
		else if (option == 2)
		{
			// calculate the month interest for both saver 1 and saver 2 scenarios
			saver1.calculateMonthlyInterest();
			saver2.calculateMonthlyInterest();

			// display the new balances for saver 1 and saver 2
			cout << "Saver 1 scenario's updated savings account balance is: $" << saver1.getSavingsBalance() << "\n";
			cout << "Saver 2 scenario's updated savings account balance is: $" << saver2.getSavingsBalance() << "\n\n";
		}
		// proceed to quit the program if the user selects option 3
		else if (option == 3)
		{
			// display to the user that they have exited the program
			cout << "--- QUIT ---";
			quit = true;
		}
		// proceed to display a pre-defined test case of scenarios if the user selects option 4
		else if (option == 4)
		{
			// display pre-built test case to the user
			testSavingsAccountClass();
		}
	}
}