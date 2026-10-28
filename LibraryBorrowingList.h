#ifndef LIBRARY_BORROWING_LIST_H
#define LIBRARY_BORROWING_LIST_H

#include <string>

struct BorrowingNode {
    int bookID;
    std::string title;
    BorrowingNode* previous;
    BorrowingNode* next;

    BorrowingNode(int id, const std::string& bookTitle);
};

class LibraryBorrowingList {
private:
    BorrowingNode* head;
    BorrowingNode* tail;
    BorrowingNode* current;

public:
    LibraryBorrowingList();
    ~LibraryBorrowingList();

    LibraryBorrowingList(const LibraryBorrowingList&) = delete;
    LibraryBorrowingList& operator=(const LibraryBorrowingList&) = delete;

    void addBookAtEnd(int bookID, const std::string& title);
    void insertAfterCurrent(int bookID, const std::string& title);
    bool moveNext();
    bool movePrevious();
    bool removeCurrent();
    void displayCurrent() const;
    void displayForward() const;
    void displayBackward() const;
    bool isEmpty() const;
};

#endif
