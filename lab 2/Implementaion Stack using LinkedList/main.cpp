#include <iostream>

using namespace std;

class Node
{
    public:
        int Data;
        Node *Prev, *Next;

        Node(int data)
        {
            Data = data;
            Prev = Next = NULL;
        }
};

class Stack
{
   public:
    Node *top;
    Stack()
    {
        top=NULL;
    }
    void Push(int data)
    {
        Node *newNode = new Node(data);
        newNode->Prev=top;
        top=newNode;
    }
    int Pop(int *data)
    {
        if(top==NULL)
            return 0;
        *data =top->Data;
        top=top->Prev;
        return 1;
    }
    int Peek()
    {
       return top->Data;
    }
    void Display()
    {
        Node *current = top;

        while(current != NULL)
        {
            cout << current->Data<<"\n";
            current = current->Prev;
        }
    }
};

int main()
{
    Stack stk;
    stk.Push(1);
    stk.Push(2);
    stk.Push(3);


    stk.Display();
    cout<<"Peek: "<<stk.Peek()<<"\n";

    int value;
    while(stk.Pop(&value))
    {
        cout<<"Value: "<<value<<endl;
    }

    stk.Display();

    return 0;
}
