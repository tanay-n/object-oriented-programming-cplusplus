#pragma once

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

#include <iostream>
#include <string>
#include <exception>
using std::cout;
using std::cin;
using std::string;
using std::exception;
using std::stoi;
using std::stod;

/*
Print Credit Balance for Karls Bob Department Store customer

The remaining balance of the user is printed after
they have entered their credit account details. Note
that a negative balance signifies that the user's account
balance is negative, is a surplus, and if positive, is 
the sum owed (the user must make their monthly payments).
The new balance is calculated as the beginning (balance +
charges) - credits.
*/


class Customer
{
public:

	// setting default customer account values
	Customer(
		int account_number = 0, 
		double balance = 0, 
		double charge = 0, 
		double credit = 0, 
		double limit = 0);

	// retrieving customer values
	int getAccountNumber();
	double getBalance();
	double getCharge();
	double getCredit();
	double getLimit();

	// computing the new balance
	void calculateBalance();

	// collecting and validating customer input
	void inputAccountNumber();
	void inputBalance();
	void inputCharge();
	void inputCredit();
	void inputLimit();

	// assigning customer values
	void setAccountNumber(int x);
	void setBalance(double x);
	void setCharge(double x);
	void setCredit(double x);
	void setLimit(double x);

private:

	// customer's credit acount details
	int account_number;
	double balance;
	double charge;
	double credit;
	double limit;
};