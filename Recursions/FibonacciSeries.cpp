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