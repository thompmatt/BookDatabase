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

* **Matt Thompson** - *Book Database*
