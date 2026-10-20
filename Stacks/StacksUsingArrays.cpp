#include <iostream>
using namespace std;

const int StackSize = 5;
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
    void Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        else
        {
            cout << "The top most element of the stack is " << StackArray[top];
        }
    }
    void Size()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        cout << "The number of value inside the stack is " << top + 1;
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty . Nothing to display.";
            return;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << StackArray[i] << " ";
            }
        }
    }
};

int main()
{
    Stack myStack;
    myStack.Push(23);
    myStack.Push(34);
    myStack.Push(265);
    myStack.Push(78);
    myStack.Push(34);
    myStack.Display();
    return 0;
}