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
        tail = newNode;
        count++;
    }
}

template <typename T>
void LinkedList<T> :: insert(const T& value, int index){
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
        current -> next = newNode;
        count++;
    }
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index >= count || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        Node* nodeToDelete = head;
        head = head -> next;
        delete nodeToDelete;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
        }
        Node* nodeToDelete = current -> next;
        current -> next = current -> next-> next;
        delete nodeToDelete;
    }
    count--;
}

template <typename T>
int LinkedList<T> :: size() const{
    return count;
}

template <typename T>
void LinkedList<T> :: clear(){
    Node *current = head;
    while(current){
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