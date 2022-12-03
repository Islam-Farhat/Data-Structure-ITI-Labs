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

class Queue
{
   public:
    Node *front;
    Node *rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    void EnQueue(int data)
    {
        Node *newNode = new Node(data);
        if(front == NULL)
        {
            front=newNode;
            rear=newNode;
            return;
        }
        else{
            rear->Next=newNode;
            rear=newNode;
        }
    }
    int DeQueue(int *data)
    {
        if(front==NULL)
            return 0;
        *data =front->Data;
        front=front->Next;
        return 1;
    }
    int Peek()
    {
        return front->Data;
    }
    void Display()
    {
        Node *current = front;

        while(current != NULL)
        {
            cout << current->Data<<"\n";
            current = current->Next;
        }
    }
};

int main()
{
    Queue queue;
    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);
    queue.EnQueue(4);
    queue.Display();

    cout<<"Peek: "<<queue.Peek()<<"\n";

    int value;
    queue.DeQueue(&value);
    cout<<"Value: "<<value<<endl;
    queue.DeQueue(&value);
    cout<<"Value: "<<value<<endl;
    queue.DeQueue(&value);
    cout<<"Value: "<<value<<endl;
    queue.DeQueue(&value);
    cout<<"Value: "<<value<<endl;

    queue.Display();

    return 0;
}
