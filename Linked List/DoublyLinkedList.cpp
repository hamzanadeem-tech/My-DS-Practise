#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;
    Node *Prev;
    Node()
    {
        data = 0;
        Next = Prev = nullptr;
    }
};
class List
{
public:
    Node *First;
    Node *Last;
    List()
    {
        First = Last = nullptr;
    }
    void AddItem(int d)
    {
        Node *Temp = new Node;
        Temp->data = d;
        if (First == nullptr)
        {
            Last = Temp;
            First = Temp;
        }
        else
        {
            Last->Next = Temp;
            Temp->Prev = Last;
            Last = Temp;
        }
    }
    void Delete(int d)
    {
        if (First == nullptr)
        {
            cout << "Nothing to delete";
            return;
        }
        if (First->data == d)
        {
            First = First->Next;
            if (First == nullptr)
            {
                cout << "The only node deleted";
                Last = nullptr;
            }
            else
            {
                First->Prev = nullptr;
            }
            return;
        }
        Node *Curr = First;
        Node *Foll = nullptr;
        while (Curr != nullptr && Curr->data != d)
        {
            Foll = Curr;
            Curr = Curr->Next;
        }
        if (Curr == nullptr)
        {
            cout << "No data Found to delete" << endl;
            return;
        }
        if (Curr == Last)
        {
            Foll->Next = nullptr;
            Curr->Prev = nullptr;
            Last = Foll;
        }
        else
        {
            Foll->Next = Curr->Next;
            Curr = Curr->Next;
            Curr->Prev = Foll;
        }
    }
    void DisplayForward()
    {
        if (First == nullptr)
        {
            cout << "Nothing to display. List is empty." << endl;
            return;
        }
        Node *Temp = First;
        while (Temp != nullptr)
        {
            cout << Temp->data << "\t";
            Temp = Temp->Next;
        }
    }
    void DisplayBackward()
    {
        if (First == nullptr)
        {
            cout << "Nothing to display. List is empty." << endl;
            return;
        }
        Node *Temp = Last;
        while (Temp != nullptr)
        {
            cout << Temp->data << "\t";
            Temp = Temp->Prev;
        }
    }
};

int main()
{
    List myList;
    myList.AddItem(30);
    myList.AddItem(20);
    myList.AddItem(25);
    myList.AddItem(45);
    myList.Delete(30);
    myList.AddItem(10);
    myList.DisplayBackward();
    return 0;
}