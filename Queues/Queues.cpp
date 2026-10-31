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
class Queue
{
public:
    Node *Front;
    Node *Rear;
    Queue()
    {
        Front = Rear = nullptr;
    }
    bool IsEmpty()
    {
        if (Front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Enqueue(int d)
    {
        Node *Temp = new Node;
        Temp->data = d;
        if (IsEmpty())
        {
            Front = Rear = Temp;
        }
        else
        {
            Rear->Next = Temp;
            Rear = Temp;
        }
    }
    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is already empty. Cannot dequeue anything";
            return;
        }
        else if (Front == Rear)
        {
            Front = Rear = nullptr;
        }
        else
        {
            Front = Front->Next;
        }
    }
    int GetFront()
    {
        if (IsEmpty())
        {
            cout << "Queue is already empty. Cannot get front";
            return -1;
        }
        else
            return Front->data;
    }
    void Display()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty. Nothing to display.";
            return;
        }
        else
        {
            Node *Temp = Front;
            while (Temp != nullptr)
            {
                cout << Temp->data << "\t";
                Temp = Temp->Next;
            }
        }
    }
};

int main()
{
    Queue q;

    cout << "--- Testing Empty Queue ---" << endl;
    q.Display();
    q.Dequeue();

    cout << "\n--- Enqueuing Elements (10, 20, 30) ---" << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();

    cout << "\n--- Checking Front Element ---" << endl;
    cout << "Front element is: " << q.GetFront() << endl;

    cout << "\n--- Dequeuing One Element ---" << endl;
    q.Dequeue();
    q.Display();
    cout << "New Front element is: " << q.GetFront() << endl;

    cout << "\n--- Dequeuing Remaining Elements ---" << endl;
    q.Dequeue();
    q.Dequeue();
    q.Display();

    return 0;
}