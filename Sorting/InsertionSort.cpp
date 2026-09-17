#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void DisplayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int const size = 5;
    int arr[size] = {5, 4, 2, 1, 3};
    InsertionSort(arr, size);
    DisplayArray(arr, size);
    return 0;
}