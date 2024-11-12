#include <iostream>
const int N = 5;
int deque[5];
int front = -1, rear = -1;
using namespace std;

class DQ
{
public:
  void insert_at_front()
  {
    int x;
    cout << endl
         << "Enter element: ";
    cin >> x;

    // Check if deque is full
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
      cout << endl
           << "Queue is full";
    }
    else if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Inserting into empty queue";
      front = rear = 0;
      deque[front] = x;
      cout << endl
           << "Element inserted";
    }
    else if (front == 0) // Circularly wrap front pointer
    {
      front = N - 1;
      deque[front] = x;
      cout << endl
           << "Element inserted";
    }
    else // Normal insertion at front
    {
      front--;
      deque[front] = x;
      cout << endl
           << "Element inserted";
    }
  }

  void insert_at_rear()
  {
    int x;
    cout << endl
         << "Enter element: ";
    cin >> x;

    // Check if deque is full
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
      cout << endl
           << "Queue is full";
    }
    else if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Inserting into empty queue";
      front = rear = 0;
      deque[rear] = x;
      cout << endl
           << "Element inserted";
    }
    else if (rear == N - 1) // Circularly wrap rear pointer
    {
      rear = 0;
      deque[rear] = x;
      cout << endl
           << "Element inserted";
    }
    else // Normal insertion at rear
    {
      rear++;
      deque[rear] = x;
      cout << endl
           << "Element inserted";
    }
  }

  void getfront()
  {
    if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Queue is empty";
    }
    else
    {
      cout << endl
           << "Element at front end: " << deque[front];
    }
  }

  void getrear()
  {
    if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Queue is empty";
    }
    else
    {
      cout << endl
           << "Element at rear end: " << deque[rear];
    }
  }

  void delete_at_front()
  {
    if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Queue is empty";
    }
    else if (front == rear) // Single element in deque
    {
      cout << endl
           << "Element " << deque[front] << " deleted";
      front = rear = -1;
    }
    else if (front == N - 1) // Circularly wrap front pointer
    {
      cout << endl
           << "Element " << deque[front] << " deleted";
      front = 0;
    }
    else // Normal deletion from front
    {
      cout << endl
           << "Element " << deque[front] << " deleted";
      front++;
    }
  }

  void delete_at_rear()
  {
    if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Queue is empty";
    }
    else if (front == rear) // Single element in deque
    {
      cout << endl
           << "Element " << deque[rear] << " deleted";
      front = rear = -1;
    }
    else if (rear == 0) // Circularly wrap rear pointer
    {
      cout << endl
           << "Element " << deque[rear] << " deleted";
      rear = N - 1;
    }
    else // Normal deletion from rear
    {
      cout << endl
           << "Element " << deque[rear] << " deleted";
      rear--;
    }
  }

  void isFull()
  {
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
      cout << endl
           << "Queue is full";
    }
    else
    {
      cout << endl
           << "Queue is not full";
    }
  }

  void isEmpty()
  {
    if (front == -1 && rear == -1)
    {
      cout << endl
           << "Queue is empty";
    }
    else
    {
      cout << endl
           << "Queue is not empty";
    }
  }

  void display()
  {
    if (front == -1 && rear == -1) // Check if deque is empty
    {
      cout << endl
           << "Queue is empty";
    }
    else // Traverse and display deque elements
    {
      int i = front;
      while (i != rear)
      {
        cout << deque[i] << " ";
        i = (i + 1) % N;
      }
      cout << deque[i];
    }
  }
};

int main()
{
  DQ d1;
  int ch;
  cout << "Size of Queue is: " << N;
  do
  {
    cout << endl
         << "1.Insertion at Front";
    cout << endl
         << "2.Insertion at Rear";
    cout << endl
         << "3.Deletion at Front";
    cout << endl
         << "4.Deletion at Rear";
    cout << endl
         << "5.Get Front";
    cout << endl
         << "6.Get Rear";
    cout << endl
         << "7.Queue Full";
    cout << endl
         << "8.Queue Empty";
    cout << endl
         << "9.Display";
    cout << endl
         << "10.Exit";

    cout << endl
         << "Enter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      d1.insert_at_front();
      break;

    case 2:
      d1.insert_at_rear();
      break;

    case 3:
      d1.delete_at_front();
      break;

    case 4:
      d1.delete_at_rear();
      break;

    case 5:
      d1.getfront();
      break;

    case 6:
      d1.getrear();
      break;

    case 7:
      d1.isFull();
      break;

    case 8:
      d1.isEmpty();
      break;

    case 9:
      d1.display();
      break;

    case 10:
      cout << "Thank you";
      break;
    }
  } while (ch != 10);

  return 0;
}
