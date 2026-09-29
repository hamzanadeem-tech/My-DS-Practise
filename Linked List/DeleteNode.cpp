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
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = First;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->Next;
        }
    }

    void Delete(int d)
    {
        // List is empty
        if (First == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        // Node is present at the start of the list
        if (First->data == d)
        {
            First = First->Next;
            cout << "Node at 1st position is deleted." << endl;
            // If node is both first and last . Only 1 node.
            if (First == nullptr)
            {
                cout << "There was only 1 node in the list" << endl;
                Last = nullptr;
            }
            return;
        }
        Node *Curr = First;
        Node *Prev = nullptr;
        // If removing from center of the list
        while (Curr != nullptr && Curr->data != d)
        {
            Prev = Curr;
            Curr = Curr->Next;
        }
        // If we reached the end and didn't find the data
        if (Curr == nullptr)
        {
            cout << "Data not found" << endl;
            return;
        }
        // If removing from last
        if (Curr == Last)
        {
            Prev->Next = nullptr;
            Last = Prev;
        }
        // If removing from center
        else
        {
            Prev->Next = Curr->Next;
        }

        delete Curr;
    }
};

int main()
{
    LinkedList myList;
    myList.AddItem(20);
    myList.AddItem(30);
    myList.AddItem(40);
    myList.AddItem(50);
    myList.Delete(30);
    myList.Display();
    return 0;
}