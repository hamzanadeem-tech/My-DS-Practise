#include <iostream>
using namespace std;

void Count(int x)
{
    if(x == 0)
        return;

    cout << x + 3 << "\t";
    Count(x - 1);
    cout << x * 2 << "\t";
}

int main()
{
    Count(3);
    return 0;
}