#include <iostream>
using namespace std;
void Insertion(int arr[], int size)
{
  int i, key, j;
  for (i = 1; i < size; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void print(int arr[], int size)
{
  cout << "Sorted array elements : ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int i, n;
  int a[100];
  cout << "Insertion Sort" << endl;
  cout << "Enter the size of array : ";
  cin >> n;
  cout << "Enter array elements : ";
  for (i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  Insertion(a, n);
  print(a, n);
  return 0;
}