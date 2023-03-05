#include "LinkedList.h"
#include<iostream>
using namespace std;
int main(){
    cout<<"\n***********************************************************************************";
    cout<<"\nThis is the testing file to check whether all functions are working properly or not";
    cout<<"\n***********************************************************************************\n";
    int i;
    LinkedList<int> l;
    for( i = 4; i >= 0; i--)
    l.push_front(i);
    for( i = 6; i <= 10; i++)
    l.push_back(i);
    l.insert(5, 5);
    cout<<"\nThe size of current list is: "<<l.size()<<"\nThe elements in the list are: "<<endl;
    for( i = 0; i < l.size(); i++)
    cout<<l[i]<<" ";
    cout<<endl;
    l.remove(0);
    cout<<"\nAfter removing element at index zero the size of the list is: "<<l.size();
    cout<<"\nThe updated list is: ";
    for(i = 0; i < l.size(); i++)
    cout<<l[i]<<" ";
    cout<<endl;
    l.clear();
    cout<<"\nWhether the list is cleared or not: ";
    if(l.empty() == 1) cout<<"true";
    else cout<<"false";
}