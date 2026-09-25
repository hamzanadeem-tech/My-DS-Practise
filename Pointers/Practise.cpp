#include<iostream>
using namespace std;

int main(){
    int x , *ptr;
    ptr = &x;
    *ptr = 10;
    cout << *ptr << endl << ptr;

    int arr [10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr2 = arr; // Stores 1st
    return 0;
}