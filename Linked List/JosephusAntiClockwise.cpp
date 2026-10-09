// Method 1: Singly Linked List (Reversed Creation)
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
    Node *CreateCircle(int n)
    {
        Node *First = new Node;
        First->Data = 1;
        Node *Curr = First;
        for (int i = n; i >= 2; i--)
        {
            Node *Temp = new Node;
            Temp->Data = i;
            Curr->Next = Temp;
            Curr = Temp;
        }
        Curr->Next = First;
        return First;
    }
    int Josephus(int n, int k)
    {
        Node *Head = CreateCircle(n);
        Node *Curr = Head;
        while (Head->Next != Head)
        {
            for (int i = 1; i < k; i++)
            {
                Curr = Head;
                Head = Head->Next;
            }
            Curr->Next = Head->Next;
            Node *Temp = Head;
            Head = Head->Next;
            delete Temp;
        }
        int data = Head->Data;
        delete Head;
        return data;
    }
};

int main()
{
    List myList;
    cout << "The survivor of the josephus circle is " << myList.Josephus(10, 3);
    return 0;
}


// Method 2: Doubly Linked List (Anticlockwise Traversal)

#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
    Node *Prev;
    Node()
    {
        Data = 0;
        Next = nullptr;
        Prev = nullptr;
    }
};

class List
{
public:
    Node *CreateCircle(int n)
    {
        Node *First = new Node;
        First->Data = 1;
        Node *Curr = First;
        for (int i = 2; i <= n; i++)
        {
            Node *Temp = new Node;
            Temp->Data = i;
            Curr->Next = Temp;
            Temp->Prev = Curr;
            Curr = Temp;
        }
        Curr->Next = First;
        First->Prev = Curr;
        return First;
    }
    int Josephus(int n, int k)
    {
        Node *Head = CreateCircle(n);
        Node *Curr = Head;
        while (Head->Prev != Head)
        {
            for (int i = 1; i < k; i++)
            {
                Curr = Head;
                Head = Head->Prev;
            }
            Curr->Prev = Head->Prev;
            Head->Prev->Next = Curr;
            Node *Temp = Head;
            Head = Head->Prev;
            delete Temp;
        }
        int data = Head->Data;
        delete Head;
        return data;
    }
};

int main()
{
    List myList;
    cout << "The survivor of the josephus circle is " << myList.Josephus(10, 3);
    return 0;
}