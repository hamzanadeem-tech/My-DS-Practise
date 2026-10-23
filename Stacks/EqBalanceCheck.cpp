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

    bool BalanceCheck(string exp){
        Stack myStack;
        for (int i = 0; i < exp.length(); i++)
        {
            char c = exp[i];
            if (c == '(' || c == '{' || c == '[')
            {
                myStack.Push(c);
            }
            else if (c == ')' || c == '}'|| c == ']')
            {
                if (myStack.isEmpty() == true)
                {
                    cout << "Error\n";
                    return false;
                }
                
                else if (c == ')' && myStack.Peak() == '(' || c == '}' && myStack.Peak() == '{'  || c == ']' && myStack.Peak() == '[')
                {
                    myStack.Pop();
                }
                else
                return false;
            }
            
        }
        return myStack.isEmpty();
        
    }
};

int main() {
    Stack myStack;
    string exp = "{[(4+5+7)]}";
    string exp2 = "{[(4+5+7)]";
     if (myStack.BalanceCheck(exp) == true) {
        cout << exp << " -> Balanced" << endl;
    } else {
        cout << exp << " -> Not Balanced" << endl;
    }
    if (myStack.BalanceCheck(exp2) == true) {
        cout << exp2 << " -> Balanced" << endl;
    } else {
        cout << exp2 << " -> Not Balanced" << endl;
    }
    return 0;
}
