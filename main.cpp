#include "queue.h"

int main()
{
  CustomQueue<int> myQueue;
  char choice = '\0';
  int n;

  while(choice!='0')
  {
    std::cout<<
    "\n1. Add element\n"<<
    "2. Remove element\n"<<
    "3. Get top element\n"<<
    "4. Size of the queue\n"<<
    "5. Clear queue\n"<<
    "6. Print queue\n"<<
    "0. Exit"<<std::endl;

    std::cout<<"Number of command: > ";
    std::cin>>choice;
    switch (choice)
    {
      case '1':
      {
        std::cout<<"Type an item:"<<std::endl;
        std::cin>>n;
        myQueue.Push(n);
        break;
      }
      case '2':
      {
        if (myQueue.IsEmpty())
          std::cout<<"Queue is empty!"<<std::endl;
        else
          myQueue.Pop();
        break;
      }
      case '3':
      {
        if (myQueue.IsEmpty())
          std::cout<<"Queue is empty!"<<std::endl;
        else
          std::cout<<"First element: "<<std::endl;
          myQueue.Top();
        break;
      }
      case '4':
      {
        if (myQueue.IsEmpty())
          std::cout<<"Queue is empty!"<<std::endl;
        else
          std::cout<<"Size of the queue: "<<myQueue.Size()<<std::endl;
        break;
      }
      case '5':
      {
        if (myQueue.IsEmpty())
          std::cout<<"Queue is empty!"<<std::endl;
        else
          myQueue.Clear();
        break;
      }
      case '6':
      {
        if (myQueue.IsEmpty())
          std::cout<<"Queue is empty!"<<std::endl;
        else
          myQueue.Print();
        break;
      }
      case '0':
        break;
      default:
      {
        std::cout<<"Unknown command!"<<std::endl;
        break;
      }
    }
  }
  return 0;
}
