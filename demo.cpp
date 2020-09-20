/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Demo for Book Database
// Files: BookDB.h, BookDB.cpp, demo.cpp, README.md, Makefile
// Course: CS 368, Spring 2020
//
// Author: Matt Thompson
// Student ID: 9081263262
// Email: mathompson23@wisc.edu
// Lecturer's Name: Marc Renault
//
// Online Sources: 
// - https://stackoverflow.com/questions/409348/iteration-over-stdvector-
//   	unsigned-vs-signed-index-variable
// - https://stackoverflow.com/questions/875103/how-do-i-erase-an-element
// 		-from-stdvector-by-index
// - https://stackoverflow.com/questions/4892680/sorting-a-vector-of-structs
// 
//////////////////////////// FILE DESCRIPTION /////////////////////////////////
// 
// This file demo's all the function in the Book Database. Contains the main()
// method which runs a while loop which continues until the user enters 'q'
// (quit). Prints out error statements when a command is not valid.
//
///////////////////////////////////////////////////////////////////////////////

#include "BookDB.h"
#include <iostream>

int main()
{
	std::vector<Book> database;
	char option = ' ';
	int bookID;	// User selected ID
	int bookYear; // User selected Year
	int returned; // Returned value by functions
	int sortMethod; // User selected method for sortDB()
	double bookRating; // User selected Rating
	double returnedAvg; // For the calculateAverageRating() function 
	
	// While loop that runs the program until user enters char 'q' (quit).
	while (option != 'q') {
		std::cout << "> ";
		std::cin >> option;

		// Switch statement with all possible commands. If it does not match,
		// throws error message.
		switch (option) {
			case 'q': // Quit
				break;
			case 'a': // Adds book method
				std::cin >> bookID >> bookYear >> bookRating;
				returned = addBook(bookID, bookYear, bookRating, database);
				if (returned == 1) {
					std::cout << "Error processing command" << std::endl;
				} else {
					std::cout << "Book " << bookID << " added" << std::endl;
				}

				break;
			case 'u': // Updates book method
				std::cin >> bookID >> bookYear >> bookRating;
				returned = updateBook(bookID, bookYear, bookRating, database);
				if (returned == 1) {
					std::cout << "Error processing command" << std::endl;
				} else {
					std::cout << "Book " << bookID << " updated" << std::endl;
				}

				break;
			case 'c': // Calculate average rating method
				returnedAvg = calculateAverageRating(database);
				if (returnedAvg == -1.0) {
					std::cout << "Error processing command" << std::endl;
				} else {
					std::cout << "Average rating = " << returnedAvg << std::endl;
				}

				break;
			case 'd': // Deletes a book method
				std::cin >> bookID;
				returned = deleteBook(bookID, database);
				if (returned == 1) {
					std::cout << "Error processing command" << std::endl;
				} else {
					std::cout << "Book " << bookID << " removed" << std::endl;
				}

				break;
			case 'p': // Prints books in database
				if (database.size() == 0) { // If database has no books
					std::cout << "No entries" << std::endl;
					break;
				} else {
					print(database);
				}

				break;
			case 'f': // Find book of specific year
				std::vector<Book> * returnedBooks;

				std::cin >> bookYear;
				returnedBooks = findBooks(bookYear, database);
				if (returnedBooks->size() == 0) { // If pointer size is 0
					std::cout << "No entries" << std::endl;
				} else {
					print(*returnedBooks);
				}
				delete returnedBooks;

				break;
			case 's': // Sort database by selected method
				std::cin >> sortMethod;
				returned = sortDB(database, sortMethod);

				break;
			default:
				std::cout << "Error processing command" << std::endl;

				break;
		}
	}

	std::cout << "quit" << std::endl;
	return 0;
}