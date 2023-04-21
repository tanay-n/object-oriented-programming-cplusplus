#pragma once

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

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
using std::exception;
using std::fixed;
using std::setprecision;

// represents a savings account
class SavingsAccount
{
public:

	// set the savings with in initial balance
	SavingsAccount(double balance);
	
	// retrieve the annual interest for all accounts
	static double getAnnualInterestRate();

	// retrieve the savings account balance for a particular account
	double getSavingsBalance();

	// calculate monthly interest and update the savings account balance
	void calculateMonthlyInterest();

	// modify the interest rate for all accounts 
	static void modifyInterestRate(double ir);

private:

	// annual interest rate for all accounts
	static double annualInterestRate;

	// savings account balance for a particular account
	double savingsBalance;
	
};

// validate user input and only store value until it has been verified to be valid
void validateInput(string& prompt, string& message, double& number, double min_, double max_savings);

// call test savings account scenarios
void testSavingsAccountClass();

// represents a test savings account
class testSavingsAccount
{
public:

	// set the savings with in initial balance
	testSavingsAccount(double balance);

	// retrieve the annual interest for all test accounts
	static double getAnnualInterestRate();

	// retrieve the savings account balance for a particular test account
	double getSavingsBalance();
	
	// calculate monthly interest and update the test savings account balance
	void calculateMonthlyInterest();

	// modify the interest rate for all test accounts 
	static void modifyInterestRate(double ir);

private:

	// annual interest rate for all test accounts
	static double annualInterestRate;

	// savings account balance for a particular account
	double savingsBalance;

};