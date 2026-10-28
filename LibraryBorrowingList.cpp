#include "LibraryBorrowingList.h"
#include <iostream>

using namespace std;

BorrowingNode::BorrowingNode(int id, const string& bookTitle) {
    bookID = id;
    title = bookTitle;
    previous = nullptr;
    next = nullptr;
}

LibraryBorrowingList::LibraryBorrowingList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

LibraryBorrowingList::~LibraryBorrowingList() {
    BorrowingNode* node = head;
    while (node != nullptr) {
        BorrowingNode* nextNode = node->next;
        delete node;
        node = nextNode;
    }
}

bool LibraryBorrowingList::isEmpty() const {
    return head == nullptr;
}

void LibraryBorrowingList::addBookAtEnd(int bookID, const string& title) {
    BorrowingNode* node = new BorrowingNode(bookID, title);
    node->previous = tail;

    if (tail != nullptr) {
        tail->next = node;
    } else {
        head = node;
    }

    tail = node;

    if (current == nullptr) {
        current = node;
    }
}

void LibraryBorrowingList::insertAfterCurrent(int bookID, const string& title) {
    if (current == nullptr) {
        addBookAtEnd(bookID, title);
        return;
    }

    BorrowingNode* node = new BorrowingNode(bookID, title);
    node->previous = current;
    node->next = current->next;

    if (current->next != nullptr) {
        current->next->previous = node;
    } else {
        tail = node;
    }

    current->next = node;
    current = node;
}

bool LibraryBorrowingList::moveNext() {
    if (current == nullptr || current->next == nullptr) {
        return false;
    }

    current = current->next;
    return true;
}

bool LibraryBorrowingList::movePrevious() {
    if (current == nullptr || current->previous == nullptr) {
        return false;
    }

    current = current->previous;
    return true;
}

bool LibraryBorrowingList::removeCurrent() {
    if (current == nullptr) {
        return false;
    }

    BorrowingNode* removed = current;
    BorrowingNode* previousNode = current->previous;
    BorrowingNode* nextNode = current->next;

    if (previousNode != nullptr) {
        previousNode->next = nextNode;
    } else {
        head = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->previous = previousNode;
    } else {
        tail = previousNode;
    }

    current = nextNode != nullptr ? nextNode : previousNode;
    delete removed;
    return true;
}

void LibraryBorrowingList::displayCurrent() const {
    if (current == nullptr) {
        cout << "No book is selected in the borrowing session.\n";
        return;
    }

    cout << "Current book: " << current->bookID << " - "
         << current->title << '\n';
}

void LibraryBorrowingList::displayForward() const {
    cout << "\nBorrowing Session (First to Last)\n";

    for (BorrowingNode* node = head; node != nullptr; node = node->next) {
        cout << node->bookID << " - " << node->title;
        if (node == current) {
            cout << " [CURRENT]";
        }
        cout << '\n';
    }

    if (head == nullptr) {
        cout << "The borrowing session is empty.\n";
    }
}

void LibraryBorrowingList::displayBackward() const {
    cout << "\nBorrowing Session (Last to First)\n";

    for (BorrowingNode* node = tail; node != nullptr; node = node->previous) {
        cout << node->bookID << " - " << node->title;
        if (node == current) {
            cout << " [CURRENT]";
        }
        cout << '\n';
    }

    if (tail == nullptr) {
        cout << "The borrowing session is empty.\n";
    }
}
