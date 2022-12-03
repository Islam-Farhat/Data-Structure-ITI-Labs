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

class LinkedList
{
    Node *head, *tail;

    public:
        LinkedList()
        {
            head = tail = NULL;
        }

        void Add(int data)
        {
            Node *node = new Node(data);

            if(head == NULL)
            {
                head = tail = node;
            }
            else
            {
                node->Prev = tail;
                tail->Next = node;
                tail = node;
            }
        }

        void Display()
        {
            Node *current = head;

            while(current != NULL)
            {
                cout << current->Data<<"\n";
                current = current->Next;
            }
        }

        int Search(int data)
        {
            Node *node = GetNodeByData(data);

            return node != NULL;
        }

        void Remove(int data)
        {
             Node *node = GetNodeByData(data);

             if(node == NULL)
                return;

             if(node == head)
             {
                 if(node == tail)
                 {
                     head = tail = NULL;
                 }
                 else
                 {
                    head = head->Next;
                    head->Prev = NULL;
                 }
             }
             else if(node == tail)
             {
                 tail = tail->Prev;
                 tail->Next = NULL;
             }
             else
             {
                 /*Node *A = node->Prev;
                 Node *B = node->Next;

                 A->Next = B;
                 B->Prev = A;*/

                node->Prev->Next = node->Next;
                node->Next->Prev = node->Prev;
             }

             delete node;
        }

        void InsertAfter(int data, int afterData)
        {
            Node *node = GetNodeByData(afterData);
            Node *newNode = new Node(data);
            if(node == NULL)
            {
                Add(data);
            }
            else
            {
                node->Next->Prev=newNode;
                newNode->Next = node->Next;
                newNode->Prev = node;
                node->Next = newNode;
            }
        }

        int Count()
        {
            Node *current=head;
            int count=0;
            while(current != NULL)
            {
                count++;
                current=current->Next;
            }
            return count;
        }

        int GetDataByIndex(int index)
        {
            int allElements=Count();
            if(index >= allElements)
                return -1;
            else
            {
                Node *current=head;
                for(int i=0;i<index;i++)
                {
                    current=current->Next;
                }
                return current->Data;
            }
        }

        LinkedList* Reverse()
        {
            LinkedList *newList =new LinkedList();
            Node *current=head;
            while(current->Next != NULL)
            {

                current=current->Next;
            }
            while(current != NULL)
            {

                newList->Add(current->Data);
                current=current->Prev;

            }
            return newList;

        }
        void InPlaceReverse()
        {
            if(head==NULL || head->Next==NULL)
                return;
            Node *temp;
            temp=head;
            while(head!=NULL)
            {
                temp=head->Prev;
                head->Prev=head->Next;
                head->Next=temp;
                if (head->Prev == NULL)
                      return;
                else {head = head->Prev;}
            }
            return;
        }

        void BubbleSort()
        {
            int size=this->Count();
            int sorted = 0;

            for(int counter = 0; counter < size - 1 && sorted == 0; counter++)
            {
                Node *current=this->head;
                sorted = 1;

                for(int index = 0; index < size - 1 - counter; index++)
                {
                    if(current->Data > current->Next->Data )
                    {
                        int temp=current->Data;
                        current->Data=current->Next->Data;
                        current->Next->Data=temp;

                        sorted = 0;
                    }
                    current=current->Next;
                }
            }
        }

        int BinarySearch(int data)
        {
            int size=this->Count();
            int minIndex = 0, maxIndex = size - 1, midIndex;

            while(minIndex <= maxIndex)
            {
                midIndex = (minIndex + maxIndex) / 2;

                if(data == this->GetDataByIndex(midIndex))
                    return midIndex;

                if(data > this->GetDataByIndex(midIndex))
                    minIndex = midIndex + 1;
                else
                    maxIndex = midIndex - 1;
            }

            return -1;
        }

    private:

        Node* GetNodeByData(int data)
        {
            Node *current = head;

            while(current != NULL)
            {
                if(data == current->Data)
                    return current;

                current = current->Next;
            }

            return NULL;
        }
};




int main()
{
    LinkedList myList;

    myList.Add(100);
    myList.Add(19);
    myList.Add(6);
    myList.Add(7);
    myList.Add(9);
    myList.Add(3);
    myList.Add(4);//3 4 6 7 9 19 100


    myList.BubbleSort();
    myList.Display();

    int result=myList.BinarySearch(9);
    if(result == -1){cout<<"Item not found";}
    else{cout<<"Index: "<<result<<endl;}

    result = myList.BinarySearch(20);
    if(result == -1){cout<<"Item not found";}
    else{cout<<"Index: "<<result<<endl;}

    return 0;
}

