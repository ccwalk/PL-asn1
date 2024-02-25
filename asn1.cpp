/**
 *Name: Callie Walker
 *Assignment: 1
 *Due 2/26/24
 *Purpose: The purpose of this program is to create a Circular Queue in C++
 *
 *COMPILER: compiled using C++20
 */

class CircularQueue{

  private:

      int First; //position for First/Front/Head
      int Last; //position for Last/Rear/tail

      int MaxCapacity; //Maximum capacity for items
      double* Items; //The actual items stored in the queue



      CircularQueue(int N); //Allocates double array for N items, set Maximum capacity as N, and intialize First and Last

      ~CircularQueue(); // Destructor will deallocate the double array

      void enqueue(double newItem); //Enqueues newitem
      double dequeue(); // Dequeues the appropriate item and returns it
      bool  isEmpty(); //Verifies if the queue is empty 
      bool isFull(); //Verifies if the queue is full
      int size(); //Returns how many items are in the queue (not the same as MaxCapacity)

};

CircularQueue(int N)
{
  head = NULL;
  tail = NULL;
  
}

~CircularQueue()
{
  while(!isEmpty())
  {
    dequeue();	  
  }
}

void enqueue(double newItem)
{
  if(!isFull())
  {
    printf("Queue is full");
  }
  else if(front == -1 ) //isEmpty
  {
    first = 0;
    rear = 0;
    rear
  }
  else if 
  {

  }

 
}

double dequeue()
{
  
}

bool isEmpty()
{
  CircularQueue cq;
  return cq.size() == 0;
}

bool isFull()
{
  if(first == 0 && last == MaxCapacity) //is ||(last +1 % size == first) neceessary
  {
    returb true;
  } 
  return false;
}

int size()
{
  
}
