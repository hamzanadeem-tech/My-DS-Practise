#include <iostream>
using namespace std;

int Add(int x)
{
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;

    return Add(x - 2) + Add(x - 1);
}

int main()
{
    for(int i = 1; i <= 8; i++)
    {
        cout << Add(i) << " ";
    }
    return 0;
}

// #include <iostream>
// using namespace std;

// int fibonacci(int n) {
//     if (n <= 1) {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// void printFibonacci(int n) {
//     cout << "Fibonacci Series: ";
//     for (int i = 0; i < n; ++i) {
//         cout << fibonacci(i) << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int n = 7;
//     printFibonacci(n);
//     return 0;
// }
