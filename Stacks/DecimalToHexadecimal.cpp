#include <iostream>
using namespace std;

const int StackSize = 100;
class Stack
{
public:
    int top;
    int StackArray[StackSize];
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == StackSize - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push(int d)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot insert inside.";
            return;
        }
        top++;
        StackArray[top] = d;
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        top--;
    }
    int Peak()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return 0;
        }
        else
        {
            return StackArray[top];
        }
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "The stack is empty . Cannot display anything";
            return;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                if (StackArray[i] == 10)
                {
                    cout << "A ";
                }
                else if (StackArray[i] == 11)
                {
                    cout << "B ";
                }
                else if (StackArray[i] == 12)
                {
                    cout << "C ";
                }
                else if (StackArray[i] == 13)
                {
                    cout << "D ";
                }
                else if (StackArray[i] == 14)
                {
                    cout << "E ";
                }
                else if (StackArray[i] == 15)
                {
                    cout << "F ";
                }
                else
                {
                    cout << StackArray[i] << " ";
                }
            }
        }
    }
};

int main()
{
    Stack myStack;
    int x = 70;
    while (x > 0)
    {
        int n = x % 16;
        myStack.Push(n);
        x = x / 16;
    }
    myStack.Display();
    return 0;
}