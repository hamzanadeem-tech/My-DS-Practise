#include <iostream>
using namespace std;

const int QueueSize = 6;

class Queue
{
public:
    int Front;
    int Rear;
    int QueueArray[QueueSize];

    Queue() { Front = Rear = -1; }

    bool IsEmpty()
    {
        if (Front == -1)
            return true;
        else
            return false;
    }

    bool IsFull()
    {
        if (Front == (Rear + 1) % QueueSize)
        {
            return true;
        }
        else
            return false;
    }

    void Enque(int d)
    {
        if (IsFull())
        {
            return;
        }
        else if (IsEmpty())
        {
            Front = Rear = 0;
            QueueArray[Rear] = d;
        }
        else
        {
            Rear = (Rear + 1) % QueueSize;
            QueueArray[Rear] = d;
        }
    }

    void Deque()
    {
        if (IsEmpty())
        {
            return;
        }
        else if (Front == Rear)
        {
            Front = Rear = -1;
        }
        else
        {
            Front = (Front + 1) % QueueSize;
        }
    }

    int GetFront()
    {
        if (IsEmpty())
            return 0;
        else
            return QueueArray[Front];
    }

    int GetSize()
    {
        if (IsEmpty())
            return 0;
        else if (Rear >= Front)
        {
            return Rear - Front + 1;
        }
        else
        {
            return Rear - Front + 1 + QueueSize;
        }
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "cannot display anything. Queue is emepty.";
            return;
        }
        int x = Front;
        while (true)
        {
            cout << QueueArray[x] << "\t";
            if (x == Rear)
                break;
            x = (x + 1) % QueueSize;
        }
    }
};

int main()
{
    Queue q;

    q.Enque(10);
    q.Enque(20);
    q.Enque(30);
    q.Enque(40);

    cout << "Current Queue: ";
    q.Display();
    cout << endl;

    cout << "Size: " << q.GetSize() << endl;
    cout << "Front Element: " << q.GetFront() << endl;

    q.Deque();
    cout << "After 1 Deque: ";
    q.Display();

    return 0;
}