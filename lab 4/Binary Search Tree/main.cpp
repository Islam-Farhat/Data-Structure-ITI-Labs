#include <iostream>

using namespace std;
class Node
{
    public:
        int Data;
        Node *Left, *Right;

        Node(int data)
        {
            Data = data;
            Left = Right = NULL;
        }
};

class Tree
{
    Node *root;

    public:
        Tree() {root = NULL;}

        void Add(int data)
        {
            Node *node = new Node(data);

            if(root == NULL)
            {
                root = node;
            }
            else
            {
                Node *current = root;
                Node *parent;

                while(current != NULL)
                {
                    parent = current;

                    if(data > current->Data)
                        current = current->Right;
                    else
                        current = current->Left;
                }

                if(data > parent->Data)
                    parent->Right = node;
                else
                    parent->Left = node;

            }
        }

        void Remove(int data)
        {
            Node *node = GetNodeByData(data);

            if(node == NULL)
                return;

            if(node == root)
            {
                if(root->Left == NULL && root->Right == NULL)
                {
                    root = NULL;
                }
                else if(root->Right == NULL)
                {
                    root = root->Left;
                }
                else if(root->Left == NULL)
                {
                    root = root->Right;
                }
                else
                {
                    Node *newRoot = root->Left;
                    Node *maxRight = GetMaxRight(newRoot);

                    maxRight->Right = root->Right;
                    root = newRoot;
                }
            }
            else
            {
                Node *parent = GetParent(node);
                Node *newChild;

                if(node->Left == NULL && node->Right == NULL)
                {
                    newChild = NULL;
                }
                else if(node->Right == NULL)
                {
                    newChild = node->Left;
                }
                else if(node->Left == NULL)
                {
                    newChild = node->Right;
                }
                else
                {
                    Node *newParent = node->Left;
                    Node *maxRight = GetMaxRight(newParent);

                    maxRight->Right = node->Right;

                    newChild = newParent;
                }

                if(parent->Left == node)
                    parent->Left = newChild;
                else
                    parent->Right = newChild;
            }

            delete node;
        }

        void Traverse()
        {
            Display(root);
        }

         int GetHigh()
        {
           return GetMaxDepth(root);
        }


    protected:

    private:

        Node* GetNodeByData(int data)
        {
            Node *current = root;

            while(current != NULL)
            {
                if(data == current->Data)
                    return current;

                if(data > current->Data)
                    current = current->Right;
                else
                    current = current->Left;
            }

            return NULL;
        }

        Node* GetParent(Node *node)
        {
            Node *parent = root;

            while(parent != NULL)
            {
                if(parent->Left == node || parent->Right == node)
                    return parent;

                if(node->Data > parent->Data)
                    parent = parent->Right;
                else
                    parent = parent->Left;
            }

            return NULL;
        }

        Node* GetMaxRight(Node *node)
        {
            while(node->Right != NULL)
                node = node->Right;

            return node;
        }
        void Display(Node *node)
        {

            if(node == NULL)
                return;
            Display(node->Left);
            cout << node->Data << "   ";
            Display(node->Right);

        }

         int GetMaxDepth(Node * root)
        {
            if(root == NULL)
                return 0;

            //int test=root->Data;
            int leftTreeHigh = GetMaxDepth(root->Left);
            int rightTreeHigh = GetMaxDepth(root->Right);

            if (leftTreeHigh > rightTreeHigh)
                return leftTreeHigh + 1;
            else
                return rightTreeHigh + 1;

        }
};

int main()
{

    Tree tree;

    tree.Add(100);
    tree.Add(200);
    tree.Add(120);
    tree.Add(220);
    tree.Add(50);
    tree.Add(30);
    tree.Add(60);
    tree.Add(59);
    tree.Add(58);
    tree.Add(70);

    cout<<"Max Depth: "<<tree.GetHigh();


    return 0;
}
