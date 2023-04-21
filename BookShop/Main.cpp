
/*
Tanay Nagireddy
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
HW #5 - "a real-world, meaningful program, and
show me how creative you can be in this 'Student Challenge'"
3/3/21

This program manages the operations of a small bookshop by
allowing staff to add books to the store's inventory, add books
for purchase by a customer using a cart system, and finally, print
a receipt with the total amount payable by the customer.
*/

#include "PageTurner.h"

int main()
{
	// setting up to retrieve customer details
	string name = ""; // customer's name
	string email = ""; // customer's email 
	string membership = ""; // customer's membership ID
	
	// setting up an empty cart for the customer
	Cart cart;

	// displaying application welcome page and instructions
	cout
		<< "### Tanay Nagireddy's Page-Turner Bookshop ###\n"
		<< "         Welcome!\n\n"
		;

	// requesting customer details
	cout << "Please enter you name: ";
	getline(cin >> ws, name); // storing customer's name
	cout << "Please enter your email: ";
	getline(cin >> ws, email); // storing customer's email
	cout << "Please enter your membership ID (includes phone#): ";
	getline(cin >> ws, membership); // storing customer's membership

	// associating the cart with the customer details
	cart.addCustomerDetails(&name, &email, &membership);

	// displaying instructions for the store staff to follow, and 
	// staff must choose between one of the following options to proceed
	cout
		<< "Please choose between one of the following options:\n"
		<< "1. add a book to the system\n"
		<< "2. add a book to the cart\n"
		<< "3. buy the book or checkout\n"
		<< "4. close the Page-Turner app\n\n"
		;

	// setting up a blank setting value that later 
	// will be changed by staff input
	int number_ = 0;
 
	// setting up a new system for store operations
	PageTurner pageturner;

	// if staff enters the option 4, this will trigger the app to quit, else
	// the app will continue running
	bool quit = false;

	// run the app until staff quits
	while (!quit)
	{
		// request staff to enter 1 of the four options available
		string prompt_ = "\nPlease enter an option number (1, 2, 3, or 4) from the list above: ";
		
		// validate the entered input, by
		// making sure it's not out of bounds or 
		// invalid (containing text)
		validateInput(prompt_, number_, 4);


		// proceeed with adding a book to the system
		if (number_ == 1)
		{
			string prompt = ""; // the prompt string to be displayed to staff
			string message = ""; // the error handling message to be displayted to staff
			string author_ = ""; // the name of the author
			string title_ = ""; // the name of the title
			int counts_ = 0; // the number of copies of the book that have been received
			double prices_ = 0.0;

			// collect details of the shipment of book that arrived 
			// and add the record to the system

			// name of the author of the book
			cout << "Enter the author's name: ";
			getline(cin >> ws, author_);

			// name of the title of the book
			cout << "Enter the title of the book: ";
			getline(cin >> ws, title_);

			// retrieve the number of copies of the book
			prompt = "Enter the number of copies being added to the shop: "; // prompt to be displayed to staff for number of copies recieved
			message = "Out of bounds for number of copies."; // the error handling message to be displayted to staff
			pageturner.validateCopies(prompt, message, counts_); // validate the staff entry for book copies

			// retrieve the price of a single book
			prompt = "Enter the price of a single copy of the book: "; // prompt to be displayed to staff for price of the book
			message = "Out of bounds for book price."; // the error handling message to be displayted to staff
			pageturner.validatePrice(prompt, message, prices_); // validate the staff entry for book price

			// set the intial check for title to be not in the store
			bool in_store = false;

			// go through titles and check if any match with the one being currently added by staff
			for (int i = 0; i < pageturner.titles.size(); i++)
			{
				// check if the title being added is already in store
				if ((title_ == pageturner.titles[i]) && (author_ == pageturner.authors[i]))
				{
					cout << "--- Title Already in Store ---\n";
					in_store = true;
				}
			}
			
			// if the book is not currently in the store, then add it to the system
			if (in_store == false)
			{
				// add book to the sytem by passing author, title, copies, and price of each copy
				pageturner.addBook(author_, title_, counts_, prices_);
				cout << "--- Item Added to Store ---\n";
			}
		}

		// if the option selected is 2, then proceed to add books to cart
		else if (number_ == 2)
		{	
			string title_ = ""; // set title as blank to be filled in by staff
			string author_ = ""; // set author as blank to be filled in by staff

			// request title of book
			cout << "Please enter title of book: ";
			getline(cin >> ws, title_); // store title of book

			// request name of author of the book 
			cout << "Please enter author of book: ";
			getline(cin >> ws, author_);

			// set the initial match to false until check is complete
			bool match = false;

			// check against each title and author currently in store until a match is found
			for (int i = 0; i < pageturner.titles.size(); i++)
			{
				// // check entered author and title information for a match in store
				if ((title_ == pageturner.titles[i]) && (author_ == pageturner.authors[i]))
				{
					// check to make sure copies are still available
					if (pageturner.counts[i] >= 1)
					{
						cart.addToCart(author_, title_, pageturner.prices[i]); // add book to customer's cart
						pageturner.counts[i] = pageturner.counts[i] - 1; // reduce the number of copies available by 1
						match = true; // set match as true, match is found
						cout << "--- Item Added to Cart ---\n"; // display confirmation that item has been added to cart
						break; // exit loop
					}
					// if no copies of desired book are available, display out of stock message
					else if (pageturner.counts[i] < 1)
					{
						cout << "--- Sold Out ---\n";
					}
				}
			}
			// if no matches are found, display error message that no matches were found
			if (match == false)
			{
				cout
					<< "### No matches found. ###\n"
					<< "Try again or change you search title and author.\n"
					;
			}
		}

		// proceed with checking out customer cart if staff enters option number 3
		else if (number_ == 3)
		{
			// if cart is empty, do not compute total, but
			// just print an error message saying that the cart is empty
			if (cart.prices.size() < 1)
			{
				cout << "--- Cart is Empty ---\n";
			}
			// if cart is not empty, construct the receipt
			else
			{
				// display store title and receipt header
				cout 
					<< "\n<<< Page-Turners Receipt >>>\n"
					<< "For (name, email, membership ID):\n"
					;
					
				// display customer details
				for (string detail : cart.receipt)
				{
					cout << detail << "\n";
				}

				// display items that were confirmed for purchase
				cout 
					<< "\n"
					<< "The following were purchased:\n"
					;

				// print items in cart to be purchased
				for (int i{ 0 }; i < cart.titles.size(); i++)
				{
					cout
						<< cart.titles[i]
						<< " by "
						<< cart.authors[i]
						<< "\n"
						;
				}

				cout << "\n";

				// set receipt total to zero initially
				double total = 0.0;

				// compute cart total that customer must pay
				for (double price : cart.prices)
				{
					total = total + price;
				}

				// print grand total of all books being purchased, along
				// with a warm parting message
				cout 
					<< fixed << setprecision(2) // display proper financial format
					<< "Your total is: $" << total << "\n"
					<< defaultfloat // revert back to default stream output format
					<< "Thank you for making a purchase!\n"
					<< "Hope to see you back here soon :)\n\n"
					;
			}
			
			// empty all contents currently in the customer's cart
			cart.emptyCart();
		}

		// proceed to quit the application if the staff enteres option 4
		else if (number_ == 4)
		{
			// set quit to true to leave the Page-Turner's application
			cout << "--- QUIT ---";
			quit = true;
		}
	}

}
