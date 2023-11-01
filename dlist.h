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
        friend class Mylist;
        Iterator();
        Iterator(struct Node* node);
        T& operator*();
        Iterator& operator++();
        Iterator& operator--();
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
    };
    
    void AddElementPos(const T& value,Iterator position);
    void RmElementPos(Iterator position);
    void Swap(Iterator it1, Iterator it2);

    T GetElementPos(Iterator position);

    Iterator begin();
    Iterator rbegin();
    Iterator end();
    Iterator rend();
};

#endif


