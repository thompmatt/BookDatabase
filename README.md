/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: README.md for Book Database
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
// This README.md file explains what the Book Database program does, how it is
// organized, how to compile, and how to run the code.
//
///////////////////////////////////////////////////////////////////////////////


# Book Database

The Book Database program is a "library" of books that are stored in a vector of type Book. Each book contains three main elements: ID, year, and rating. This program has the functions of adding a book into the database, deleting a book from the database using the book's ID, updating a book from the database using the book's ID, calculating the average rating of all the books inside the database, printing the contents of the database, finding a book inside the database by year, and sorting the books in the database by ID, year or rating.

## Organization

The code is organized into three files: BookDB.h, BookDB.cpp and demo.cpp. This program also includes a Makefile. Inside the BookDB.h header file, all the functions are included but not defined. The BookDB.cpp file includes the header file and defines all the function bodies, going into detail on how they all work. Finally, demo.cpp runs the main method, which contains a while loop that runs the program continuously until the user enters 'q' (quit command).

## Compiling and running code

To compile the code:
- Open Terminal
- Navigate towards the location of the files / Makefile.
- Type "make" onto the terminal.

To run the code:
- After compiling, type "./demo"

## Author

* **Matt Thompson** - *Math Library*