#include <iostream>
using namespace std;

void conquer(int arr[], int si, int mid, int ei)
{
    // O(n)
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    // Merge the two subarrays
    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[x] = arr[idx1];
            x++;
            idx1++;
        }
        else
        {
            merged[x] = arr[idx2];
            x++;
            idx2++;
        }
    }

    // Copy remaining elements from the left subarray
    while (idx1 <= mid)
    {
        merged[x] = arr[idx1];
        x++;
        idx1++;
    }

    // Copy remaining elements from the right subarray
    while (idx2 <= ei)
    {
        merged[x] = arr[idx2];
        x++;
        idx2++;
    }

    // Copy the merged array back to the original array
    for (int i = 0; i < x; i++)
    {
        arr[si + i] = merged[i];
    }
}

void divide(int arr[], int si, int ei)
{
    // O(logn)
    if (si >= ei)
    {
        return; // Base case
    }

    int mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

int main()
{
    int arr[100], n;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    divide(arr, 0, n - 1); // Perform merge sort

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}