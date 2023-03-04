#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 *  @brief LinkedList implementation that supports adding and removing the nodes at the front and back
 *  along with adding and removing at an arbitrary positon in the LinkedList.
 * 
 *  @tparam T The type of element stored in the list.
*/
template<typename T>
class LinkedList{
public:
    /**
     *  @brief A node in the linked list that stores an element of type T and a pointer to the
     *  next node in the list.
     */
    struct Node{
        T data;///< The element stored in the node.
        Node *next;///< A pointer to the next node in the list.
        Node(const T& data): data(data), next(nullptr){}
    };

    /**
     *  @brief Constructor that creates an empty linked list with no nodes.
     */
    LinkedList();

    /**
     *  @brief Destructor that deletes all nodes in the linked list.
     */
    ~LinkedList();

    /**
     *  @brief Add data at the beginning of the LinkedList.
     *  This is a typical list operation. The function creates a node
     *  with the given value and links that node with the list at
     *  front and updates head value to this value.
     * 
     *  @param value data to be added.
     * 
     *  @throws std::bad_alloc if there is not enough memory to create a new node
     * 
     *  @return None
    */
    void push_front(const T& value);

    /**
     *  @brief  Add data to the end of the LinkeList.
     *  This is a typical list operation. The function creates a node
     *  with the given value and links that node with the list at
     *  end and updates head value to this value.
     *  @param  value  Data to be added.
     * 
     *  @throws std::bad_alloc if there is not enough memory to create a new node
     * 
     *  @return None
    */
    void push_back(const T& value);

    /**
     *  @brief Add specified data at specified index in the LinkedList.
     *  This function inserts a new node with the given value at the specified position
     *  in the LinkedList.
     *  If the given index is out of range it throws `std::out_of_range` exception
     * 
     *  @param value data to be added
     *  @param index postition at which the given data is to be added starting from 0
     * 
     *  @throws std::out_of_range Thrown when the index given by user is less
     *  than 0 or greater than the size of LinkedList.
     * 
     *  @return None
     * 
     *  @note When the index is 0, the value is inserted at the beginning of the LinkedList.
     *  When the index is equal to current size the value is inserted at the end of the LinkedList making
     *  making the time complexity for both operation as O(1).
     *  If the specified index is between 0 and current size the the value is inserted at the
     *  specified postition making the time complexity for this operation as O(n), where n is the size of 
     *  LinkedList.
    */
    void insert(const T& value, int index);

    /**
     *  @brief Removes the node at the specified index in the LinkedList.
     *  This function removes an existing node from specified position in the LinkedList.
     *  If the given index is out of range it throws `std::out_of_range` exception
     * 
     *  @param index position from which the data is to be removed
     * 
     *  @return None
     * 
     *  @throws std::out_of_range Thrown when the index given by user is less than 0 or 
     *  greater than the size of LinkedList.
     * 
     *  @note The time complexity of this function is O(n) where n is the size 
     *  of the LinkedList.
    */
    void remove(int index);

    /**
     *  @brief Returns the number of nodes in LinkedList. 
     *  This is a constant function that returns size of current LinkedList.
     * 
     *  @return Size of the LinkedList.
    */
    int size() const;

    /**
     *  @brief Returns whether the list is empty or not.
     *  This is constant function that returns true if the current list is empty otherwise 
     *  it returns false.
     * 
     *  @return LinkedList is empty or not.
     * 
     *  @note This function can be useful  when checking if the LinkedList is empty before
     *  performing certain operations, such as removing a node from the list.
    */
    bool empty() const;

    /**
     *  @brief Clears the current LinkedList by deleting all the nodes and updating count to zero.
     *  This function iterates through each node in the LinkedList and deletes it. It updates the count
     *  of the LinkedList to zero.
    */
    void clear();

    /**
     *  @brief Overloads the [] operator for the LinkedList.
     *  This function allows accessing elements in the LinkedList using
     *  the [] operator, providing a syntax similar to that of arrays.
     *
     *  @param index index of the element to be accessed
     *
     *  @return reference to the data stored in the node at the given index.
     *
     *  @throws std::out_of_range Thrown when the index given by user is less
     *  than 0 or greater than or equal to the size of LinkedList.
    */
    T& operator[](int index) const;
private:
    Node *tail;
    Node *head;
    int count;
};
#include "LinkedList.tpp"
#endif