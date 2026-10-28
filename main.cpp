#include <iostream>
#include <limits>
#include <string>
#include "LibraryBorrowingList.h"

using namespace std;

int main() {
    LibraryBorrowingList borrowingSession;
    int choice;

    borrowingSession.addBookAtEnd(201, "Data Structures");
    borrowingSession.addBookAtEnd(202, "Database Systems");
    borrowingSession.addBookAtEnd(203, "Operating Systems");

    do {
        cout << "\nLibrary Management System - Borrowing Session\n";
        cout << "1. Display Current Book\n";
        cout << "2. Move to Next Book\n";
        cout << "3. Move to Previous Book\n";
        cout << "4. Add Book to Borrowing Session\n";
        cout << "5. Insert Book After Current Book\n";
        cout << "6. Remove Current Book\n";
        cout << "7. Display Session Forward\n";
        cout << "8. Display Session Backward\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number from 1 to 9.\n";
            continue;
        }

        if (choice == 1) {
            borrowingSession.displayCurrent();
        } else if (choice == 2) {
            if (!borrowingSession.moveNext()) {
                cout << "There is no next book.\n";
            } else {
                borrowingSession.displayCurrent();
            }
        } else if (choice == 3) {
            if (!borrowingSession.movePrevious()) {
                cout << "There is no previous book.\n";
            } else {
                borrowingSession.displayCurrent();
            }
        } else if (choice == 4 || choice == 5) {
            int id;
            string title;

            cout << "Enter book ID: ";
            if (!(cin >> id)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid book ID.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter book title: ";
            getline(cin, title);

            if (choice == 4) {
                borrowingSession.addBookAtEnd(id, title);
            } else {
                borrowingSession.insertAfterCurrent(id, title);
            }

            cout << "Book added to the borrowing session.\n";
        } else if (choice == 6) {
            if (borrowingSession.removeCurrent()) {
                cout << "Current book removed from the borrowing session.\n";
                borrowingSession.displayCurrent();
            } else {
                cout << "There is no book to remove.\n";
            }
        } else if (choice == 7) {
            borrowingSession.displayForward();
        } else if (choice == 8) {
            borrowingSession.displayBackward();
        } else if (choice == 9) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Select a number from 1 to 9.\n";
        }
    } while (choice != 9);

    return 0;
}
