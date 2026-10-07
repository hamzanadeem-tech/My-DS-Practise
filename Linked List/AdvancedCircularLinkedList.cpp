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
            cout << "List is empty" << endl;
            return;
        }
        Node *Temp = First;
        do
        {
            cout << Temp->Data << "\t";
            Temp = Temp->Next;
        } while (Temp != First);
        cout << endl;
    }

    void Delete(int d)
    {
        if (First == nullptr)
        {
            cout << "Nothing to Delete" << endl;
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
                Node* nodeToDelete = First;
                First = First->Next;
                Last->Next = First;
                delete nodeToDelete;
                return; // Added return to prevent continuing into the rest of the function
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

    void Searching(int d)
    {
        if (First == nullptr)
        {
            cout << "List is empty. Can't find node." << endl;
            return;
        }

        Node *Temp = First;
        int count = 1;
        do
        {
            if (Temp->Data == d)
            {
                cout << "The Node which was being searched is found at position " << count << endl;
                return;
            }
            Temp = Temp->Next;
            count++;
        } while (Temp != First);

        cout << "Node not found" << endl;
    }

    void Swap(int d1, int d2)
    {
        if (First == nullptr) return;

        Node *Temp = First;
        Node *node1 = nullptr;
        Node *node2 = nullptr;
        
        do
        {
            if (Temp->Data == d1)
            {
                node1 = Temp;
            }
            if (Temp->Data == d2)
            {
                node2 = Temp;
            }
            if (node1 != nullptr && node2 != nullptr)
            {
                break;
            }
            Temp = Temp->Next;
        } while (Temp != First);

        if (node1 != nullptr && node2 != nullptr)
        {
            // Value swap is safest and most robust here
            int tempValue = node1->Data;
            node1->Data = node2->Data;
            node2->Data = tempValue;
        }
    }

    int FindMinimum()
    {
        if (First == nullptr) return -1; // Fallback

        Node *Temp = First;
        int min = Temp->Data;
        do
        {
            if (Temp->Data < min)
            {
                min = Temp->Data;
            }
            Temp = Temp->Next;
        } while (Temp != First);
        
        return min;
    }

    int FindMaximum()
    {
        if (First == nullptr) return -1; // Fallback

        Node *Temp = First;
        int max = Temp->Data;
        do
        {
            if (Temp->Data > max)
            {
                max = Temp->Data;
            }
            Temp = Temp->Next;
        } while (Temp != First);
        
        return max;
    }

    void AddBetween(int d, int DesiredLocation)
    {
        if (First == nullptr)
        {
            cout << "List is empty, can't add between" << endl;
            return;
        }

        if (First->Data == DesiredLocation)
        {
            cout << "We cannot insert data because it is the first " << endl;
            return;
        }

        Node *Curr = First->Next;
        Node *Prev = First;
        bool found = false;
        
        while (Curr != First)
        {
            if (Curr->Data == DesiredLocation)
            {
                found = true;
                break;
            }
            Prev = Curr;
            Curr = Curr->Next;
        }
        
        if (!found)
        {
            cout << "No target data found" << endl;
            return;
        }

        Node *Temp = new Node;
        Temp->Data = d;
        Prev->Next = Temp;
        Temp->Next = Curr;
    }

    void Sort()
    {
        if (First == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        
        // If there is only 1 node, no sorting is needed
        if (First->Next == First) 
        {
            return;
        }
        
        for (Node *i = First; i->Next != First; i = i->Next)
        {
            for (Node *j = i->Next; j != First; j = j->Next)
            {
                if (i->Data > j->Data)
                {
                    int tempValue = i->Data;
                    i->Data = j->Data;
                    j->Data = tempValue;
                }
            }
        }
    }

    void SortedInsert(int d)
    {
        Node *Temp = new Node;
        Temp->Data = d;

        // If list is empty
        if (First == nullptr)
        {
            First = Last = Temp;
            Last->Next = First;
            return;
        }

        // If needs to be inserted at the very beginning
        if (d < First->Data)
        {
            Temp->Next = First;
            First = Temp;
            Last->Next = First;
            return;
        }

        // Traverse to find the correct insertion point
        Node *Curr = First;
        while (Curr->Next != First && Curr->Next->Data < d)
        {
            Curr = Curr->Next;
        }

        // Insert Temp after Curr
        Temp->Next = Curr->Next;
        Curr->Next = Temp;

        // If we inserted at the very end, update Last
        if (Curr == Last)
        {
            Last = Temp;
        }
    }
};

int main()
{
    List myList;
    
    myList.AddNode(30);
    myList.AddNode(40);
    myList.AddNode(92);
    myList.AddNode(87);
    myList.AddNode(25);
    myList.AddNode(73);
    
    cout << "Original List:" << endl;
    myList.Display();
    
    cout << "\nDeleting 25:" << endl;
    myList.Delete(25);
    myList.Display();

    cout << "\nSearching for 92:" << endl;
    myList.Searching(92);

    cout << "\nSwapping 40 and 87:" << endl;
    myList.Swap(40, 87);
    myList.Display();
    
    cout << "\nMaximum Value: " << myList.FindMaximum() << endl;
    cout << "Minimum Value: " << myList.FindMinimum() << endl;

    cout << "\nTesting Sort:" << endl;
    myList.Sort();
    myList.Display();

    cout << "\nTesting SortedInsert (inserting 34):" << endl;
    myList.SortedInsert(34);
    myList.Display();
    
    cout << "\nTesting AddBetween (insert 50 before 73):" << endl;
    myList.AddBetween(50, 73);
    myList.Display();

    return 0;
}