#/////////////////////////////// FILE HEADER ///////////////////////////////////
#/
#/ Title: Book Database Makefile
#/ Files: BookDB.h, BookDB.cpp, demo.cpp, README.md, Makefile
#/ Course: CS 368, Spring 2020
#/
#/ Author: Matt Thompson
#/ Student ID: 9081263262
#/ Email: mathompson23@wisc.edu
#/ Lecturer's Name: Marc Renault
#/
#/ Online Sources: 
#/ - https://stackoverflow.com/questions/409348/iteration-over-stdvector-
#/   	unsigned-vs-signed-index-variable
#/ - https://stackoverflow.com/questions/875103/how-do-i-erase-an-element
#/ 		-from-stdvector-by-index
#/ - https://stackoverflow.com/questions/4892680/sorting-a-vector-of-structs
#/ 
#/////////////////////////// FILE DESCRIPTION /////////////////////////////////
#/ 
#/ This is the makefile for demo.cpp, which displays the Book Database.
#/
#//////////////////////////////////////////////////////////////////////////////

# Makefile

CXX=g++
CXXFLAGS=-Wall

all: build

BookDB.o: BookDB.h

clean:
	-rm BookDB.o
	-rm demo

build: demo.cpp BookDB.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp BookDB.o