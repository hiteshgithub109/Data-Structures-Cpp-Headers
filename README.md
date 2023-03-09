
  

# LinkedList Header
LinkedList header is a C++ header file that provides a simple implementation of basic funtions of Linked list data structure. This header files allows you to use basic LinkedList functions such as empty, push_front, push_back, insert, remove, size, clear and overloaded operator '[]' to access elements via indexing making element accessing same and easy as arrays.The implementation is written in C++ and utilizes templates for increased flexibility and reusability.

  

## Usage

  

### Installation

1. Download **LinkedList.h** header file and **LinkedList.tpp** file from LinkedList folder of this repository.

2. Include the header file in your C++ project.

  

``` C++
#include "LinkedList.h"
```
### Creating LinkedList object.

To create a new LinkedList object, simply type **LinkedList**:

  

``` C++
LinkedList<int> myLinkedList; //creates new empty linked list object which will store data of type "int" only
```  
### Adding or Inserting elements to the LinkedList

To add element at the front or back of the LinkedList use **push_front()** or **push_back()** function, respectively:

``` C++
myLinkedList.push_front(10);
myLinkedList.push_back(20);
```

### Removing element front the LinkedList

To remove an element from the LinkedList use **remove()** function, which takes an index as its argument:
``` C++
myLinkedList.remove(1);//removes the element at first index(second element of the list)
```
### Accessing elements in the LinkedList
You can access elements in the LinkedList using the `[]` operator:
``` C++
int element = myLinkedList[0]; // gets the first element in the LinkedList
```
### Checking the size of the LinkedList
To check the size of the LinkedList, use the `size` function:

``` C++
int size = myLinkedList.size();
```
### Clearing the LinkedList

To clear the LinkedList of all its elements, use the `clear` function:
``` C++
myLinkedList.clear();
```
### Checking if the LinkedList is empty

To check if the LinkedList is empty, use the `empty` function:
``` C++
bool isEmpty = myLinkedList.empty();
```
## Contributing

Contributions are welcome! If you find any bugs or want to add new features, please create a pull request or submit an issue.

## License

This project is licensed under the MIT License - see the [LICENSE](MyLibraryLicense.license) file for details.