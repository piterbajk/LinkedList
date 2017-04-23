#ifndef TEST_H
#define TEST_H

#include "gtest/gtest.h"
#include "LinkedList.h"

/**
Testing some functions for their proper response.
All tests are conducted on int type.
Given index numeration and size have to be casted to 
unsigned type to prevent compilation warnings. 
 */

//Testing size of newly created list
TEST(LinkedListTest, New) {
  LinkedList<int> list;
  EXPECT_EQ((unsigned)0, list.size());
}

// Add & Remove Front
TEST(LinkedListTest, AddRemoveFront) {
  LinkedList<int> list;

  list.addFront(1);
  list.addFront(10);
  list.addFront(100);

  EXPECT_EQ((unsigned)3, list.size());
  
  EXPECT_EQ(100, list.front());
  list.removeFront();
  EXPECT_EQ(10, list.front());
  list.removeFront();
  EXPECT_EQ(1, list.front());
  list.removeFront();

  EXPECT_EQ((unsigned)0, list.size()); 
}


// Add & Remove Back
TEST(LinkedListTest, AddRemoveBack) {
  LinkedList<int> list;

  list.addBack(1);
  list.addBack(10);
  list.addBack(100);

  EXPECT_EQ((unsigned)3, list.size());
  
  EXPECT_EQ(100, list.back());
  list.removeBack();
  EXPECT_EQ(10, list.back());
  list.removeBack();
  EXPECT_EQ(1, list.back());
  list.removeBack();

  EXPECT_EQ((unsigned)0, list.size()); 
}


// Add & Remove At Position
TEST(LinkedListTest, AddRemovePosition) {
  LinkedList<int> list;

  list.addAt(1, 1); // List 1 - X - X
  list.addAt(10, 2); // List 1 - 10 - X
  list.addAt(100, 1); // List 100 - 1 - 10

  EXPECT_EQ((unsigned)3, list.size());
  
  EXPECT_EQ(100, list.front());
  list.remove((unsigned)1);
  EXPECT_EQ(10, list.back());
  list.remove((unsigned)2);
  EXPECT_EQ(1, list.back());
  list.remove((unsigned)1);

  EXPECT_EQ((unsigned)0, list.size()); 
}


// Get index of element
TEST(LinkedListTest, GetIndex) {
  LinkedList<int> list;

  list.addBack(2);
  list.addBack(20);
  list.addBack(200);

  EXPECT_EQ((unsigned)1, list.indexOf(2) );
  EXPECT_EQ((unsigned)2, list.indexOf(20) );
  EXPECT_EQ((unsigned)3, list.indexOf(200) );
}


//Check element at index
TEST(LinkedListTest, CheckIndex) {
  LinkedList<int> list;

  list.addBack(2);
  list.addBack(20);
  list.addBack(200);

  EXPECT_EQ(200, list.atIndex((unsigned)3) );
  EXPECT_EQ(20, list.atIndex((unsigned)2) );
  EXPECT_EQ(2, list.atIndex((unsigned)1) );
}


//Bubble sort check
TEST(LinkedListTest, BubbleSort) {
  LinkedList<int> list;

  list.addBack(100);
  list.addBack(50);  
  list.addBack(70);  
  list.addBack(120);
  list.addBack(10);

  //List order
  // 100-50-70-120-10
  
  list.sortBubble();

  //List order
  // 10-50-70-100-120
  
  EXPECT_EQ(120, list.atIndex((unsigned)5) );
  EXPECT_EQ(100, list.atIndex((unsigned)4) );
  EXPECT_EQ(70, list.atIndex((unsigned)3) );
  EXPECT_EQ(50, list.atIndex((unsigned)2) );
  EXPECT_EQ(10, list.atIndex((unsigned)1) );
}

#endif // TEST_H
