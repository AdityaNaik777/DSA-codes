/*
a. Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist
provide following facility:
a. Add Party to Waitlist
b. Seat Party
c. Display Waitlist
*/
#include <iostream>
using namespace std;
int front = -1;
int rear = -1;
string queue[5];
int size = 5;
// Linear Queue
class Waitinglist
{
public:
  void enqueue()
  {
    string party = "";
    cout << endl
         << "Enter the party name : ";
    cin >> party;
    if (rear == -1)
    {
      rear = front = 0;
      queue[rear] = party;
      cout << "Added to the Waitinglist : " << party;
    }
    else if (rear == size - 1)
    {
      cout << endl
           << "Queue is full";
      return; // Exit the function to prevent further execution
    }
    else
    {
      rear++;
      queue[rear] = party;
      cout << "Added to the Waitinglist : " << party;
    }
  }

  void dequeue()
  {
    // Removing from the waitinglist
    if (front == -1)
    {
      cout << endl
           << "Queue is empty";
    }
    else if (front == rear)
    {
      cout << "Seating Party: " << queue[front] << endl;
      front = rear = -1;
    }
    else
    {
      cout << "Seating Party: " << queue[front] << endl;
      ;
      front++;
    }
  }

  void print()
  {
    if (front == -1)
    {
      cout << "Queue is empty!";
    }
    else
    {
      for (int i = front; i <= rear; i++)
      {
        cout << queue[i] << "  ";
      }
    }
  }
};

int main()
{
  Waitinglist wl;

  int ch;
  do
  {
    cout << endl
         << "1) Add Party to Waiting List";
    cout << endl
         << "2) Remove Party from waiting list to seat party";
    cout << endl
         << "3) Print Partys present in the waiting list";

    cout << endl
         << "Enter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      wl.enqueue();
      break;

    case 2:
      wl.dequeue();
      break;

    case 3:
      wl.print();
      break;

    case 4:
      cout << endl
           << "Thank you for visiting our Restaurant";

    default:
      cout << endl
           << "Invalid choice, try again";
    }
  } while (ch != 4);

  return 0;
}