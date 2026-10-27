#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
public:
    Node* top;
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if (top == NULL)
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
        Node* newNode = new Node(d);
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
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
            cout << "The top most element of the stack is " << top->data;
        }
    }
    void Size()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        int count = 0;
        Node* temp = top;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "The number of value inside the stack is " << count;
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
            Node* temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
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