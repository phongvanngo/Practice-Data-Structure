#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *left, *right;

public:
    Node(int _data = 0)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
    friend class BinarySearchTree;
};

class BinarySearchTree
{
    Node *root;
    BinarySearchTree()
    {
        root = NULL;
    };

    void Insert(int _data)
    {
        Node *child = new Node(_data);
        Node *father = root;
        if (root == NULL) {
            root = child;
            return;
        };

    }
};
