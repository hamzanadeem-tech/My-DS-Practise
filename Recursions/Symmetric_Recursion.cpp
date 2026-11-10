#include <iostream>
using namespace std;

void Count(int x)
{
    if (x == 0)
        return;

    cout << x << " ";
    Count(x - 1);
    cout << x << " ";
}

int main()
{
    Count(3);
    return 0;
}