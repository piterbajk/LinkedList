#include"LinkedList.h"

int main(){

  LinkedList<int> DLL; //Create Doubly Linked List object

  int s;

  do{

    std::cout << "\n# DOUBLY LINKED LIST #\n\
1.Add Front\n\
2.Add Back\n\
3.Add At\n\
4.Remove Front\n\
5.Remove Back\n\
6.Remove\n\
7.Peek Front\n\
8.Peek Back\n\
9.Print\n\
10.Print Reverse\n\
11.Size\n\
12.Check if Empty\n\
13.Return value from position\n\
14.Return index of value\n\
15.Swap Indexes\n\
16.Reverse list\n\
17.Sort" << std::endl << std::endl;

    std::cout << "Choice: ";

    std::cin >> s;

    switch(s){
    case 1:{
      int data;
      std::cin >> data;
      DLL.addFront(data);
      std::cout << "Inserted: " << data << std::endl;
      break;
    }
    case 2:{
      int data;
      std::cin >> data;
      DLL.addBack(data);
      std::cout << "Inserted: " << data << std::endl;
      break;
    }
    case 3:{
      int data, pos;
      std::cin >> data;
      std::cout << "\nEnter position: ";
      std::cin >> pos;
      DLL.addAt(data, pos);
      std::cout << "Inserted: " << data << " at position " << pos << std::endl;
      break;
    }
    case 4: DLL.removeFront(); break;
    case 5: DLL.removeBack(); break;
    case 6:{
      int pos_to_remove;
      std::cin >> pos_to_remove;
      DLL.remove(pos_to_remove);
      break;
    }
    case 7: std::cout << "Front: " << DLL.front() << std::endl; break;
    case 8: std::cout << "Back: " << DLL.back() << std::endl; break;
    case 9: DLL.print(); break;
    case 10: DLL.printReverse(); break;
    case 11: std::cout << "Size: " << DLL.size() << std::endl; break;
    case 12: std::cout << "Empty? " << DLL.isEmpty() << std::endl; break;
    case 13:{
      unsigned pos;
      std::cin >> pos;
      std::cout << "Value on position: " << DLL.atIndex(pos) << std::endl;
      break;
    }
    case 14:{
      unsigned search_for; //By default - unsigned
      std::cin >> search_for;
      std::cout << "Found value on index: " << DLL.indexOf(search_for) << std::endl;
      break;
    }
    case 15:{
      unsigned first, second;
      std::cout << "Enter first index: ";
      std::cin >> first;
      std::cout << "\nEnter second index: ";
      std::cin >> second;
      DLL.swapIndex(first, second);
      break;
    }
    case 16: DLL.reverse(); break;
    case 17: DLL.sortBubble(); break;
    }

  }
  while(s != 0);


  return 0;
}
