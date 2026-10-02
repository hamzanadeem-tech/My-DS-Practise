#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
    Node()
    {
        Data = 0;
        Next = nullptr;
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
    void AddNode(int d)
    {
        Node *Temp = new Node;
        Temp->Data = d;
        if (First == nullptr)
        {
            Last = First = Temp;
            Last->Next = First;
        }
        else
        {
            Last->Next = Temp;
            Last = Temp;
            Last->Next = First;
        }
    }
    void Display()
    {
        if (First == nullptr)
        {
            cout << "List is empty";
            return;
        }
        Node *Temp = First;
        do
        {
            cout << Temp->Data << endl;
            Temp = Temp->Next;
        } while (Temp != First);
    }
    void Delete(int d)
    {
        if (First == nullptr)
        {
            cout << "Nothing to Delete";
            return;
        }
        if (First->Data == d)
        {
            if (First == Last)
            {
                delete First;
                First = Last = nullptr;
                cout << "The only node deleted" << endl;
                return;
            }
            else
            {
                First = First->Next;
                Last->Next = First;
            }
        }
        Node *Curr = First;
        Node *Prev = nullptr;
        do
        {
            Prev = Curr;
            Curr = Curr->Next;
        } while (Curr != First && Curr->Data != d);
        if (Curr == First)
        {
            cout << "No data found to delete" << endl;
            return;
        }
        if (Curr == Last)
        {
            Prev->Next = First;
            Last = Prev;
        }
        else
        {
            Prev->Next = Curr->Next;
        }
        delete Curr;
    }
};

int main()
{
    List myList;
    myList.AddNode(30);
    myList.AddNode(40);
    myList.AddNode(25);
    myList.Delete(25);
    myList.Display();
    return 0;
}