#include <iostream>
using namespace std;

int Add(int x)
{
    if(x == 0)
        return 0;

    return x + Add(x - 1);
}

int main()
{
    cout << Add(4);
    return 0;
}