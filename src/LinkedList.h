#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

/**
Class representing Doubly Linked List
 */
template <typename T>
class LinkedList{

  // First and last node on the list
  std::shared_ptr<Node<T>> head, tail;

  // SIze of the list (number of nodes)
  unsigned list_size;

public:

  // Default constructor
  LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

  // Destructor
  ~LinkedList(){
    while( !isEmpty() )
      this->removeBack();
  }

  // Add element to front ( chain method )
  LinkedList<T>& addFront(const T&);

  // Add element to back ( chain method )
  LinkedList<T>& addBack(const T&);

  // Add element to list at given position (index starts from 1)
  LinkedList<T>& addAt(const T&, unsigned int);

  // Peek front element without removing it
  T front() const;

  // Peek back element without removing it
  T back() const;

  // Remove front element
  void removeFront();

  // Remove back element
  void removeBack();

  // Remove element from given position
  void remove(unsigned);

  // Return number of elements on list
  unsigned size() const;

  // Check if list is empty
  bool isEmpty() const;

  // Print list from first to last
  void print() const;

  // Print list from last to first node
  void printReverse() const;

  // Iterate to node at given position and return its value
  T atIndex(unsigned) const;

  // Find given value and return its index
  unsigned indexOf(const T&) const;

  // Replace two values from given node pointers
  void swap(std::shared_ptr<Node<T>>,
            std::shared_ptr<Node<T>>);

  // Replace two values at given indexes
  void swapIndex(unsigned, unsigned);

  // Reverse elements on list
  void reverse();

  // Bubble sort
  void sortBubble();

};

/**
Linked List methods definition
*/


/**
   Function checks if list is empty

   @return True if empty, false if not empty
 */
template <typename T>
bool LinkedList<T>::isEmpty() const{
  return list_size == 0;
}


/**
   Adds element at front of the list

   @param Data to be added
   @return Reference to LinkedList class to allow method chaining
 */
template <typename T>
LinkedList<T>& LinkedList<T>::addFront(const T & _data){

  auto elem =  std::make_shared<Node<T>>(_data);

  // List is empty
  if( isEmpty() )
    head = tail = elem;

  // List is not empty
  else{
    elem->setNext(head);
    head->setPrev(elem);
    head = elem;
  }

  list_size++; // Increment number of elements

  return *this; // Allow method chaining
}


/**
   Adds element at back of the list

   @param Data to be added
   @return Reference to LinkedList class to allow method chaining
*/
template <typename T>
LinkedList<T>& LinkedList<T>::addBack(const T & _data){

  auto elem =  std::make_shared<Node<T>>(_data);

  // List is empty
  if( isEmpty() )
    head = tail = elem;

  // List is not empty
  else{
    elem->setPrev(tail);
    tail->setNext(elem);
    tail = elem;
  }

  list_size++; // Increment number of elements

  return *this; // Allow method chaining
}


/**
   Adds element at given position of the list
   Current element at given pos is moved one node forward

   @param Data to be added and its position on list
   @return Reference to LinkedList class to allow method chaining
*/
template <typename T>
LinkedList<T>& LinkedList<T>::addAt(const T & data, unsigned int pos){

  auto elem =  std::make_shared<Node<T>>(data);

  // Given position is greater than number of elements
  if( pos > list_size+1 || pos < 1 )
    throw std::out_of_range("IncorrectPositionException");

  // Given position is first element
  if( pos == 1 )
    addFront(data); // Add element at front

  // Given position is one after last element
  else if( pos == list_size+1 )
    addBack(data); // Add element at back

  // Given position is not on the verge
  else{

    std::shared_ptr<Node<T>> tmp;

    // Given position is closer to HEAD
    if( pos <= list_size/2 ){

      tmp = head;

      for(unsigned i=1; i < pos; ++i) // Traverse forward till pos reached
        tmp = tmp->getNext();
    }

    // Given position is closer to TAIL
    else{
      tmp = tail;

      for(unsigned i=1; i <= list_size-pos; ++i) // Traverse backwards till pos reached
        tmp = tmp->getPrev(); 
    }

    elem->setNext( tmp ); // Set 'next' in new node to next node
    elem->setPrev( tmp->getPrev() ); // Set 'previous' in new node to previous node
    tmp->getPrev()->setNext( elem ); // Set 'next' in previous node to new node
    tmp->setPrev( elem ); // Set 'previous' in next node to new node

    list_size++; // Increment number of elements
  }

  return *this; // Allow method chaining
}


