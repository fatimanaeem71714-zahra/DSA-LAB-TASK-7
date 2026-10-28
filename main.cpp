#include <iostream>
#include <limits>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    DoublyLinkedList session;
    int choice;

    session.InsertRight(new dNode(101, "Data Structures"));
    session.InsertRight(new dNode(102, "Database Systems"));
    session.InsertRight(new dNode(103, "Operating Systems"));

    do {
        cout << "\nLibrary Borrowing Session\n";
        cout << "1. Display Current Book\n";
        cout << "2. Move to Next Book\n";
        cout << "3. Move to Previous Book\n";
        cout << "4. Insert Book at the End\n";
        cout << "5. Insert Book After Current Book\n";
        cout << "6. Remove Current Book\n";
        cout << "7. Display Session from First to Last\n";
        cout << "8. Display Session from Last to First\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number from 1 to 9.\n";
            continue;
        }

        if (choice == 1) {
            session.PrintCurrent();
        } else if (choice == 2) {
            session.Next();
            session.PrintCurrent();
        } else if (choice == 3) {
            session.Previous();
            session.PrintCurrent();
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

            dNode* node = new dNode(id, title);

            if (choice == 4) {
                session.InsertRight(node);
            } else {
                session.InsertAfterCurrent(node);
            }

            cout << "Book inserted successfully.\n";
        } else if (choice == 6) {
            dNode* removed = session.RemoveCurrent();

            if (removed != nullptr) {
                cout << "Removed book: " << removed->bookID << " - "
                     << removed->title << '\n';
                delete removed;
            } else {
                cout << "There is no book to remove.\n";
            }
        } else if (choice == 7) {
            session.PrintForward();
        } else if (choice == 8) {
            session.PrintBackward();
        } else if (choice == 9) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Select a number from 1 to 9.\n";
        }
    } while (choice != 9);

    return 0;
}
