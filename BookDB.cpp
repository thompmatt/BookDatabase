/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Book Database
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
// This file contains and defines all the functions stated in MathLib.h.
// Contains the following methods:
// 
// - addBook()
// - updateBook()
// - deleteBook()
// - findBooks()
// - calculateAverageRating()
// - print()
// - sortDB()
// - compareByID()
// - compareByYear()
// - compareByRating()
//
///////////////////////////////////////////////////////////////////////////////

#include "BookDB.h"
#include <iostream>
#include <algorithm>

/**
 * First searches the database for an entry with the given bookID. If no such 
 * entry is found, adds the book with the given bookID, year, and rating to the
 * end of the vector and return 0. If there is already an entry with the given 
 * bookID, the list should not be changed and 1 should be returned.
 * 
 * @param bookID The ID number of the book to be added
 * @param year The year of the book to be added
 * @param rating The rating of the book to be added
 * @param &db The vector containing all of the books
 * @return 0 if a book was added, otherwise 1.
 */
int addBook(int bookID, int year, double rating, std::vector<Book> &db) {
	// Iterates through the database to see if there is a book with the same ID
	for (int i = 0; i < db.size(); i++) {
		if (db[i].ID == bookID) {
			return 1;
		}
	}

	Book book;
	book.ID = bookID;
	book.year = year;
	book.rating = rating;

	db.push_back(book); // Adds the book to the vector
	return 0;
}

/**
 * Searches the database for an entry with the given bookID. If such an entry 
 * is found, update the rating and the year as per the input and return 0.
 * If an entry is not found, return 1.
 * 
 * @param bookID The ID number of the book to be updated
 * @param year The year of the book to be updated
 * @param rating The rating of the book to be updated
 * @param &db The vector containing all of the books
 * @return 0 if a book was updated, otherwise 1.
 */
int updateBook(int bookID, int year, double rating, std::vector<Book> &db) {
	// Iterates through the database to see if there is a book with the same ID,
	// if true, changes the year and rating of desired book.
	for (int i = 0; i < db.size(); i++) {
		if (db[i].ID == bookID) {
			db[i].year = year;
			db[i].rating = rating;
			return 0;
		}
	}

	return 1;
}

/**
 * Searches the database for an entry with the given bookID. If such an entry 
 * is found, remove the entry from the database and return 0. If there is no
 * entry on the list with the given bookID, the list should not be changed and 
 * 1 should be returned.
 * 
 * @param bookID The ID number of the book to be removed
 * @param &db The vector containing all of the books
 * @return 0 if a book was deleted, otherwise 1.
 */
int deleteBook(int bookID, std::vector<Book> &db) {
	// Iterates through the database to see if there is a book with the same ID
	for (int i = 0; i < db.size(); i++) {
		if (db[i].ID == bookID) {
			db.erase(db.begin() + i); // Erases the element from vector
			return 0;
		}
	}

	return 1;
}

/**
 * Returns a pointer to the vector of Books published in the year specified 
 * by the argument.
 * 
 * @param year The year of the book that would like to be returned
 * @param &db The vector containing all of the books
 * @return a pointer to the vector of Books
 */
std::vector<Book>* findBooks(int year, const std::vector<Book> &db) {
	std::vector<Book> * ptr = new std::vector<Book>();

	// Looks through database for books with specified year
	for (int i = 0; i < db.size(); i++) {
		if (db[i].year == year) {
			ptr->push_back(db[i]); // Adds it to the pointer
		}
	}

	return ptr;
}

/**
 * Calculate and print the average rating of all the books in the database. 
 * If no books have been added, returns -1.0.
 * 
 * @param &db The vector containing all of the books
 * @return the average rating, or -1.0 if no books have been added
 */
double calculateAverageRating(const std::vector<Book> &db) {
	double average = 0.0;

	// If there are no books, return -1.0
	if (db.size() == 0) {
		return -1.0;
	}

	// Adds the rating of every single book in database
	for (int i = 0; i < db.size(); i++) {
		average += db[i].rating;
	}

	average = average/db.size(); // Divides by number of books
	
	return average;
}

/**
 * Prints the contents of the database to cout.
 * 
 * @param &db The vector containing all of the books
 */
void print(const std::vector<Book> &db) {
	// Iterates through the database, printing all its contents
	for (int i = 0; i < db.size(); i++) {
		std::cout << db[i].ID << ", " << db[i].year << ", " << db[i].rating
			<< std::endl;
	}

	return;
}

/**
 * This functions should take two arguments: the book database and the 
 * user-specified sorting behavior choice. After calling this function, a call
 * to print() from main() should produce a sorted output. If the user enters
 * something other than the three possible numbers for the sort option, 
 * return 1. Otherwise return 0.
 * 
 * @param &db The vector containing all of the books to be sorted
 * @param sortingMethod Desired method of sorting the books
 * @return 1 if not an option, else 0.
 */
int sortDB(std::vector<Book> &db, int sortingMethod) {
	// Switch statement with all 3 different methods
	switch (sortingMethod) {
		case 1: // Sort by ID
			std::sort(db.begin(), db.end(), compareByID);
			break;
		case 2: // Sort by Year
			std::sort(db.begin(), db.end(), compareByYear);
			break;
		case 3: // Sort by Rating
			std::sort(db.begin(), db.end(), compareByRating);
			break;
		default:
			return 1;
	}

	return 0;
}

/**
* Helper method to sort books by ID, returns the smaller ID first
* @return true if a is smaller than b, false otherwise
*/
bool compareByID(const Book &a, const Book &b) {
	return a.ID < b.ID;
}

/**
* Helper method to sort books by year, returns the smaller year first
* @return true if a is smaller than b, false otherwise
*/
bool compareByYear(const Book &a, const Book &b) { 
	// If there is a tie, compare by ID
	if (a.year == b.year) {
		return compareByID(a, b);
	}

	return a.year < b.year;
}

/**
* Helper method to sort books by rating, returns the smaller rating first
* @return true if a is smaller than b, false otherwise
*/
bool compareByRating(const Book &a, const Book &b) {
	// If there is a tie, compare by ID
	if (a.rating == b.rating) {
		return compareByID(a, b);
	}

	return a.rating < b.rating;
}