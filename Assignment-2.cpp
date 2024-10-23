//Consider Employee database of PCCOE (at least 20 records). Database contains different fields of
//every employee like EMP-ID, EMP-Name and EMP-Salary.
//a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
//b. Arrange list of Employee alphabetically using Merge Sort

#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 20; // Maximum number of employees it is a global constant

// Employee class to represent each employee
class Employee {
public:
    int emp_id;
    string emp_name;
    float emp_salary;

    // Constructor
    Employee() : emp_id(0), emp_name(""), emp_salary(0.0) {}  // Default constructor

    Employee(int id, string name, float salary) : emp_id(id), emp_name(name), emp_salary(salary) {}

    // Function to display employee details
    void display() const{
        cout << "EMP-ID: " << emp_id << ", EMP-Name: " << emp_name << ", EMP-Salary: " << emp_salary << endl;
    }
};

// EmployeeDatabase class containing employee list and sorting methods
class EmployeeDatabase {
private:
    Employee employees[MAX_EMPLOYEES];  // Array to store employees
    int employeeCount;                  // Current number of employees

    // Helper function for quick sort partition (by EMP-ID)
    int partition(int low, int high) {
        int pivot = employees[high].emp_id;
        int i = low - 1;
        for (int j = low; j < high; j++) 
        {
            if (employees[j].emp_id < pivot) 
            {
                i++;
                swap(employees[i], employees[j]);
            }
        }
        swap(employees[i + 1], employees[high]);
        return i + 1;
    }

    // Quick Sort recursive function (by EMP-ID)
    void quickSort(int low, int high) {
        if (low < high) 
        {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

        // Merge function for merge sort (by EMP-Name)
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays
        Employee L[n1], R[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            L[i] = employees[left + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = employees[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].emp_name <= R[j].emp_name) {
                employees[k] = L[i];
                i++;
            } else {
                employees[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[], if any
        while (i < n1) {
            employees[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[], if any
        while (j < n2) {
            employees[k] = R[j];
            j++;
            k++;
        }
    }

    // Merge Sort recursive function (by EMP-Name)
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

public:
    // Constructor
    EmployeeDatabase() : employeeCount(0) {}

    // Function to add employee to the database
    void addEmployee(int id, string name, float salary) {
        if (employeeCount < MAX_EMPLOYEES) {
            employees[employeeCount] = Employee(id, name, salary);
            employeeCount++;
        } else {
            cout << "Employee database is full!\n";
        }
    }

    // Function to display all employees
    void displayEmployees() const {
        for (int i = 0; i < employeeCount; i++) {
            employees[i].display();
        }
    }

    // Function to sort employees by EMP-ID using Quick Sort
    void sortByEmpID() {
        quickSort(0, employeeCount - 1);
    }

    // Function to sort employees alphabetically by EMP-Name using Merge Sort
    void sortByEmpName() {
        mergeSort(0, employeeCount - 1);
    }
};

int main() {
    EmployeeDatabase db;

    // Adding employees to the database
    db.addEmployee(103, "Alice", 50000);
    db.addEmployee(101, "Bob", 60000);
    db.addEmployee(107, "Charlie", 55000);
    db.addEmployee(104, "David", 45000);
    db.addEmployee(102, "Eve", 70000);

    cout << "Original Employee List:\n";
    db.displayEmployees();

    // Sorting employees by EMP-ID using Quick Sort
    db.sortByEmpID();
    cout << "\nEmployee List Sorted by EMP-ID (Quick Sort):\n";
    db.displayEmployees();

    // Sorting employees by EMP-Name using Merge Sort
    db.sortByEmpName();
    cout << "\nEmployee List Sorted by EMP-Name (Merge Sort):\n";
    db.displayEmployees();

    return 0;
}