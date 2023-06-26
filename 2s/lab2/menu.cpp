#include "Array.h"
#include "ArraySequence.h"
#include "List.h"
#include "ListSequence.h"
#include "Sequence.h"
#include <iostream>
#include <time.h>
template <typename T> 
T reducer(T a, T b) {
  return a+b;
}

template <typename T> 
T mapper(T a) {
  return a*2;
}

template <typename T> 
bool wherer(T a) {
  return a < 3;
}

template <typename T> 
int main_t() {
  int object;
  int length;
  int choice;
  int position;
  int startIndex;
  int endIndex;
  T value;
  Sequence<T> *seq;
  Sequence<T> *res;
  std::cout << "Choose object to create: " << std::endl;
  std::cout << "0 - ArraySequence, 1 - ListSequence" << std::endl;
  std::cin >> object;
  switch (object) {
  case 0:
    seq = new ArraySequence<T>();
    break;
  case 1:
    seq = new LinkedListSequence<T>();
    break;
  }
  std::cout << "Lenght: " << std::endl;
  std::cin >> length;
  for (int i = 0; i < length; i++) {
    std::cin >> value;
    seq->Append(value);
  }
 
  do {
      std::cout << "----------- Sequence Menu -----------" << std::endl;
      std::cout << "1. Print" << std::endl;
      std::cout << "2. Append" << std::endl;
      std::cout << "3. Prepend" << std::endl;
      std::cout << "4. Insert At Position" << std::endl;
      std::cout << "5. Concat" << std::endl;
      std::cout << "6. GetSubsequence" << std::endl;
      std::cout << "7. Map" << std::endl;
      std::cout << "8. Where" << std::endl;
      std::cout << "9. Reduce" << std::endl;
      std::cout << "10. Exit" << std::endl;
      std::cout << "----------------------------------------" << std::endl;
      std::cout << "Enter your choice: ";
      std::cin >> choice;
      std::cout << std::endl;
      switch (choice) {
          case 1:
            std::cout << "seq = " << seq;
            break;
          case 2:
            std::cin >> value;
            seq->Append(value);  
            break;
          case 3:
            std::cin >> value;
            seq->Prepend(value);  
            break;
          case 4:
            std::cin >> value;
            std::cin >> position;
            seq->InsertAt(value, position);  
            break;
          case 5:
            res = seq->Concat(seq);
            delete seq;
            seq = res;
            break;
          case 6:
            std::cin >> startIndex;
            std::cin >> endIndex;
            res = seq->GetSubsequence(startIndex, endIndex);
            delete seq;
            seq = res;
            break;
          case 7:
            res = seq->Map(mapper);
            delete seq;
            seq = res;
            break;
          case 8:
            res = seq->Where(wherer);
            delete seq;
            seq = res;
            break;
          case 9:
            std::cout << seq->Reduce(reducer, 0) << std::endl;
            break;
          case 10:
            std::cout << "Exiting... " << std::endl;
            delete seq;
            break;
          default: 
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
  
      }
  } while (choice != 10);
  
  return 0;
}

int main() {
  srand(time(nullptr));
  std::cout << "Choose stored type:" << std::endl;
  std::cout << "0 - integer, 1 - real" << std::endl;
  int type;
  std::cin >> type;
  switch (type) {
  case 0:
    return main_t<int>();
  case 1:
    return main_t<double>();
  }
}