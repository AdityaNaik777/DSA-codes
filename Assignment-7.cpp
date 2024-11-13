/*
Implement a browser history management system using a stack data structure to track the user's
browsing history. The system should support the following functionalities:
a. Add visited page
b. Navigate back
c. View current page
d. Check if history is empty or not
Assume no upper bound on number of pages visited
*/
#include <iostream>
using namespace std;
string stk1[100];
int top = -1;
int k = 0;
int n = 100;
void add(string str)
{
  if (top >= 99)
  {
    cout << "Stack is full";
  }
  else
  {
    top++;
    stk1[top] = str;
  }
}
void navigateback()
{
  string stk2[100];
  if (top >= 0)
  {
    for (int temp = top; temp >= 0; temp--)
    {
      stk2[k] = stk1[temp];
      cout << stk2[k] << endl;
    }
    cout << endl;
  }
  else
  {
    cout << "Browser History is deleted" << endl;
  }
}
void empty()
{
  if (top == -1)
  {
    cout << "Browser History is empty";
  }
  else
  {
    cout << "Browser History is not empty" << endl;
  }
}
void current()
{
  cout << "Current Page is : " << stk1[top];
}
int main()
{
  // Write C++ code here
  int ch;
  string site;
  do
  {
    cout << endl;
    cout << "1. Add Visited Page " << endl;
    cout << "2. Navigate Back " << endl;
    cout << "3. View xurrent page " << endl;
    cout << "4. Check if history is empty " << endl;
    cout << "5. Exit " << endl;
    cout << "Enter choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "Enter the site visited : ";
      cin >> site;
      add(site);
      break;
    case 2:
      navigateback();
      break;
    case 3:
      current();
      break;
    case 4:
      empty();
      break;
    case 5:
      cout << "Thank You!";
      break;
    default:
      cout << "Invalid Option!";
      break;
    }
  } while (ch != 5);
  return 0;
}
