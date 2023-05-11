#include <iostream>
#include <stack>
using namespace std;

// Function to swap two elements
void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//partition the array on the basis of pivot element
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

// perform quicksort non-recursively
void quicksort(int arr[], int low, int high)
{
    stack<int> stack;

    // push initial values of low and high to stack
    stack.push(low);
    stack.push(high);

    while (!stack.empty())
    {
        // pop low and high values from stack
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        // partition the array and get the pivot index
        int var = partition(arr, low, high);

        // push the left sub-array to stack
        if (var - 1 > low)
        {
            stack.push(low);
            stack.push(var - 1);
        }

        // push the right sub-array to stack
        if (var + 1 < high)
        {
            stack.push(var + 1);
            stack.push(high);
        }
    }
}

// Function to print the sorted array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5, 10, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}  
