#include <iostream>
#include <cmath>
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

    bool isAnum(char c)
    {
        if (c >= '0' && c <= '9')
        {
            return true;
        }
        else
            return false;
    }
    int Evaluation(string Postfix)
    {
        Stack myStack;
        for (int i = 0; i < Postfix.length(); i++)
        {
            char c = Postfix[i];
            if (isAnum(c))
            {
                myStack.Push(c - '0');
            }
            else
            {
                int op1 = myStack.Peak();
                myStack.Pop();
                int op2 = myStack.Peak();
                myStack.Pop();
                switch (c)
                {
                case '/':
                    myStack.Push( op2 / op1);
                    break;
                case '+':
                    myStack.Push( op2 + op1);
                    break;
                case '-':
                    myStack.Push( op2 - op1);
                    break;
                case '*':
                    myStack.Push( op2 * op1);
                    break;
                case '^':
                    myStack.Push( pow(op2, op1));
                    break;

                default:
                    break;
                }
            }
        }
        return myStack.Peak();
    }
};

int main(){
    Stack myStack;
    string Postfix = "45*2+";
    cout << "The evaluation of the given Postfix is " << myStack.Evaluation(Postfix);
}