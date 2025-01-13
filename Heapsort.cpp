#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index `i`
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize the largest as the root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child exists and is larger than the root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child exists and is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Swap the root with the largest child

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n)
{
    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
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

    // Sort the array using Heap Sort
    heapSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
