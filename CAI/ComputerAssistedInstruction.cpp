
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

// setting the initial values for difficulty level, problem type, problems, answers, responses and feedback
PracticeMath::PracticeMath()
	: difficulty_level{ 1 } // initializing the difficulty level to 1
	, problem_type{ 1 } // initializing the difficulty level to 1

	// initializing randomly generated values for the 10 problems
	, numbers1{}
	, numbers2{}

	, ptype{} // initializing the problem type array
	, answers{} // initializing the answers array
	, responses{} // initializing the responses array

	// initializing feedback strings to display to the user depending whether they answered right or wrong
	, feedback_right{"Nice one!", "That's great, keep going!", "Good job!", "Fantastic!"}
	, feedback_wrong{"Not quite, next time!","Whoops, on to the next one!","This one's wrong, but you still got this!","Nope, don't give up!"}
{}

// retrieve difficutly level
int PracticeMath::getDifficultyLevel()
{
	return difficulty_level; // returning difficulty level
}

// retrieve problem type
int PracticeMath::getProblemType()
{
	return problem_type; // returning problem type
}

// assign difficulty level
void PracticeMath::setDifficultyLevel(int diff_lvl)
{
	difficulty_level = diff_lvl; // store difficulty level

}

// assign problem type
void PracticeMath::setProblemType(int prblm_type)
{
	problem_type = prblm_type; // store problem type

}

// make sure that user input for program settings is a valid integer
void PracticeMath::validateSettings
(
	string& prompt, // passing prompt to display
	int& number, // passing number to store the user input
	int options // passing number of options available to select
)
{
	bool next = false; // setting condition to exit while loop

	// repeatedly prompt user for a difficulty level until 
	// a valid integer is entered
	while (!next)
	{
		string input = ""; // set up to collect user input

		cout <<  prompt; // displaying prompt
		cin >> input; // collecting user input

		// attempt to store integer
		try
		{
			number = stoi(input); // attempting to store user input

			// check if entry is within bounds
			if (number < 1 || number > options)
			{
				cout
					<< "Setting is out of bounds.\n"
					<< "Please try again.\n";
			}
			else
			{
				next = true; // exit loop and store setting option from user input
			}
		}

		// display error message if entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what() // display error message from stoi function
				<< " for setting.\n"
				<< "Please try again.\n";
		}
	}
}

// obtain settings from user
void PracticeMath::inputSettings()
{	
	int number = 0; // initialize setting number
	string prompt = ""; // initialize prompt to display
	
	// display prompt for difficulty level
	prompt = "Please enter the difficulty level you have chosen: ";
	
	// validate user input for difficulty level
	validateSettings(prompt, number, 3);
	setDifficultyLevel(number); // store difficulty level

	// display prompt for problem type
	prompt = "Please enter the problem type you have chosen: ";

	// validate user input for problem type
	validateSettings(prompt, number, 5);
	setProblemType(number); // store problem type
}

// generating random number
int PracticeMath::genRandomNumber(int& max, int& min)
{
	// store randomly generated number
	int number = (rand() % ((max - min) + 1)) + min;
	return number; // return randomly generated number
}

// mark each question with a specific problem type
void PracticeMath::createProblemTypes()
{
	if (problem_type == 1) // check for specific problem type - addition
	{
		// mark each question with the selected problem type
		for (int i = 0; i < 10; i++)
		{
			ptype[i] = 1; // set problem type to 1
		}
	}
	else if (problem_type == 2) // check for specific problem type - subtraction
	{
		// mark each question with the selected problem type
		for (int i = 0; i < 10; i++)
		{
			ptype[i] = 2; // set problem type to 2
		}
	}
	else if (problem_type == 3) // check for specific problem type - multiplication
	{
		// mark each question with the selected problem type
		for (int i = 0; i < 10; i++)
		{
			ptype[i] = 3; // set problem type to 3
		}
	}
	else if (problem_type == 4) // check for specific problem type - division
	{
		// mark each question with the selected problem type
		for (int i = 0; i < 10; i++)
		{
			ptype[i] = 4; // set problem type to 4
		}
	}
	else if (problem_type == 5) // check if random set of problems need to be generated
	{
		int max = 4; // set max value for random number generator function 
		int min = 1; // set min value for random number generator function

		// for each question, generate a problem type
		for (int i = 0; i < 10; i++)
		{
			ptype[i] = genRandomNumber(max, min); // store randomly generated problem type
		}
	}
}

