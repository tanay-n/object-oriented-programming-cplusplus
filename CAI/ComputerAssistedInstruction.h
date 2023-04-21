#pragma once

/*
Tanay Nagireddy
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
HW #4 - Exercise 6.57-6.61 p281-p282
2/18/21

This interactive program helps a student practice fundamental
math as it allows the student to choose from 5 options, namely, 
addition, subtraction, multiplication, division, or a random mix
of all 4 along with a difficulty in terms of the number of digits
each value the problem contains. This program tracks the performance
of the given 10 problems, providing feedback after every answer,
and provides a final grade. It then encourages the student to seek 
assistance from the teacher or proceed to the next level of difficulty 
depending on the performance of the student.
*/

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <array>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::string;
using std::exception;
using std::rand;
using std::srand;
using std::time;
using std::array;
using std::setprecision;
using std::round;

// represents a tunums math training application
class PracticeMath
{

public:

	static const size_t arraySize{ 10 }; // size of the array

	// setting the initial values for difficulty level, problem type, problems, answers, responses and feedback
	PracticeMath();

	// retrieve difficutly level
	int getDifficultyLevel();

	// retrieve problem type
	int getProblemType();

	// set the difficulty and type of the problems to solve
	void inputSettings();

	// create problems
	void createProblems();

	// calculate and store answers
	void computeAnswers();
	
	// display problems to solve and mark if answer is right or wrong
	void displayProblems();
	
	// compute the performance from the ten problems answered and display final assessment
	void computeScore();

private:

	// storing program settings
	int difficulty_level; // storing difficulty type
	int problem_type; // storing problem type

	array<double, arraySize> numbers1{ 0 }; // storing the first set of randomly generated values for the 10 problems
	array<double, arraySize> numbers2{ 0 }; // storing the second set of randomly generated values for the 10 problems
	array<int, arraySize> ptype{ 0 }; // storing problem type
	array<double, arraySize> answers{ 0 }; // storing answers
	array<int, arraySize> responses{ 0 }; // storing responses
	array<string, arraySize> feedback_right{ 0 }; // storing feedback messages to display for a right answer
	array<string, arraySize> feedback_wrong{ 0 }; // storing feedback messages to display for a wrong answer

	// generate a random number
	int genRandomNumber(int& max, int& min);
	
	// validate user input for settings
	void validateSettings(string& input, int& number, int options);
	
	// store the difficulty level
	void setDifficultyLevel(int diff_lvl); 
	
	// store the problem type
	void setProblemType(int prblm_type);
	
	// create the problems the student will solve
	void createProblemTypes();

	// validate the reponses from the student before checking the response against the answer
	void validateResponse(int& question, string& prompt, double& number);
};