#include <iostream>
using namespace std;

class Node
{
public:
  int data; // Job ID
  int pr;   // Job Priority
  Node *next;
  Node *prev;

  Node(int val, int priority)
  {
    data = val;
    pr = priority;
    next = NULL;
    prev = NULL;
  }
};

class Deque
{
public:
  Node *front;
  Node *rear;

  // Constructor to initialize the deque
  Deque()
  {
    front = rear = NULL;
  }

  // Insert based on priority (higher priority jobs are added closer to the front)
  void insert_by_priority(int val, int pr)
  {
    Node *nn = new Node(val, pr);
    if (!front) // Deque is empty
    {
      front = rear = nn;
    }
    else if (pr > front->pr) // Insert at the front if highest priority
    {
      nn->next = front;
      front->prev = nn;
      front = nn;
    }
    else
    {
      Node *temp = front;
      while (temp->next && temp->next->pr >= pr)
      {
        temp = temp->next;
      }
      nn->next = temp->next;
      if (temp->next)
        temp->next->prev = nn;
      else
        rear = nn; // Update rear if inserted at the end
      nn->prev = temp;
      temp->next = nn;
    }
    cout << "Job added with priority " << pr << ": " << val << endl;
  }

  // Delete the front node of the deque
  void delete_at_front()
  {
    if (!front)
    {
      cout << "Deque is empty. Nothing to delete at front." << endl;
      return;
    }
    Node *temp = front;
    cout << "Job removed from front: " << front->data << endl;

    if (front == rear) // Only one node in the deque
    {
      front = rear = NULL;
    }
    else
    {
      front = front->next;
      front->prev = NULL;
    }
    delete temp;
  }

  // Delete the rear node of the deque
  void delete_at_rear()
  {
    if (!rear)
    {
      cout << "Deque is empty. Nothing to delete at rear." << endl;
      return;
    }
    Node *temp = rear;
    cout << "Job removed from rear: " << rear->data << endl;

    if (front == rear) // Only one node in the deque
    {
      front = rear = NULL;
    }
    else
    {
      rear = rear->prev;
      rear->next = NULL;
    }
    delete temp;
  }

  // Display jobs in the deque
  void print()
  {
    if (!front)
    {
      cout << "No jobs to schedule" << endl;
      return;
    }
    Node *temp = front;
    cout << "Jobs in the system (in order of processing): ";
    while (temp)
    {
      cout << "(Job ID: " << temp->data << ", Priority: " << temp->pr << ") ";
      temp = temp->next;
    }
    cout << endl;
  }

  // Search for a job by ID
  void search_job(int val)
  {
    Node *temp = front;
    while (temp)
    {
      if (temp->data == val)
      {
        cout << "Job found - ID: " << temp->data << ", Priority: " << temp->pr << endl;
        return;
      }
      temp = temp->next;
    }
    cout << "Job with ID " << val << " not found." << endl;
  }
};

int main()
{
  Deque jobQueue;
  int ch, val, priority;

  do
  {
    cout << endl
         << "1) Insert Job by Priority";
    cout << endl
         << "2) Delete at Front";
    cout << endl
         << "3) Delete at Rear";
    cout << endl
         << "4) Display Jobs";
    cout << endl
         << "5) Search Job";
    cout << endl
         << "6) Exit";

    cout << endl
         << "Enter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
      cout << "Enter Job ID: ";
      cin >> val;
      cout << "Enter Job Priority: ";
      cin >> priority;
      jobQueue.insert_by_priority(val, priority);
      break;

    case 2:
      jobQueue.delete_at_front();
      break;

    case 3:
      jobQueue.delete_at_rear();
      break;

    case 4:
      jobQueue.print();
      break;

    case 5:
      cout << "Enter Job ID to search: ";
      cin >> val;
      jobQueue.search_job(val);
      break;

    case 6:
      cout << "Exiting Job Scheduling System" << endl;
      break;

    default:
      cout << "Invalid Option" << endl;
      break;
    }
  } while (ch != 6);

  return 0;
}
