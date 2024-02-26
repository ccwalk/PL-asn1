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
      
      CircularQueue operator+(CircularQueue);
      double operator[](int);
      bool operator==(CircularQueue q1);
      bool operator!=(CircularQueue q1);
      friend std::ostream &operator<<(ostream&, CircularQueue);
      void operator<<(double);      
      void operator>>(double*);
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
  
    if(First == Last) //queue is now empty after popping
    {
      First = -1;
      Last  = -1;
      return popped;
    } 
    else if(First != Last) //queue is not empty after pop
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
  if(First == 0 && Last == MaxCapacity - 1)
  {
    return true;
  } 
  return false;
}

int CircularQueue::size()
{
  if(First == -1 && Last == -1) 
  {
     return 0;
  }
  return (Last - First) + 1;
}
//overloads == operator
bool CircularQueue::operator==(CircularQueue q1)
{
  if(this->size() != q1.size())
  { 
    return false;
  }
  for(int i = 0; i < this->size(); i++)
  {
    if(this->Items[(First +i) % MaxCapacity] != q1.Items[(q1.First+i) % q1.MaxCapacity])
    {
      return false;
    }
  }
  return true;
}
//overloads addition operator
CircularQueue CircularQueue::operator+(CircularQueue q2)
{
  int sz1 = this->size();
  int sz2 = q2.size();
  int max = 0;

  if(sz1 > sz2)
  {
    max = sz1;
  }
  else
  {
    max = sz2;
  }

  CircularQueue Result(max);

  for(int i = 0; i < max; i++)
  {
    Result.enqueue(0);
  }

  for(int i = 0; i < sz1; i++)
  {
    Result.Items[i] += Items[First + i];
  }

  for(int i = 0; i <= sz2; i++)
  {
    Result.Items[i] += q2.Items[q2.First + i];
  }

  return Result;

}
//overloads array access
double CircularQueue::operator[](int index)
{
  if(index == -1)
  {
    return Items[Last];

  }
  else if(index < 0)
  {
    perror("Index != -1 and < 0");
  }

  return Items[First + index];

}
//overloads != operator
bool CircularQueue::operator!=(CircularQueue q1)
{
  return !(*this==q1);
}

//standard out overloading
std::ostream& operator<<(ostream& o, CircularQueue q1)
{
  for(int i = 0; i < q1.size(); i++)
  {
    o << q1.Items[(q1.First + i) % q1.MaxCapacity] << ", "; 
  }
  return o;
}

//overloads << to enqueue
void CircularQueue::operator<<(double a)
{
  this->enqueue(a);
}

//overloads >> to dequeue
void CircularQueue::operator>>(double* d)
{
  *(d) =  this->dequeue();
}

int main()
{
  CircularQueue cq(4);
  CircularQueue cq2(5);
  
  double item1 = 2.4;
  double item2 = 3.2;
  double item3 = 10.1;

  double dd;
  double* d = &dd;

  CircularQueue queue3(4), queue4(3);

  double item4 = 2.4;
  double item5 = 3.5;
  double item6 = 4.6;

  double item7 = 5.7;
  double item8 = 6.8;
  double item9 = 7.9;
  double item10 = 8.1;
  
  queue3.enqueue(item4);
  queue3.enqueue(item5);
  queue3.enqueue(item6);
  queue3.enqueue(item7);

  queue4.enqueue(item8);
  queue4.enqueue(item9);
  queue4.enqueue(item10);
  
  //tests

  CircularQueue q = queue3 + queue4;

  cout << q << "this tests addition\n";

  cout << "next we'll test array accessing \n";
  for(int i = 0; i < 4; i++)
  {
    cout << q[i] << "\n";
  }
  
  
  cq.enqueue(item1); //2.4
  cq.enqueue(item2); //3.4

  cq2.enqueue(item1); //2.4
  
  cout << "the size of cq is " << cq.size() << "\n"; 

  cout << "here is cq using our standard output: " << cq << "\n";
  cout << "here is cq2 using our standard output: " << cq2 << "\n"; 
  cout << "Is cq equal to cq2? " << (cq == cq2) << "\n"; 
  cout << "Is cq not equal to cq2? " << (cq != cq2) << "\n";
  
  cout << "here we are testing enqueuing with our operator overload \n";
  cq2 << item3;  //enqueues 10.1
  
  cq >> d; //dequeue from cq 
  cout << *d << " the dequeued item \n"; //a dequeued item
  
  cout << cq << "cq \n"; //final cq
  cout << cq2 << "cq2 \n"; //final cq2
  
  
  return 0;
}