/**
   Returns element at front of the list

   @return Element at front
 */
template <typename T>
T LinkedList<T>::front() const{
  return head->getData();
}


/**
   Returns element at back of the list

   @return Element at back
*/
template <typename T>
T LinkedList<T>::back() const{
  return tail->getData();
}


/**
   Removes element from front
*/
template <typename T>
void LinkedList<T>::removeFront(){

  // List is empty
  if( isEmpty() )
    throw std::out_of_range("EmptyListException");

  // List is not empty
  else{
    std::shared_ptr<Node<T>> elem = head;
    head = head->getNext();
    list_size--;
  }
}


/**
   Removes element from back
*/
template <typename T>
void LinkedList<T>::removeBack(){

  // List is empty
  if( isEmpty() )
    throw std::out_of_range("EmptyListException");

  // List is not empty
  else{
    std::shared_ptr<Node<T>> elem = tail;
    tail = tail->getPrev();
    list_size--;
  }
}


/**
   Removes element from given position

   @param Position of element to be deleted
*/
template <typename T>
void LinkedList<T>::remove(unsigned int pos){

  // Given position is greater than number of elements
  if( pos > list_size+1 || pos < 1 )
    throw std::out_of_range("IncorrectPositionException");

  // Given position is first element
  if( pos == 1 )
    removeFront(); // Remove front node and set head to next

  // Given position is last element
  else if( pos == list_size )
    removeBack(); // Remove last node and set tail to previous

  // Given position is not on the verge
  else{

    std::shared_ptr<Node<T>> tmp;

    // Given position is closer to HEAD
    if( pos <= list_size/2 ){

      tmp = head;

      for(unsigned i=1; i < pos; ++i) // Traverse forward till pos reached
        tmp = tmp->getNext();
    }

    // Given position is closer to TAIL
    else{
      tmp = tail;

      for(unsigned i=1; i <= list_size-pos; ++i) // Traverse backwards till pos reached
        tmp = tmp->getPrev(); 
    }

    tmp->getPrev()->setNext( tmp->getNext() ); // Point previous 'next' to next
    tmp->getNext()->setPrev( tmp->getPrev() ); // Point next 'prev' to previous

    list_size--; // Decrease number of elements
  }
}


/**
   Prints whole list (from HEAD to TAIL), iterating through nodes

   NOTICE: '<<'' operator for T class must be overloaded
*/
template <typename T>
void LinkedList<T>::print() const{

  std::shared_ptr<Node<T>> ptr = head;

  // List is empty
  if( isEmpty() ){
    std::cout << "List empty" << std::endl;
    return;
  }

  std::cout << "FRONT" << std::endl;

  // Print elements from head to tail
  for(unsigned i=0; i < list_size; ++i ){
    std::cout << ptr->getData() << std::endl;
    ptr = ptr->getNext();
  }

  std::cout << "BACK" << std::endl;
}


/**
   Prints whole list backwards (from TAIL to HEAD), iterating through nodes

   NOTICE: '<<'' operator for T class must be overloaded
*/
template <typename T>
void LinkedList<T>::printReverse() const{

  std::shared_ptr<Node<T>> ptr = tail;

  // List is empty
  if( isEmpty() ){
    std::cout << "List empty" << std::endl;
    return;
  }

  std::cout << "BACK" << std::endl;

  // Print elements from tail to head
  for(unsigned i = 0; i < list_size; ++i ){
    std::cout << ptr->getData() << std::endl;
    ptr = ptr->getPrev();
  }

  std::cout << "FRONT" << std::endl;
}


/**
   Returns number of nodes on list

   @return List size
 */
template <typename T>
unsigned LinkedList<T>::size() const{
  return this->list_size;
}


