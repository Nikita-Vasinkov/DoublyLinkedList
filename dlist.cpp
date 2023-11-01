#include "dlist.h"
#include "polynomials.h"

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
T& Mylist<T>::Iterator::operator*() {
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
bool Mylist<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template <typename T>
void Mylist<T>::AddElementPos(const T& value, typename Mylist<T>::Iterator position){
    if (position == begin()){
        AddElementStart(value);
        return;
    }
    if ((position.current == NULL) || (position == end())) {
        AddElementEnd(value);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = position.current;
    newNode->prev = position.current->prev;
    position.current->prev->next = newNode;
    position.current->next->prev = newNode;
}

template <typename T>
T Mylist<T>::GetElementPos(typename Mylist<T>::Iterator position){
    return *position;
}

template <typename T>
void Mylist<T>::RmElementPos(Iterator position){
    if(position == end()){
        RmLastElement();
    }else{
        position.current->prev->next = position.current->next;
        position.current->next->prev = position.current->prev;
        free(position.current);
    }
}

template <typename T>
void Mylist<T>::Swap(Iterator it1, Iterator it2) {
    T temp = *it1;
    *it1 = *it2;
    *it2 = temp;
}

template <typename T>
typename Mylist<T>::Iterator Mylist<T>::begin() {
    return Iterator(head);
}

template <typename T>
typename Mylist<T>::Iterator Mylist<T>::end() {
    return Iterator(NULL);
}

template <typename T>
typename Mylist<T>::Iterator Mylist<T>::rbegin() {
    return Iterator(tail);
}

template <typename T>
typename Mylist<T>::Iterator Mylist<T>::rend() {
    return Iterator(NULL);
}

template class Mylist<int>;
template class Mylist<char>;
template class Mylist< Mylist<char> >;

