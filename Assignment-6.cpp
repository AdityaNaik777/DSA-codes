#include <bits/stdc++.h>
using namespace std;

// Class representing a node in a polynomial linked list
class Node
{
public:
  int coeff; // Coefficient of the term
  int pow;   // Power (exponent) of the term
  Node *next;

  Node()
  {
    coeff = pow = 0;
    next = NULL;
  }
};

// Class representing a linked list for a polynomial
class LL
{
public:
  Node *head = NULL;

  // Function to create a new node and add it to the end of the polynomial linked list
  void create_node(int x, int y)
  {
    Node *nn = new Node(); // Creating a new node
    nn->coeff = x;         // Setting coefficient
    nn->pow = y;           // Setting power
    if (head == NULL)
    { // If the list is empty, make new node the head
      head = nn;
    }
    else
    {
      // Traverse to the end of the list to add the new node
      Node *temp = head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = nn; // Link the last node to the new node
    }
  }

  // Function to add two polynomial linked lists and store the result in the current list
  void polyadd(LL l1, LL l2)
  {
    Node *p1 = l1.head;        // Pointer to traverse the first polynomial
    Node *p2 = l2.head;        // Pointer to traverse the second polynomial
    Node *result = new Node(); // Result polynomial's head node
    Node *curr = result;

    // Traverse both lists and add terms with the same power
    while (p1 != NULL && p2 != NULL)
    {
      Node *nn = new Node(); // Create a new node for the result
      if (p1->pow > p2->pow)
      {
        nn->pow = p1->pow;
        nn->coeff = p1->coeff;
        p1 = p1->next;
      }
      else if (p1->pow < p2->pow)
      {
        nn->pow = p2->pow;
        nn->coeff = p2->coeff;
        p2 = p2->next;
      }
      else
      { // If powers are the same, add the coefficients
        nn->pow = p1->pow;
        nn->coeff = p1->coeff + p2->coeff;
        p1 = p1->next;
        p2 = p2->next;
      }
      curr->next = nn; // Link the new node to the result
      curr = curr->next;
    }

    // Append remaining terms from p1 (if any)
    while (p1 != NULL)
    {
      curr->next = p1;
      curr = curr->next;
      p1 = p1->next;
    }

    // Append remaining terms from p2 (if any)
    while (p2 != NULL)
    {
      curr->next = p2;
      curr = curr->next;
      p2 = p2->next;
    }

    head = result->next; // Set the head of the current list to the result
  }

  // Function to print the polynomial in a readable format
  void printpoly()
  {
    if (head != NULL)
    {
      Node *temp = head;
      while (temp->next != NULL)
      {
        cout << temp->coeff << "^" << temp->pow << "+";
        temp = temp->next;
      }
      cout << temp->coeff << "^" << temp->pow;
    }
  }
};

// Main function to demonstrate polynomial addition
int main()
{
  LL l1, l2, l3;

  // Creating nodes for polynomial 1: 41x^7 + 12x^5 + 65x^0
  l1.create_node(41, 7);
  l1.create_node(12, 5);
  l1.create_node(65, 0);

  // Creating nodes for polynomial 2: 21x^5 + 15x^2
  l2.create_node(21, 5);
  l2.create_node(15, 2);

  // Display polynomial 1
  cout << "Polynomial 1: ";
  l1.printpoly();

  // Display polynomial 2
  cout << "\nPolynomial 2: ";
  l2.printpoly();

  // Adding polynomial 1 and polynomial 2
  l3.polyadd(l1, l2);

  // Display result of addition
  cout << "\nPolynomial after adding P1 and P2: ";
  l3.printpoly();

  return 0;
}