/**
   Returns the value of node at given index

   @param Index of element
   @return Value of node at given index
 */
template <typename T>
T LinkedList<T>::atIndex(unsigned pos) const {

  // Given position is greater than number of elements
  if( pos > list_size || pos < 1 )
    throw std::out_of_range("IncorrectPositionException");

  std::shared_ptr<Node<T>> tmp;

  // Given position is closer to HEAD
  if( pos <= list_size/2 ){

    tmp = head;

    for(unsigned i=1; i < pos; ++i) // Traverse forward till pos reached
      tmp = tmp->getNext();
  }

  // Given position is closer to TAIL
  else{
    tmp = tail;

    for(unsigned i=1; i <= list_size-pos; ++i) // Traverse backwards till pos reached
      tmp = tmp->getPrev(); 
  }

  return  tmp->getData();
}


/**
   Returns index of first element with given value or zero if
   element doesn't exist

   @param Value to be found
   @return Index of node with given value or 0 if no such node
 */
template <typename T>
unsigned LinkedList<T>::indexOf(const T& to_be_found ) const{

  // List is empty
  if( isEmpty() )
    throw std::out_of_range("EmptyListException");

  std::shared_ptr<Node<T>> tmp = head;
  unsigned counter = 0;

  while(tmp && tmp->getData() != to_be_found ){ // Traverse forward till value found
    tmp = tmp->getNext();
    counter++;
  }

  // Returns index of node OR  '0' if not found such value
  return tmp ? counter+1 : 0;
}


/**
   Swap the value of elements at given indexes

   @param Index of first node, Index of second node
 */
template <typename T>
void LinkedList<T>::swapIndex(unsigned int index1,
                              unsigned int index2){

  // Given position is greater than number of elements
  if( index1 > list_size || index2 > list_size || index1 < 1 || index2 < 1)
    throw std::out_of_range("IncorrectPositionException");

  // Two positions are the same
  if(index1 == index2)
    return; // Do nothing

  // Create two auxiliary pointers to traverse to nodes at given positions
  std::shared_ptr<Node<T>> ptr_one = head;
  std::shared_ptr<Node<T>> ptr_two = head;

  for(unsigned i=1; i < index1; ++i) // Traverse forward till index1 reached
    ptr_one = ptr_one->getNext();

  for(unsigned i=1; i < index2; ++i) // Traverse forward till index2 reached
    ptr_two = ptr_two->getNext();

  T temp = ptr_one->getData(); // Assign data from first node to temporary

    // Do the swap
    ptr_one->setData( ptr_two->getData() );
    ptr_two->setData( temp );

}


/**
   Swap the value of elements given as arguments

   @param Pointer to first node, Pointer to second node
 */
template <typename T>
void LinkedList<T>::swap(std::shared_ptr<Node<T>> lhs,
                         std::shared_ptr<Node<T>> rhs){

  T tmp = rhs->getData();
  rhs->setData( lhs->getData() );
  lhs->setData( tmp );

}


/**
   Reverses all elements on list
 */
template <typename T>
void LinkedList<T>::reverse(){

  // List is empty
  if( isEmpty() )
    throw std::out_of_range("EmptyListException");

  for(unsigned i=1; i <= list_size/2; ++i)
    swapIndex(i, list_size+1-i);

}


/**
   Bubble sorting of elements on list
 */
template <typename T>
void LinkedList<T>::sortBubble(){

  // List is empty
  if( isEmpty() )
    throw std::out_of_range("EmptyListException");

  // List is not empty
  else{

    std::shared_ptr<Node<T>> lhs, rhs;
    bool swap_done = true;

    // Do the bubble sort till no more swap occur
    while( swap_done ){

      lhs = head;
      rhs = head->getNext();

      swap_done = false;

      while ( rhs != nullptr ){ // Move till last element

        // Push larger elements down
        if( lhs->getData() > rhs->getData() ){
          swap( lhs, rhs );
          swap_done = true; // True if any swap done
        }

        // Move both pointers next node forward
        lhs = rhs;
        rhs = rhs->getNext();
      }
    }
  }
}

#endif
