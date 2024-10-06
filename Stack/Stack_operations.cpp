// Simple stack program
#include <iostream>
using namespace std;
int static stk1[100];
int static top = -1;
class Stack
{
public:
  void push(int data)
  {
    if (top >= 100)
    {
      cout << endl
           << "Stack Overflow";
    }
    else
    {
      if (top == -1)
      {
        top++;
        stk1[top] = data;
      }
      else
      {
        top++;
        stk1[top] = data;
      }
    }
  }

  void pop()
  {
    if (top == -1)
    {
      cout << endl
           << "Stack Empty";
    }
    else
    {
      cout << endl
           << "Element removed " << stk1[top];
      top--;
    }
  }

  void Display()
  {
    if (top >= 0)
    {
      cout << endl
           << "Stack elements : ";
      for (int i = top; i >= 0; i--)
      {
        cout << stk1[i] << " ";
      }
    }
    else
    {
      cout << endl
           << "Stack is empty";
    }
  }

  void Current()
  {
    if (top == -1)
    {
      cout << endl
           << "Stack Empty";
    }
    else
    {
      cout << endl
           << "Current element is " << stk1[top];
    }
  }
};
int main()
{
  int choice;
  int no;
  Stack s1;
  do
  {
    cout << endl
         << "1)Push in Stack" << endl;
    cout << "2)Pop in Stack" << endl;
    cout << "3)Display in Stack" << endl;
    cout << "4)Display current element in stack" << endl;
    cout << "5)Exit" << endl;
    cout << endl
         << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << endl
           << "Enter value to be inserted : ";
      cin >> no;
      s1.push(no);
      break;

    case 2:
      s1.pop();
      break;

    case 3:
      s1.Display();
      break;

    case 4:
      s1.Current();
      break;

    case 5:
      cout << endl
           << "Exited";
      break;

    default:
      cout << endl
           << "Invalid Option";
      break;
    }
  } while (choice != 5);

  return 0;
}