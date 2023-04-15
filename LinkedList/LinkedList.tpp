#include "LinkedList.h"
#include<stdexcept>

template <typename T>
LinkedList<T> :: LinkedList(): head(nullptr), count(0), tail(nullptr){}

template <typename T>
LinkedList<T> :: ~LinkedList(){
    clear();
}

template <typename T>
bool LinkedList<T> :: empty() const{
    return (head == nullptr || tail == nullptr || count == 0);
}

template <typename T>
void LinkedList<T> :: push_front(const T& value){
    Node* newNode = new Node(value);
    newNode -> next = head;
    if(head != nullptr) head->prev = newNode;
    head = newNode;
    if(empty()) tail = newNode;
    count++;
}

template <typename T>
void LinkedList<T> :: push_back (const T& value){
    if(empty()) push_front(value);
    else{
        Node *newNode = new Node(value);
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
        count++;
    }
}

template <typename T>
void LinkedList<T> :: insert(int index, const T& value){
    if(index >= count || index < 0) 
        throw std:: out_of_range("Index out of range");
    if(index == 0) push_front(value);
    else if(index == count - 1) push_back(value);
    else{
        Node *newNode = new Node(value);
        Node *current = head;
        for(int i = 0; i < index - 1; i++)
            current = current -> next;
        newNode -> next = current -> next;
        current->next->prev = newNode;
        newNode->prev = current;
        current -> next = newNode;
        count++;
    }
}

template<typename T>
void LinkedList<T>::pop_front(){
    Node* nodeToDelete = head;
    head = head -> next;
    head->prev = nullptr;
    delete nodeToDelete;
    count--;
}

template<typename T>
void LinkedList<T>::pop_back(){
    Node* nodeToDelete = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete nodeToDelete;
    count--;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index >= count || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) pop_front();
    else if(index == count-1) pop_back();
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
        }
        Node* nodeToDelete = current -> next;
        current -> next = nodeToDelete-> next;
        nodeToDelete->next->prev = current;
        delete nodeToDelete;
        count--;
    }
}

template<typename T>
T& LinkedList<T>::front() const{
    if(!head) throw std::out_of_range("LinkedList is empty");
    return head->data;
}

template<typename T>
T& LinkedList<T>::back() const{
    if(!head) throw std::out_of_range("LinkedList is empty");
    return tail->data;
}

template<typename T>
int LinkedList<T>::find(const T& element) const{
    for(int i = 0; i < size(); i++){
        if((*this)[i] == element) return i;
    }
    return -1;
}

template<typename T>
void LinkedList<T>::sort() {
    if (!head || !head->next) return; 
    bool swapped;
    Node *current;
    Node *last = nullptr;
    do {
        swapped = false;
        current = head;
        while (current->next != last) {
            if (current->data > current->next->data) {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}


template<typename T>
void LinkedList<T>::reverse() {
    if (count < 2) return;
    Node* current = head;
    Node* previous = nullptr;
    Node* nextnode = nullptr;
    while (current != nullptr) {
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
}

template <typename T>
int LinkedList<T> :: size() const{
    return count;
}

template <typename T>
void LinkedList<T> :: clear(){
    Node *current = head;
    while(current != nullptr){
        head = head -> next;
        delete current;
        current = head;
    }
    count = 0;
}

template <typename T>
T& LinkedList<T> :: operator[](int index) const{
    if (index >= count || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    if(index == 0) return head -> data;
    else if (index == count - 1) return tail -> data;
    else{
        Node *current = head;
        for(int i = 0; i < index; i++){
            current = current -> next;
        }
        return current -> data;
    }
}