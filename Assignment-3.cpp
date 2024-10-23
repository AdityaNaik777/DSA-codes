/*
Consider the playlist in a music player. Implement a playlist feature in music player application
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each
node contains information about the song (such as title or artist or duration, etc.).
The playlist should allow users to:
a. Add songs
b. Remove songs
c. Display the entire playlist
d. Play specific songs
*/

#include <iostream>
#include <string> //to use predefined functions of string class
using namespace std;

// Node class representing each song in the playlist
class Song {
public:
    string title;
    string artist;
    float duration; // in minutes
    Song* next;

    // Constructor to initialize song details
    Song(string t, string a, float d) : title(t), artist(a), duration(d), next(nullptr) {}
};

// Playlist class representing the linked list of songs
class Playlist {
private:
    Song* head; // pointer to the first song in the playlist
public:
    // Constructor to initialize an empty playlist
    Playlist()
    {
        head=nullptr;
    }

    // Function to add a song to the playlist
    void addSong(string title, string artist, float duration) {
        Song* newSong = new Song(title, artist, duration);
        if (!head) {
            head = newSong;
        } 
        else 
        {
            Song* temp = head;
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        cout << "Song '" << title << "' added to the playlist.\n";
    }

    // Function to remove a song from the playlist by title
    void removeSong(string title) {
        if (!head) {
            cout << "The playlist is empty. No song to remove.\n";
            return;
        }

        // If the song to be removed is the first song
        if (head->title == title) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << "Song '" << title << "' removed from the playlist.\n";
            return;
        }

        // Search for the song in the playlist
        Song* temp = head;
        while (temp->next && temp->next->title != title) {
            temp = temp->next;
        }

        if (temp->next) {
            Song* songToRemove = temp->next;
            //this below initialization will bypass the linking of that song which will be deleted
            temp->next = songToRemove->next;
            delete songToRemove;
            cout << "Song '" << title << "' removed from the playlist.\n";
        } 
        else 
        {
            cout << "Song '" << title << "' not found in the playlist.\n";
        }
    }

    // Function to display the entire playlist
    void displayPlaylist() {
        if (!head) {
            cout << "The playlist is empty.\n";
            return;
        }

        Song* temp = head;
        int songCount = 1;
        cout << "Playlist:\n";
        while (temp) {
            cout << songCount << ". Title: " << temp->title 
                 << ", Artist: " << temp->artist 
                 << ", Duration: " << temp->duration << " mins\n";
            temp = temp->next;
            songCount++;
        }
    }

    // Function to play a specific song by title
    void playSong(string title) {
        Song* temp = head;
        while (temp) {
            if (temp->title == title) {
                cout << "Now playing: " << temp->title 
                     << " by " << temp->artist 
                     << " (" << temp->duration << " mins)\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song '" << title << "' not found in the playlist.\n";
    }
};

int main() {
    Playlist myPlaylist;
    int choice;
    string title, artist;
    float duration;

    do {
        cout << "\nMusic Playlist Menu:\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character after input

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter song duration (in minutes): ";
                cin >> duration;
                myPlaylist.addSong(title, artist, duration);
                break;

            case 2:
                cout << "Enter the title of the song to remove: ";
                getline(cin, title);
                myPlaylist.removeSong(title);
                break;

            case 3:
                myPlaylist.displayPlaylist();
                break;

            case 4:
                cout << "Enter the title of the song to play: ";
                getline(cin, title);
                myPlaylist.playSong(title);
                break;

            case 5:
                cout << "Exiting playlist application.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
