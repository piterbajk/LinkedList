#include<iostream>
#include<stdexcept>
#include<memory>
#include<vector>

#ifndef NODE_TEST_H
#define NODE_TEST_H

/**
   Class representing single element on list
*/
template <typename T>
class Node{

  //Variable storing data in node
  T data;

  //Pointers to next and previous node
  std::shared_ptr<Node<T>> next, prev;

 public:

  //Default constructor
 Node() : next(nullptr), prev(nullptr) {}

  //Constructor with parameters ( data, next, previous )
  Node(const T& _data, Node<T>* n = nullptr, Node<T>* p = nullptr) : data(_data), next(n), prev(p) {}

  //Destructor
  ~Node(){ next = prev = nullptr; }

  //Returns data from node
  T  getData() const;

  //Sets data in node
  void setData(const T&);

  //Returns pointer to next node
  std::shared_ptr<Node<T>> getNext() const;

  //Sets next node
  void setNext(std::shared_ptr< Node<T> >);

  //Returns pointer to previous node
  std::shared_ptr<Node<T>> getPrev() const;

  //Sets previous node
  void setPrev(std::shared_ptr<Node<T>>);
};

/**
Node methods definition
*/

/**
   Returns data

   @return The data in node
 */
template <typename T>
T Node<T>::getData() const{
  return data;
}

/**
   Returns pointer to next node

   @return Pointer to next node
 */
template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNext() const{
  return this->next;
}

/**
   Returns pointer to previous node

   @return Pointer to previous node
 */
template <typename T>
std::shared_ptr<Node<T>> Node<T>::getPrev() const{
  return this->prev;
}

/**
   Sets data to node

   @param Data to be set in the node
*/
template <typename T>
void Node<T>::setData(const T& _data){
  data = _data;
}

/**
   Sets next node to current

   @param Pointer to next node
*/
template <typename T>
void Node<T>::setNext(std::shared_ptr<Node<T>> _next){
  next = _next;
}

/**
   Sets previous node to current

   @param Pointer to previous node
*/
template <typename T>
void Node<T>::setPrev(std::shared_ptr<Node<T>> _prev){
  prev = _prev;
}


#endif
