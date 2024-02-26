/**
 *Name: Callie Walker & Emma Smith 
 *Assignment: 1
 *Due 2/26/24
 *Purpose: The purpose of this program is to create a Circular Queue in C++
 *
 *COMPILER: compiled using C++20
 */


#include <iostream>
#include <float.h>
using namespace std;

class CircularQueue
{
    private:

      int First; //position for First/Front/Head
      int Last; //position for Last/Rear/tail

      int MaxCapacity; //Maximum capacity for items
      double* Items; //The actual items stored in the queue


     public:
      CircularQueue(int N); //Allocates double array for N items, set Maximum capacity as N, and intialize First and Last

      ~CircularQueue(); // Destructor will deallocate the double array

      void enqueue(double newItem); //Enqueues newitem
      double dequeue(); // Dequeues the appropriate item and returns it
      bool  isEmpty(); //Verifies if the queue is empty 
      bool isFull(); //Verifies if the queue is full
      int size(); //Returns how many items are in the queue (not the same as MaxCapacity)

};

CircularQueue::CircularQueue(int N)
{
  Items = new double[N];
  MaxCapacity = N; 
  First = -1;
  Last = -1;
}

CircularQueue::~CircularQueue()
{
  while(!isEmpty())
  {
    dequeue();	  
  }
}

void CircularQueue::enqueue(double newItem)
{
  if(isFull())
  {
    printf("Queue is full");
    //return;?
  }
  else if(First == -1 ) //isEmpty
  {
    First = 0;
    Last = 0;
    Items[0] = newItem;
  }
  else if(Last == (size() - 1) && First != 0) //an Item was dequeued from the front
  {
    Last = 0;
    Items[Last] = newItem;
  }
  else
  { 
    Last++;
    Items[Last] = newItem;
  }
}

double CircularQueue::dequeue()
{
  if(isEmpty())
  {
    perror("queue is empty");
    exit(-1);
  }
  else
  {
    double popped = Items[First];
    Items[First] = -1.0;
  
    if(First == Last)
    {
      First = -1;
      Last  = -1;
      return popped;
    } 
    else if(First != Last)
    {
      First++;
      return popped;
    }
  }
  exit(-1);
}

bool CircularQueue::isEmpty()
{
  return size() == 0;
}

bool CircularQueue::isFull()
{
  if(First == 0 && Last == MaxCapacity - 1) //is ||(last +1 % size == first) neceessary
  {
    return true;
  } 
  return false;
}

int CircularQueue::size()
{
  return (Last - First) + 1;
}

int main()
{
  CircularQueue cq(4);
  double item1 = 2.4;
  cq.enqueue(item1);

  cout << cq.size() << "\n";
  
  return 0;
}
