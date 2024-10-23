/*
Implement a simple text editor application using a doubly linked list to manage the text buffer.
Text editor should support the following functionalities:
a. Insert text
b. Delete text
c. Display text
d. Search text
e. Print text in reverse 
*/

#include <iostream>
#include <string>
using namespace std;

// Node class representing each character in the text editor
class Node {
public:
    char data;       // stores each character
    Node* prev;      // pointer to the previous character
    Node* next;      // pointer to the next character

    // Constructor to initialize the character node
    Node(char d) : data(d), prev(nullptr), next(nullptr) {}
};

// TextEditor class to manage text using a doubly linked list
class TextEditor {
private:
    Node* head;      // pointer to the start of the text (first character)
    Node* tail;      // pointer to the end of the text (last character)

public:
    // Constructor to initialize an empty text buffer
    TextEditor() : head(nullptr), tail(nullptr) {}

    // Function to insert text (character by character)
    void insertText(string text) {
        for (char ch : text) {
            Node* newNode = new Node(ch);
            if (!head) 
            {
                head = tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        cout << "Text inserted: " << text << "\n";
    }

    // Function to delete text (removes n characters from the end)
    void deleteText(int n) {
        if (!head) 
        {
            cout << "Text buffer is empty. No text to delete.\n";
            return;
        }

        while (n-- && tail) 
        {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) 
            {
                tail->next = nullptr;
            } 
            else 
            {
                head = nullptr;
            }
            delete temp;
        }
        cout << "Deleted characters from the end.\n";
    }

    // Function to display the entire text
    void displayText() {
        if (!head) 
        {
            cout << "Text buffer is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Current text: ";
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for a substring in the text
    void searchText(string query) {
        if (!head) 
        {
            cout << "Text buffer is empty. Cannot search.\n";
            return;
        }

        Node* temp = head;
        bool found = false;
        int position = 0;

        while (temp) 
        {
            Node* current = temp;
            int i = 0;

            // Check if substring matches character by character
            while (current && i < query.length() && current->data == query[i]) 
            {
                current = current->next;
                i++;
            }

            if (i == query.length()) {
                cout << "Substring '" << query << "' found at position " << position << ".\n";
                found = true;
                break;
            }

            temp = temp->next;
            position++;
        }

        if (!found) {
            cout << "Substring '" << query << "' not found in the text.\n";
        }
    }
    
    // Function to display the text in reverse order
    void displayReverseText() {
        if (!tail) {
            cout << "Text buffer is empty.\n";
            return;
        }

        Node* temp = tail;
        cout << "Text in reverse: ";
        while (temp) {
            cout << temp->data;
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string text, query;
    int deleteCount;

    do {
        cout << "\nText Editor Menu:\n";
        cout << "1. Insert Text\n";
        cout << "2. Delete Text\n";
        cout << "3. Display Text\n";
        cout << "4. Search Text\n";
        cout << "5. Print Text in Reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle newline after number input

        switch (choice) {
            case 1:
                cout << "Enter text to insert: ";
                getline(cin, text);
                editor.insertText(text);
                break;

            case 2:
                cout << "Enter number of characters to delete from the end: ";
                cin >> deleteCount;
                editor.deleteText(deleteCount);
                break;

            case 3:
                editor.displayText();
                break;

            case 4:
                cout << "Enter text to search: ";
                getline(cin, query);
                editor.searchText(query);
                break;

            case 5:
                editor.displayReverseText();
                break;

            case 6:
                cout << "Exiting text editor.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
