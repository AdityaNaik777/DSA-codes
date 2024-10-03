#include <iostream>
#include <string>
using namespace std;

// Employee class
class Employee
{
public:
  int empID;
  string empName;
  int empSalary;

  Employee() {} // Default constructor
  Employee(int id, string name, int salary)
  {
    empID = id;
    empName = name;
    empSalary = salary;
  }
};

// Partition function for Quick Sort (sort by EMP-ID)
int partition(Employee employees[], int low, int high)
{
  int pivot = employees[low].empID; // Choosing the pivot as the first element
  int left = low + 1;               // Start just after the pivot
  int right = high;                 // Start from the end

  while (true)
  {
    // Move the left pointer until we find an element larger than or equal to the pivot
    while (left <= right && employees[left].empID < pivot)
    {
      left++;
    }

    // Move the right pointer until we find an element smaller than or equal to the pivot
    while (right >= left && employees[right].empID > pivot)
    {
      right--;
    }

    // If pointers cross, break the loop
    if (left > right)
    {
      break;
    }

    // Hardcoded swap logic without using a function
    Employee temp = employees[left];
    employees[left] = employees[right];
    employees[right] = temp;

    // Move the pointers
    left++;
    right--;
  }

  // Hardcoded swap logic for swapping the pivot with the element at the right pointer
  Employee temp = employees[low];
  employees[low] = employees[right];
  employees[right] = temp;

  // Return the index of the pivot element
  return right;
}

// Quick Sort (arrange by EMP-ID in ascending order)
void quickSort(Employee employees[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(employees, low, high);
    quickSort(employees, low, pi - 1);
    quickSort(employees, pi + 1, high);
  }
}

// Merge two halves for Merge Sort (used for sorting alphabetically by EMP-Name)
void merge(Employee employees[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Employee *leftArr = new Employee[n1];
  Employee *rightArr = new Employee[n2];

  for (int i = 0; i < n1; i++)
    leftArr[i] = employees[left + i];
  for (int j = 0; j < n2; j++)
    rightArr[j] = employees[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (leftArr[i].empName <= rightArr[j].empName)
    {
      employees[k] = leftArr[i];
      i++;
    }
    else
    {
      employees[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    employees[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    employees[k] = rightArr[j];
    j++;
    k++;
  }

  delete[] leftArr;
  delete[] rightArr;
}

// Merge Sort (arrange alphabetically by EMP-Name)
void mergeSort(Employee employees[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(employees, left, mid);
    mergeSort(employees, mid + 1, right);

    merge(employees, left, mid, right);
  }
}

// Function to display employee details
void dispemp(Employee employees[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << "EMP-ID: " << employees[i].empID << ", EMP-Name: " << employees[i].empName << ", EMP-Salary: " << employees[i].empSalary << endl;
  }
}

int main()
{
  // Creating a list of 10 employees (can extend it to 20)
  const int size = 10;
  // Object array Database of 10 students
  Employee employees[size] = {
      Employee(101, "Rohit", 50000),
      Employee(45, "Anjali", 60000),
      Employee(78, "Vikas", 55000),
      Employee(23, "Shreya", 52000),
      Employee(89, "Rahul", 58000),
      Employee(56, "Priya", 51000),
      Employee(102, "Akash", 62000),
      Employee(19, "Karan", 53000),
      Employee(92, "Sonal", 54000),
      Employee(63, "Nisha", 61000)};

  cout << "Original Employee List:\n";
  dispemp(employees, size);

  // Sorting by EMP-ID using Quick Sort
  quickSort(employees, 0, size - 1);
  cout << "\nEmployees sorted by EMP-ID (Quick Sort):\n";
  dispemp(employees, size);

  // Sorting by EMP-Name using Merge Sort
  mergeSort(employees, 0, size - 1);
  cout << "\nEmployees sorted by EMP-Name (Merge Sort):\n";
  dispemp(employees, size);

  return 0;
}
