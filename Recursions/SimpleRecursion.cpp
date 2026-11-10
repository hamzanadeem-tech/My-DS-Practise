#include <iostream>
using namespace std;

void Display(int x)
{
    if (x == 0)
        return;

    cout << x << " ";
    Display(x - 1);
}

int main()
{
    Display(3);
    return 0;
}