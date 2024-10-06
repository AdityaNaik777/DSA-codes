// C++ implementation of Shell Sort
#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
  int i;
  // Start with a big gap, then reduce the gap
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int j = gap; j < n; j++)
    {
      for (i = j - gap; i >= 0; i = i - gap)
      {
        if (arr[i] > arr[i + gap])
        {
          swap(arr[i], arr[i + gap]);
        }
        else
        {
          break;
        }
      }
    }
  }
  return 0;
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

int main()
{
  int n;
  cout << "Enter the size of array : ";
  cin >> n;
  int arr[n] = {0};
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << "Array before sorting: ";
  printArray(arr, n);

  shellSort(arr, n);

  cout << "\nArray after sorting: ";
  printArray(arr, n);

  return 0;
}
