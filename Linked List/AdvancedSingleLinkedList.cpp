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
private:
    Node *First;
    Node *Last;

public:
    List()
    {
        First = Last = nullptr;
    }

    void Insert(int d)
    {
        Node *Temp = new Node();
        Temp->Data = d;
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
    };

    void Searching(int d)
    {
        int count = 1;
        if (First == nullptr)
        {
            cout << "List is empty . Can't find node." << endl;
            return;
        }

        Node *Temp = First;
        while (Temp != nullptr && Temp->Data != d)
        {
            Temp = Temp->Next;
            count++;
        }

        if (Temp == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        if (Temp->Data == d)
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
        }
        if (node1 != nullptr && node2 != nullptr)
        {
            int tempValue = node1->Data;
            node1->Data = node2->Data;
            node2->Data = tempValue;
        }
    }
    int FindMinimum()
    {
        Node *Temp = First;
        int min = Temp->Data;
        while (Temp != nullptr)
        {
            if (Temp->Data < min)
            {
                min = Temp->Data;
            }
            Temp = Temp->Next;
        }
        return min;
    }
    int FindMaximum()
    {
        Node *Temp = First;
        int max = Temp->Data;
        while (Temp != nullptr)
        {
            if (Temp->Data > max)
            {
                max = Temp->Data;
            }
            Temp = Temp->Next;
        }
        return max;
    }

    void Print()
    {
        if (First == nullptr)
        {
            cout << "List is empty";
            return;
        }
        Node *Temp = First;
        while (Temp != nullptr)
        {
            cout << Temp->Data << " ";
            Temp = Temp->Next;
        }
    };
    void AddBetween(int d, int DesiredLocation)
    {
        Node *Temp = new Node;
        Node *Curr = First;
        Node *Prev = nullptr;
        Temp->Data = d;
        if (First == nullptr)
        {
            cout << "List is empty can't add between";
            return;
        }

        if (First->Data == DesiredLocation)
        {
            cout << "We cannot insert data because it is the first ";
            return;
        }

        while (Curr != nullptr && Curr->Data != DesiredLocation)
        {
            Prev = Curr;
            Curr = Curr->Next;
        }
        if (Curr == nullptr)
        {
            cout << "No data found";
            return;
        }

        Prev->Next = Temp;
        Temp->Next = Curr;
    }

    void Sort()
    {
        if (First == nullptr || First->Next == nullptr)
        {
            return;
        }

        bool swapped;
        do
        {
            swapped = false;

            Node *Prev = nullptr;
            Node *Curr = First;

            while (Curr != nullptr && Curr->Next != nullptr)
            {
                if (Curr->Data > Curr->Next->Data)
                {
                    Node *NextNode = Curr->Next;

                    if (Prev == nullptr)
                    {
                        First = NextNode;
                    }
                    else
                    {
                        Prev->Next = NextNode;
                    }

                    Curr->Next = NextNode->Next;
                    NextNode->Next = Curr;

                    Prev = NextNode;
                    swapped = true;
                }
                else
                {
                    Prev = Curr;
                    Curr = Curr->Next;
                }
            }
        } while (swapped);

        Node *Temp = First;
        while (Temp != nullptr && Temp->Next != nullptr)
        {
            Temp = Temp->Next;
        }
        Last = Temp;
    }


    void SortedInsert(int d){
      Node *Temp = new Node;
      Temp->Data = d;
      Temp->Next = nullptr;
      if (First == nullptr || d < First->Data)
      {
        Temp->Next = First;
        First = Temp;
        return;
      }
      Node *Temp2 = First;
      while(Temp2->Next != nullptr && Temp2->Next->Data < d)
      {
        Temp2 = Temp2->Next;
      }
      Temp->Next = Temp2->Next;
      Temp2->Next = Temp;      
    }
};

int main()
{
    List myList;
    myList.Insert(23);
    myList.Insert(24);
    myList.Insert(92);
    myList.Insert(87);
    myList.Insert(73);
    myList.Searching(65);
    myList.Swap(65, 45);
    cout << myList.FindMaximum() << endl;
    cout << myList.FindMinimum() << endl;
    myList.SortedInsert(34);
    myList.Sort();
    myList.Print();
    return 0;
}