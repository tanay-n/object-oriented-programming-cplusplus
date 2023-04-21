
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

#include "ComputerAssistedInstruction.h"

int main()
{
	bool quit = false; // setting condition for infinite while loop 

	// keep running the training application until the user shuts it down
	while (!quit)
	{
		// display welcome message and instructions for student
		cout
			<< "### Tanay Nagireddy's Math Practice ###\n"
			<< "Hi there! Welcome to Tanay Nagireddy's Math Practice!\n"
			<< "You will be given a set of 10 problems to solve, but\n"
			<< "before we get started, you will need to pick a difficulty\n"
			<< "level that challenges you, as well as the type of problems\n"
			<< "you want to get better at solving. Please choose from the\n"
			<< "following selection of difficulty levels and problem types.\n\n";

		// display difficulty options
		cout
			<< "Difficulty levels:\n"
			<< " 1 - problems use only single digits\n"
			<< " 2 - problems use upto two digits\n"
			<< " 3 - problems use upto three digits\n\n";

		// display problem types
		cout
			<< "Problem types:\n"
			<< " 1 - addition problems only\n"
			<< " 2 - subtraction problems only\n"
			<< " 3 - multiplication problems only\n"
			<< " 4 - division problems only "
			<< "NOTE: make sure to round your answer to 2 decimal places\n"
			<< " 5 - a random mixture of options 1, 2, 3, and 4\n\n";

		srand(time(0)); // ensuring that random values are generated every session

		PracticeMath practice_math; // setup a new assessment

		// prompt student for program settings from the options provided
		practice_math.inputSettings();

		// display the settings selected
		cout
			<< "You have selected option " 
			<< practice_math.getDifficultyLevel() // display difficulty
			<< " for difficulty, and option "
			<< practice_math.getProblemType() // display problem type
			<< " for the type of problems you will solve."
			<< "\n\n";

		// start the assessment
		practice_math.createProblems();

		// calculate the answers and store them to check the responses against
		practice_math.computeAnswers();

		// display the problems to solve
		practice_math.displayProblems();

		// calculate the final score and display next steps
		practice_math.computeScore();

	}
}