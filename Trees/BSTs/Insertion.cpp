#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Left;
    Node *Right;
    Node()
    {
        Data = 0;
        Left = Right = nullptr;
    }
};
class BST
{
public:
    Node *Root;
    BST()
    {
        Root = nullptr;
    }
    void Insert(int d)
    {
        Node *Temp = new Node();
        Temp->Data = d;
        if (Root == nullptr)
        {
            Root = Temp;
            return;
        }
        Node *Curr = Root;
        Node *Parent = nullptr;
        while (Curr != nullptr)
        {
            Parent = Curr;
            if (d > Curr->Data)
            {
                Curr = Curr->Right;
            }
            else
                Curr = Curr->Left;
        }
        if (d > Parent->Data)
        {
            Parent->Right = Temp;
        }
        else
            Parent->Left = Temp;
    }
};

int main()
{
    BST tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    return 0;
}