#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int s = 0; s < n - 1; s++)
    {
        for (int j = 0; j < n - s - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(int arr[], int n)
{
    for (int s = 0; s < n; s++)
    {
        cout << arr[s] << " ";
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
    for (int s = 0; s < n; s++)
    {
        cin >> arr[s];
    }
    cout << "Given Grray: ";
    printArray(arr, n);
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
