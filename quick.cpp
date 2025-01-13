#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and the pivot (arr[high])
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the partition index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Given Array: ";
    printArray(arr, n);

    // Sort the array using Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
