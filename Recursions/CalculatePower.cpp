#include <iostream>
using namespace std;

int calculatePower(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return num * calculatePower(num, power - 1);
}

int main()
{
    int num, power;
    cout << "Enter the number ";
    cin >> num;
    cout << "\nEnter the power ";
    cin >> power;
    cout << "The result of the values which you entered is " << calculatePower(num, power);
    return 0;
}