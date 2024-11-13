/*
9b)b. Implement a checkout system for a supermarket to efficiently manage customer queues
during peak hours. The system should support the following operations using a circular
queue data
*/
#include <iostream>
using namespace std;
int front = -1;
int rear = -1;
bool iscounteropen = true;
void enqueue(string cqueue[], int size)
{
  string cust;
  if (!iscounteropen)
  {
    cout << "Counter is closed! No further insertion could be done";
    return;
  }

  cout << endl
       << "Enter customer name: ";
  cin >> cust;

  if (((rear + 1) % size) == front)
  {
    cout << "Queue is full";
    return;
  }
  if (rear == -1 && front == -1)
  {
    front = rear = 0;
    cqueue[rear] = cust;
  }

  else
  {
    rear = (rear + 1) % size;
    cqueue[rear] = cust;
  }
  cout << endl
       << "Customer " << cust << " added";
}

// Dequeue function to remove customers
void dequeue(string cqueue[], int size)
{
  if (front == -1)
  {
    cout << "Queue is empty!";
  }
  else if (front == rear)
  {
    cout << "Customer " << cqueue[front] << " removed";
    front = rear = -1; // Reset the queue when it becomes empty
  }
  else
  {
    cout << "Customer " << cqueue[front] << " removed";
    front = (front + 1) % size; // Move front in a circular fashion
  }
}

void print(string cqueue[], int size)
{
  if (front == -1)
  {
    cout << "Queue is empty!";
  }
  else
  {
    cout << "Customers in Supermarket: ";
    if (front <= rear)
    {
      for (int i = front; i <= rear; i++)
      {
        cout << cqueue[i] << " ";
      }
    }
    else
    {
      for (int j = front; j < size; j++)
      {
        cout << cqueue[j] << " ";
      }
      for (int k = 0; k <= rear; k++)
      {
        cout << cqueue[k] << " ";
      }
    }
    cout << endl;
  }
}

// Function to close the checkout counter (stops further enqueue)
void stopenqueue()
{
  iscounteropen = false; // Close the counter, no new customers can be added
  cout << "Counter is closed now!";
}

int main()
{
  int size;
  cout << endl
       << "Enter the size of queue : ";
  cin >> size;
  int choice;
  string cqueue[size];
  do
  {
    int choice;
    cout << endl
         << endl
         << "1. Customer arrival";
    cout << endl
         << "2. Customer checkout";
    cout << endl
         << "3. Close Checkout Counter";
    cout << endl
         << "4. View customer";
    cout << endl
         << "5. Exit";

    cout << endl
         << endl
         << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      enqueue(cqueue, size);
      break;

    case 2:
      dequeue(cqueue, size);
      break;

    case 3:
      stopenqueue();
      break;

    case 4:
      print(cqueue, size);
      break;

    case 5:
      cout << "Visit again!";
      break;

    default:
      cout << "Invalid choice!";
    }
  } while (choice != 5);

  return 0;
}