#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;
    Node()
    {
        data = 0;
        Next = nullptr;
    }
};

class LinkedList
{
public:
    Node *First;
    Node *Last;

    LinkedList()
    {
        First = Last = nullptr;
    }

    void AddItem(int d)
    {
        Node *Temp = new Node;
        Temp->data = d;
        if (First == nullptr)
        {
            First = Temp;
            Last = Temp;
        }
        else
        {
            Last->Next = Temp;
            Last = Temp;
        }
    }
    void Display()
    {
        if (First == nullptr)
        {
            cout << "List is empty";
            return;
        }
        Node *temp = First;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->Next;
        }
    }
};

int main()
{
    LinkedList myList;
    myList.AddItem(20);
    myList.AddItem(30);
    myList.Display();
    return 0;
}