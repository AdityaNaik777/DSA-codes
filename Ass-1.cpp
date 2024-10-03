/*
Consider a student database of SY COMP class (at least 15 records). Database contains different
fields of every student like Roll No, Name and SGPA.
a. Design a roll call list, arrange list of students according to roll numbers in ascending order
using Insertion Sort
b. Arrange list of students alphabetically using shell sort
c. Arrange list of students to find out first ten toppers from a class using Radix sort
*/
#include <iostream>
using namespace std;
class Student
{
public:
  int rollno;
  string name;
  float sgpa;

  Student()
  {
  }

  Student(int r, string n, float s)
  {
    rollno = r;
    name = n;
    sgpa = s;
  }

  void display()
  {
    cout << "Roll No. :" << rollno << ", Name: " << name << ", SGPA: " << sgpa << endl;
  }
};

void displayStudents(Student students[], int n)
{
  for (int i = 0; i < n; i++)
  {
    students[i].display();
  }

  cout << endl;
}

// Insertion Sort
void insertionsort(Student students[], int n)
{
  for (int i = 1; i < n; i++)
  {
    Student key = students[i];
    int j = i - 1;
    while (j >= 0 && students[j].rollno > key.rollno)
    {
      students[j + 1] = students[j];
      j--;
    }
    students[j + 1] = key;
  }
}

// Shell sort by Name
void shellsort(Student students[], int n)
{
  for (int gap = n / 2; gap > 0; gap = gap / 2)
  {
    for (int i = gap; i < n; i++)
    {
      Student temp = students[i];
      int j;
      for (j = i; j >= gap && students[j - gap].name > temp.name; j = j - gap)
      {
        students[j] = students[j - gap];
      }
      students[j] = temp;
    }
  }
}

// utility function for Radix Sort(for #SGPA sorting)
int getMax(Student students[], int n)
{
  int max = (int)(students[0].sgpa * 100);
  for (int i = 1; i < n; i++)
  {
    if ((int)(students[i].sgpa * 100) > max)
    {
      max = (int)(students[i].sgpa * 100);
    }
  }
  return max;
}

// Counting sort used in radix sort
void countingSort(Student students[], int n, int exp)
{
  Student *output = new Student[n];
  int count[10] = {0};

  for (int i = 0; i < n; i++)
  {
    int digit = ((int)(students[i].sgpa * 100) / exp) % 10;
    count[digit]++;
  }

  for (int i = 1; i < 10; i++)
  {
    count[i] = count[i] + count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    int digit = ((int)(students[i].sgpa * 100) / exp) % 10;
    output[count[digit] - 1] = students[i];
    count[digit]--;
  }

  for (int i = 0; i < n; i++)
  {
    students[i] = output[i];
  }
}

// (c) Radix Sort by SGPA
void radixSort(Student students[], int n)
{
  int max = getMax(students, n);

  for (int exp = 1; max / exp > 0; exp *= 10)
  {
    countingSort(students, n, exp);
  }
}
int main()
{
  const int n = 15;
  Student students[n] = {
      {12, "Alice", 8.6}, {3, "Bob", 9.2}, {10, "Charlie", 7.8}, {5, "David", 8.4}, {7, "Eve", 8.9}, {9, "Frank", 7.5}, {2, "Grace", 9.1}, {8, "Heidi", 7.7}, {4, "Ivan", 8.2}, {11, "Judy", 8.3}, {1, "Mallory", 9.0}, {13, "Oscar", 7.9}, {15, "Peggy", 8.5}, {6, "Sybil", 9.3}, {14, "Trent", 7.6}};

  cout << "Original List of Students:\n";
  displayStudents(students, n);

  // (a) Sort by Roll Numbers using Insertion Sort
  insertionsort(students, n);
  cout << "List of Students sorted by Roll Numbers (Insertion Sort):\n";
  displayStudents(students, n);

  // (b) Sort alphabetically by Name using Shell Sort
  shellsort(students, n);
  cout << "List of Students sorted by Name (Shell Sort):\n";
  displayStudents(students, n);
  cout << endl;
  // (c) Sort by SGPA using Radix Sort to find the top 10 students
  radixSort(students, n);
  cout << "Top 10 Students sorted by SGPA (Radix Sort):\n";
  for (int i = n - 1; i >= n - 10 && i >= 0; i--) // Display from the highest to the lowest
  {
    students[i].display();
  }
  // displayStudents(students, 10); // Display only the top 10 students

  return 0;
}