// create 20 random values for a set of 10 problems
void PracticeMath::createProblems()
{
	int max_ = 0; // set max value for random number generator function
	int min_ = 0; // set min value for random number generator function

	createProblemTypes(); // mark each question with a problem type 

	// for each question, set the digit limits for problems  based on difficulty level
	for (int i = 0; i < 10; i++)
	{
		// check if question is not division type
		if (ptype[i] != 4)
		{
			if (getDifficultyLevel() == 1)
			{
				max_ = 9; // assign a max positive digit limit upto 1 digit
				min_ = -9; // assign a min negative digit limit upto 1 digit 
			}
			else if (getDifficultyLevel() == 2)
			{
				max_ = 99; // assign a max positive digit limit upto 2 digits
				min_ = -99; // assign a min negative digit limit upto 2 digits
			}
			else if (getDifficultyLevel() == 3)
			{
				max_ = 999; // assign a max positive digit limit upto 3 digits
				min_ = -999; // assign a min negative digit limit upto 3 digits
			}
		}
		// check if question is division type
		else if (ptype[i] == 4)
		{
			min_ = 1; // set min digit limit

			if (getDifficultyLevel() == 1)
			{
				max_ = 9; // asign max positive digit limit upto 1 digit
			}
			else if (getDifficultyLevel() == 2)
			{
				max_ = 99; // asign max positive digit limit upto 2 digits
			}
			else if (getDifficultyLevel() == 3)
			{
				max_ = 999; // asign max positive digit limit upto 3 digits
			}
		}

		numbers1[i] = genRandomNumber(max_, min_); // generate first random number for the question
		numbers2[i] = genRandomNumber(max_, min_); // generate second random number for the question
	}
}

// calculate answers to the problems generated
void PracticeMath::computeAnswers()
{
	// for each question, store the answer based on problem type
	for (int i = 0; i < 10; i++)
	{
		if (ptype[i] == 1) // check if problem type is addition
		{
			answers[i] = numbers1[i] + numbers2[i]; // add number1 and number 2 for the question
		}
		else if (ptype[i] == 2) // check if problem type is subtraction
		{
			answers[i] = numbers1[i] - numbers2[i]; // subtract number2 from number 1 for the question
		}
		else if (ptype[i] == 3) // check if problem type is multiplication
		{
			answers[i] = numbers1[i] * numbers2[i]; // multiply number1 and number 2 for the question
		}
		else if (ptype[i] == 4) // check if problem type is division
		{
			answers[i] = numbers1[i] / numbers2[i]; // divide number1 by number 2 for the question
			answers[i] = round(answers[i] * 100.0) / 100.0; // round to 2 decimal places
		}
	}
}

// display the problems to the user, and mark the reponse right or wrong while storing the mark
void PracticeMath::displayProblems()
{
	// for each question display a prompt depending on the problem type
	for (int i = 0; i < 10; i++)
	{
		string sign = ""; // initializing sign string
		double number_ = 0; // initializing user input answer
		int min_ = 0; // setting min value for feedback message generation
		int max_ = 3; // setting max value for feedback message generation
		int feedback = genRandomNumber(max_, min_); // generating feedback message

		if (ptype[i] == 1) // check if problem type is addition
		{
			sign = "+"; // assign plus sign depending on the problem type
		}
		else if (ptype[i] == 2) // check if problem type is subtraction
		{
			sign = "-"; // assign minus sign depending on the problem type
		}
		else if (ptype[i] == 3) // check if problem type is multiplication
		{
			sign = "x"; // assign multiplication sign depending on the problem type
		}
		else if (ptype[i] == 4) // check if problem type is division
		{
			sign = "/"; // assign division sign depending on the problem type
		}

		// validate student input
		validateResponse(i, sign, number_);

		// check if answer is correct
		if (number_ == answers[i])
		{
			cout << feedback_right[feedback] << "\n"; // display feedback message
			responses[i] = 10; // mark response as correct
		}
		// if answer is incorrect, then mark as incorrect
		else
		{
			cout << feedback_wrong[feedback] << "\n"; // display feedback message
			responses[i] = 0; // mark response as incorrect
		}
	}
}

// validate the user response/answer to the question
void PracticeMath::validateResponse
(
	int& question, // pass question number to display
	string& prompt, // pass problem type to display
	double& number // pass number to store the student's answer
)
{
	bool next = false; // set condition value for repeaing while loop

	// repeatedly prompt user for a difficulty level until 
	// a valid integer is entered
	while (!next)
	{
		string input = ""; // set up to collect user input

		// display the question prompt
		cout
			<< "Question #" << question + 1
			<< ": "
			<< numbers1[question] << " "
			<< prompt << " "
			<< numbers2[question] << " = ";

		cin >> input; // collect user input as string

		// attempt to store integer
		try
		{
			number = stod(input); // attempt to store user input
			next = true; // exit loop and store setting option from user input
		}

		// display error message if entry is invalid
		catch (exception& e)
		{
			cout
				<< e.what() // display error message from stod function
				<< " for answer.\n"
				<< "Check your answer and try again.\n";
		}
	}
}

// calculate the total score and let the student know whether they should proceed or get help
void PracticeMath::computeScore()
{
	int sum_ = 0; // initializing sum of values

	// add the marks for correctly answered questions
	for (int i = 0; i < 10; i++)
	{
		sum_ = sum_ + responses[i]; // store the marks
	}

	// display percentage
	cout
		<< "\nYour final score is "
		<< sum_ << "%."; // display the final grade as a percentage
	
	// check if final score is higher than 75%
	if (sum_ > 75)
	{
		// display prompt confirming student is ready to advance to the next difficulty level
		cout << "\nCongratulations, you are ready for the next level!\n\n";
	}
	// if final score is less than 75%
	else
	{
		// display prompt encouraging student to seek assistance from teacher
		cout << "\nPlease ask your teacher for extra help.\n\n";
	}
}
