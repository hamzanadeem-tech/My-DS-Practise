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
            cout << "Nothing to delete" << endl;
            return;
        }
        if (First->data == d)
        {
            First = First->Next;
            if (First == nullptr)
            {
                cout << "The only node deleted" << endl;
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
            Curr->Next->Prev = Foll;
            delete Curr;
        }
    }

    void Searching(int d)
    {
        int count = 1;
        if (First == nullptr)
        {
            cout << "List is empty. Can't find node." << endl;
            return;
        }

        Node *Temp = First;
        while (Temp != nullptr && Temp->data != d)
        {
            Temp = Temp->Next;
            count++;
        }

        if (Temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        if (Temp->data == d)
        {
            cout << "The Node which was being searched is found at position " << count << endl;
            return;
        }
    }

    void Swap(int d1, int d2)
    {
        Node *Temp = First;
        Node *node1 = nullptr;
        Node *node2 = nullptr;

        while (Temp != nullptr)
        {
            if (Temp->data == d1)
            {
                node1 = Temp;
            }
            if (Temp->data == d2)
            {
                node2 = Temp;
            }
            if (node1 != nullptr && node2 != nullptr)
            {
                break;
            }
            Temp = Temp->Next;
        }

        if (node1 != nullptr && node2 != nullptr)
        {
            // Swapping the data (values) instead of the pointers
            int tempValue = node1->data;
            node1->data = node2->data;
            node2->data = tempValue;
        }
    }

    int FindMinimum()
    {
        if (First == nullptr)
            return -1; // Fallback for empty list

        Node *Temp = First;
        int min = Temp->data;
        while (Temp != nullptr)
        {
            if (Temp->data < min)
            {
                min = Temp->data;
            }
            Temp = Temp->Next;
        }
        return min;
    }

    int FindMaximum()
    {
        if (First == nullptr)
            return -1; // Fallback for empty list

        Node *Temp = First;
        int max = Temp->data;
        while (Temp != nullptr)
        {
            if (Temp->data > max)
            {
                max = Temp->data;
            }
            Temp = Temp->Next;
        }
        return max;
    }

    void AddBetween(int d, int DesiredLocation)
    {
        if (First == nullptr)
        {
            cout << "List is empty, can't add between" << endl;
            return;
        }

        if (First->data == DesiredLocation)
        {
            cout << "We cannot insert data because it is the first " << endl;
            return;
        }

        Node *Curr = First;
        while (Curr != nullptr && Curr->data != DesiredLocation)
        {
            Curr = Curr->Next;
        }

        if (Curr == nullptr)
        {
            cout << "No data found" << endl;
            return;
        }

        // Inserting Temp before Curr
        Node *Temp = new Node;
        Temp->data = d;

        Node *PrevNode = Curr->Prev;
        PrevNode->Next = Temp;
        Temp->Prev = PrevNode;
        Temp->Next = Curr;
        Curr->Prev = Temp;
    }

    void Sort()
    {
        if (First == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        for (Node *i = First; i != nullptr; i = i->Next)
        {
            for (Node *j = i->Next; j != nullptr; j = j->Next)
            {
                if (i->data > j->data)
                {
                    int tempValue = i->data;
                    i->data = j->data;
                    j->data = tempValue;
                }
            }
        }
    }
    void SortedInsert(int d)
    {
        Node *Temp = new Node;
        Temp->data = d;

        // If list is empty
        if (First == nullptr)
        {
            First = Last = Temp;
            return;
        }

        // If needs to be inserted at the very beginning
        if (d < First->data)
        {
            Temp->Next = First;
            First->Prev = Temp;
            First = Temp;
            return;
        }

        // Traverse to find the correct insertion point
        Node *Curr = First;
        while (Curr->Next != nullptr && Curr->Next->data < d)
        {
            Curr = Curr->Next;
        }

        // Insert Temp after Curr
        Temp->Next = Curr->Next;
        if (Curr->Next != nullptr)
        {
            Curr->Next->Prev = Temp;
        }
        else
        {
            Last = Temp; // Inserted at the very end
        }
        Curr->Next = Temp;
        Temp->Prev = Curr;
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
        cout << endl;
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
        cout << endl;
    }
};

int main()
{
    List myList;

    // Test base additions
    myList.AddItem(23);
    myList.AddItem(24);
    myList.AddItem(92);
    myList.AddItem(87);
    myList.AddItem(73);

    cout << "Original List:" << endl;
    myList.DisplayForward();

    cout << "\nSearching for 92:" << endl;
    myList.Searching(92);

    cout << "\nSwapping 24 and 87:" << endl;
    myList.Swap(24, 87);
    myList.DisplayForward();

    cout << "\nMaximum Value: " << myList.FindMaximum() << endl;
    cout << "Minimum Value: " << myList.FindMinimum() << endl;

    cout << "\nTesting Sort:" << endl;
    myList.Sort();
    myList.DisplayForward();

    cout << "\nTesting SortedInsert (inserting 34):" << endl;
    myList.SortedInsert(34);
    myList.DisplayForward();

    cout << "\nTesting AddBetween (insert 50 before 73):" << endl;
    myList.AddBetween(50, 73);
    myList.DisplayForward();

    cout << "\nVerify Prev pointers via DisplayBackward:" << endl;
    myList.DisplayBackward();

    return 0;
}