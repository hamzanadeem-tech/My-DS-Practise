// This algorithm is also called as Shunting Yard Algorithm

#include <iostream>
using namespace std;

const int StackSize = 100;
class Stack
{
public:
    int top;
    char StackArray[StackSize];
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
    void Push(char d)
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
    char Peak()
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

    bool isAlphaNum(char c)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        {
            return true;
        }
        else
            return false;
    }

    int Precedence(char c)
    {
        switch (c)
        {
        case '^':
            return 3;
            break;
        case '/':
        case '*':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;

        default:
            return 0;
            break;
        }
    }

    string Conversion(string infix)
    {
        string PostFix = " ";
        Stack myStack;
        for (int i = 0; i < infix.length(); i++)
        {
            char c = infix[i];
            if (isAlphaNum(c))
            {
                PostFix = PostFix + c;
            }
            else if (c == '(')
            {
                myStack.Push(c);
            }
            else if (c == ')')
            {
                while (myStack.Peak() != '(')
                {
                    PostFix = PostFix + myStack.Peak();
                    myStack.Pop();
                }
                myStack.Pop();
            }
            else
            {
                while (myStack.isEmpty() != true && Precedence(c) <= Precedence(myStack.Peak()))
                {
                    PostFix = PostFix + myStack.Peak();
                    myStack.Pop();
                }
                myStack.Push(c);
            }
        }
            while (!myStack.isEmpty())
            {
                PostFix = PostFix + myStack.Peak();
                myStack.Pop();
            }
            return PostFix;
    }
};

int main()
{
    Stack converter;
    string test1 = "a+b*c";
    string test2 = "(a+b)*c";
    string test3 = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "--- Automated Tests ---" << endl;
    cout << "Infix:   " << test1 << "\nPostfix:" << converter.Conversion(test1) << "\n\n";
    cout << "Infix:   " << test2 << "\nPostfix:" << converter.Conversion(test2) << "\n\n";
    cout << "Infix:   " << test3 << "\nPostfix:" << converter.Conversion(test3) << "\n\n";
    return 0;
}