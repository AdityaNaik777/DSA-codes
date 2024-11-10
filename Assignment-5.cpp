/*
Implement a navigation system for a delivery service using a circular linked list to represent
routes. The navigation system should support the following functionalities:
a. Add route
b. Remove route
c. Display route
*/

#include <iostream>
#include <string>

using namespace std;

// Node structure representing a route in the circular linked list
struct RouteNode
{
  string location;
  RouteNode *next;

  RouteNode(string loc) : location(loc), next(nullptr) {}
};

// Class representing the circular linked list navigation system
class NavigationSystem
{
private:
  RouteNode *head;

public:
  NavigationSystem() : head(nullptr) {}

  // Add a new route
  void addRoute(const string &location)
  {
    RouteNode *newRoute = new RouteNode(location);
    if (head == nullptr)
    {
      head = newRoute;
      newRoute->next = head; // Point to itself to maintain circularity
    }
    else
    {
      RouteNode *temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = newRoute;
      newRoute->next = head;
    }
    cout << "Route to " << location << " added.\n";
  }

  // Remove a route
  void removeRoute(const string &location)
  {
    if (head == nullptr)
    {
      cout << "No routes available to remove.\n";
      return;
    }

    RouteNode *current = head, *prev = nullptr;

    // Check if the head node is the one to be removed
    if (head->location == location)
    {
      // Case: Only one node in the list
      if (head->next == head)
      {
        delete head;
        head = nullptr;
        cout << "Route to " << location << " removed.\n";
        return;
      }
      // Case: More than one node in the list
      else
      {
        RouteNode *tail = head;
        while (tail->next != head)
        {
          tail = tail->next;
        }
        tail->next = head->next; // Update tail's next to the new head
        RouteNode *temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Delete the old head
        cout << "Route to " << location << " removed.\n";
        return;
      }
    }

    // Search for the node to remove (not the head)
    do
    {
      prev = current;
      current = current->next;
      if (current->location == location)
      {
        prev->next = current->next; // Bypass the node to remove
        delete current;
        cout << "Route to " << location << " removed.\n";
        return;
      }
    } while (current != head);

    cout << "Route to " << location << " not found.\n";
  }

  // Display all routes
  void displayRoutes()
  {
    if (head == nullptr)
    {
      cout << "No routes available.\n";
      return;
    }

    RouteNode *temp = head;
    cout << "Routes:\n";
    do
    {
      cout << "- " << temp->location << endl;
      temp = temp->next;
    } while (temp != head);
  }
};

// Main function
int main()
{
  NavigationSystem navSystem;
  int choice;
  string location;

  while (true)
  {
    cout << "\n1. Add Route\n2. Remove Route\n3. Display Routes\n4. Exit\nChoose an option: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the location to add: ";
      cin >> location;
      navSystem.addRoute(location);
      break;
    case 2:
      cout << "Enter the location to remove: ";
      cin >> location;
      navSystem.removeRoute(location);
      break;
    case 3:
      navSystem.displayRoutes();
      break;
    case 4:
      cout << "Exiting navigation system.\n";
      return 0;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }
}
