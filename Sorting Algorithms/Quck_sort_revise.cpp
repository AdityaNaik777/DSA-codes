#include <iostream>
using namespace std;
class qs
{
public:
  int Partition(int arr[], int start, int end)
  {
    int low = start;
    int high = end;
    int pivot = arr[start];
    while (low < high)
    {
      while (arr[low] <= pivot)
      {
        low++;
      }
      while (arr[high] > pivot)
      {
        high--;
      }
      if (low < high)
      {
        swap(arr[low], arr[high]);
      }
    }
    swap(arr[start], arr[high]);
    return high;
  }

  void Quick_sort(int arr[], int start, int end)
  {
    if (start < end)
    {
      int p = Partition(arr, start, end);
      Quick_sort(arr, start, p - 1);
      Quick_sort(arr, p + 1, end);
    }
  }
};
int main()
{
  int size;
  /*
  cout << "Enter the size of array : ";
  cin >> size;
  cout << "Enter the array elements : ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  */
  size = 5;
  int arr[5] = {5, 2, 4, 1, 8};
  int start = 0;
  int end = size - 1;

  qs q1;
  cout << "Original array elements : ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  q1.Quick_sort(arr, start, end);
  cout << endl
       << "Sorted array elements : ";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}