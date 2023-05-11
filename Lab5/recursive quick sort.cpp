#include <iostream>
using namespace std;

// swap two elements
void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// partition the array on the basis of pivot element
int partition(int arr[], int low, int high)
{
    int pivot_ele = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot_ele)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// perform quicksort recursively
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int var = partition(arr, low, high);

        quicksort(arr, low, var - 1);
        quicksort(arr, var+ 1, high);
    }
}

// print the sorted array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 4, 5, 2, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
