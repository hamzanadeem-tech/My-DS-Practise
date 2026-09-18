#include <iostream>
using namespace std;
void SelectionSort(int arr[], int size)
{
    int temp, minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int const size = 5;
    int arr[size] = {3, 9, 2, 5, 7};
    SelectionSort(arr, size);
    printArr(arr , size);
    return 0;
}