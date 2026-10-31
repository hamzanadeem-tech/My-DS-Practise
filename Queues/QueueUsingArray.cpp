#include <iostream>
using namespace std;

const int QueueSize = 6;

class Queue
{
public:
    int Front;
    int Rear;
    int QueueArray[QueueSize];
    Queue()
    {
        Front = Rear = -1;
    }
    bool IsFull()
    {
        if (Rear + 1 == QueueSize)
        {
            return true;
        }
        else
            return false;
    }
    bool IsEmpty()
    {
        return Front == -1;
    }
    void Enqueue(int d)
    {
        if (IsFull())
        {
            cout << "Queue is already full. Cannot Enqueue anything.";
            return;
        }
        else if (IsEmpty())
        {
            Front = Rear = 0;
            QueueArray[Rear] = d;
        }
        else
        {
            Rear++;
            QueueArray[Rear] = d;
        }
    }
    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Cannot dequeue anything. Queue is empty.";
            return;
        }
        else if (Front == Rear)
        {
            Front = Rear = -1;
        }
        else
        {
            Front++;
        }
    }
    int Size()
    {
        if (IsEmpty())
        {
            return 0;
        }
        else
            return Rear - Front + 1;
    }
    void Display()
    {
        if (IsEmpty())
        {
            cout << "Cannot display anything. Queue is empty.";
            return;
        }
        for (int i = Front; i <= Rear; i++)
        {
            cout << QueueArray[i] << "\t";
        }
        cout << endl;
    }
    int GetFront()
    {
        if (IsEmpty())
        {
            cout << "No front. Queue is empty.";
            return -1;
        }
        else
            return QueueArray[Front];
    }
};

int main()
{
    Queue q;

    cout << "--- Enqueuing 6 Elements (Filling the Queue) ---" << endl;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Display();
    cout << "Current Size: " << q.Size() << endl;

    cout << "\n--- Trying to Enqueue when Full ---" << endl;
    q.Enqueue(70);

    cout << "\n--- Dequeuing 2 Elements ---" << endl;
    q.Dequeue();
    q.Dequeue();
    q.Display();
    cout << "Front Element: " << q.GetFront() << endl;
    cout << "Current Size: " << q.Size() << endl;

    return 0;
}