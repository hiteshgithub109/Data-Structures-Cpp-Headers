#include "LinkedList.h"
#include<iostream>
using namespace std;
int main(){
    cout<<"\n***********************************************************************************";
    cout<<"\nThis is the testing file to check whether all functions are working properly or not";
    cout<<"\n***********************************************************************************\n";
    //creating a LinkedList object
    LinkedList<int> list;

    //testing push_front()
    for(int i = 5; i > -1; i--) list.push_front(i);

    //testing push_back()
    for(int i = 6; i < 12; i++) list.push_back(i);

    //testing overloaded operator [] by accessing elements using loop and size too at the same time
    for(int i = 0; i < list.size(); i++) cout<<list[i]<<" ";
    
    cout<<endl;

    //using remove()
    list.remove(5);

    //using insert();
    list.insert(5, 15);
    cout<<"After insertion at index 5 of number 15: ";
    for(int i = 0; i < list.size(); i++) cout<<list[i]<<" ";

    //using pop_front() and pop_back();
    list.pop_front();
    list.pop_back();

    //using front() and back() methods
    int f = list.front();
    int b = list.back();
    cout<<"\nFront and back elements(after pop_front() and pop_back()) respectively are: "<<f<<" and "<<b;

    //testing size()
    cout<<"\nSize: "<<list.size();

    //testing find()
    cout<<"\nThe element 10 is present at index: "<<list.find(10);

    //testing sort() and then reverse()
    list.sort();
    list.reverse();
    cout<<"\nThe descending order of list is: ";
    for(int i = 0; i < list.size(); i++) cout<<list[i]<<" ";

    //testing clear() and checking the list is empty after clear() and before clear()
    cout<<"\nBefore clear: "<<list.empty();
    list.clear();
    cout<<"\nAfter clear: "<<list.empty();
    cout<<endl;
}