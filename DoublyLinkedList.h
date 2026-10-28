#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <string>

struct dNode {
    int bookID;
    std::string title;
    dNode* left;
    dNode* right;

    dNode(int id, const std::string& name);
};

class DoublyLinkedList {
private:
    dNode* head;
    dNode* tail;
    dNode* current;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void InsertRight(dNode* node);
    void Next();
    void Previous();
    void PrintCurrent() const;
    void InsertAfterCurrent(dNode* node);
    dNode* RemoveCurrent();
    void PrintForward() const;
    void PrintBackward() const;
};

#endif
