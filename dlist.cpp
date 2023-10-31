#include "dlist.h"

template <typename T>
Mylist<T>::Mylist() {
    head = NULL;
    tail = NULL;
}
template <typename T>
Mylist<T>::~Mylist() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

template <typename T>
Mylist<T>::Mylist(const Mylist& other) {
    head = NULL;
    tail = NULL;

    for (Node* current = other.head; current != NULL; current = current->next) {
        AddElementEnd(current->data);
    }
}

template <typename T>
void Mylist<T>::AddElementEnd(const T& value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;
    
    if (tail != NULL) {
        tail->next = newNode;
    }
    
    tail = newNode;
    
    if (head == NULL) {
        head = newNode;
    }
    // printf("%ld\n", tail - head); - length
}

template <typename T>
void Mylist<T>::AddElementStart(const T& value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL){
        head->prev = newNode;
    }
    
    head = newNode;
    
    if (tail == NULL){
        tail = newNode;
    }
    
}

template <typename T>
void Mylist<T>::RmLastElement() {
    if (tail != NULL) {
        if (head == tail) {
            free(tail);
            head = NULL;
            tail = NULL;
        } else {
            struct Node* prevNode = tail->prev;
            prevNode->next = NULL;
            free(tail);
            tail = prevNode;
        }
    }
}

template <typename T>
Mylist<T>& Mylist<T>::operator=(const Mylist& other) {
    if (this != &other) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
        tail = NULL;

        for (Node* current = other.head; current != NULL; current = current->next) {
            AddElementEnd(current->data);
        }
    }
    return *this;
}

template <typename T>
Mylist<T>::Iterator::Iterator() {
    current = NULL;
}

template <typename T>
Mylist<T>::Iterator::Iterator(struct Node* node) {
    current = node;
}

template <typename T>
int& Mylist<T>::Iterator::operator*() {
    return current->data;
}

template <typename T>
typename Mylist<T>::Iterator& Mylist<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template <typename T>
typename Mylist<T>::Iterator& Mylist<T>::Iterator::operator--() {
    current = current->prev;
    return *this;
}

template <typename T>
bool Mylist<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <typename T>
typename Mylist<T>::Iterator Mylist<T>::begin() {
    return Iterator(head);
}

template <typename T>
typename Mylist<T>::Iterator Mylist<T>::end() {
    return Iterator(NULL);
}

template class Mylist<int>;



