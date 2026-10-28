Lab 07 - Part B: Doubly Linked List in a Library Management System

Purpose:
This separate console example applies a doubly linked list to a library borrowing session.
Each node stores a book ID, title, previous pointer, and next pointer. The current pointer
lets the librarian move forward and backward, insert a book after the selected book, and
remove the selected book.

Files:
- main.cpp
- LibraryBorrowingList.h
- LibraryBorrowingList.cpp

Compile:
g++ main.cpp LibraryBorrowingList.cpp -std=c++17 -o partb

Run on Windows:
partb.exe

Run on Linux/macOS:
./partb

This is a standalone Part B demonstration and does not connect to the SQL Server database
or replace the existing Library Management System backend.
