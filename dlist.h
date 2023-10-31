#ifndef DLIST_H
#define DLIST_H

#include <stdio.h>
#include <stdlib.h>

template <typename T>
class Mylist {
private:
    struct Node {
        T data;
        struct Node* next;
        struct Node* prev;
    };
    Node* head;
    Node* tail;

public:
    Mylist();
    ~Mylist();
    Mylist(const Mylist& other);
    void AddElementEnd(const T& value);
    void AddElementStart(const T& value);
    void RmLastElement();
    Mylist& operator=(const Mylist& other);

    class Iterator {
    private:
        struct Node* current;

    public:
        Iterator();
        Iterator(struct Node* node);
        int& operator*();
        Iterator& operator++();
        Iterator& operator--();
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

#endif



