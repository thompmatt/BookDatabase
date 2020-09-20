/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Book Database Header
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
// This program is a Book Database, in which the user is prompted to enter
// a command, or quit. The program can add a book, with its year and rating,
// remove a book, update a book, find a certain book by searching for its year
// calculate the average rating of all books, and sort the books in three
// different ways.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef BOOKDB_H
#define BOOKDB_H

#include <vector>
#include <string>

/* Creates a struct with the values of the Book's ID, publication year, and 
rating */
struct Book {
	int ID; // Book's ID
	int year; // Book's year
	double rating; // Book's rating
};

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
int addBook(int bookID, int year, double rating, std::vector<Book> &db);

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
int updateBook(int bookID, int year, double rating, std::vector<Book> &db);

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
int deleteBook(int bookID, std::vector<Book> &db);

/**
 * Returns a pointer to the vector of Books published in the year specified 
 * by the argument.
 * 
 * @param year The year of the book that would like to be returned
 * @param &db The vector containing all of the books
 * @return a pointer to the vector of Books
 */
std::vector<Book>* findBooks(int year, const std::vector<Book> &db);

/**
 * Calculate and print the average rating of all the books in the database. 
 * If no books have been added, returns -1.0.
 * 
 * @param &db The vector containing all of the books
 * @return the average rating, or -1.0 if no books have been added
 */
double calculateAverageRating(const std::vector<Book> &db);

/**
 * Prints the contents of the database to cout.
 * 
 * @param &db The vector containing all of the books
 */
void print(const std::vector<Book> &db);

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
int sortDB(std::vector<Book> &db, int sortingMethod);

/**
* Helper method to sort books by ID, returns the smaller ID first
* @return true if a is smaller than b, false otherwise
*/
bool compareByID(const Book &a, const Book &b);

/**
* Helper method to sort books by year, returns the smaller year first
* @return true if a is smaller than b, false otherwise
*/
bool compareByYear(const Book &a, const Book &b);

/**
* Helper method to sort books by rating, returns the smaller rating first
* @return true if a is smaller than b, false otherwise
*/
bool compareByRating(const Book &a, const Book &b);

#endif // BOOKDB_H