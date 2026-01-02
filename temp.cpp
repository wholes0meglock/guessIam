#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    int key; 
    Node *left; 
    Node *right; 
    int height; 

    Node(int k) { 
        key = k; 
        left = nullptr; 
        right = nullptr; 
        height = 1; 
    }
}; 

int height(Node* n)
{
    if(n == nullptr)
    return 0;
    return n->height;
}

Node* rotateRight(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->right),height(y->left));
    x->height = 1 + max(height(x->left),height(x->right));

    return x;
}

Node* rotateLeft(Node* y)
{
    Node* x = y->right;
    Node* T2 = x->left;

    y->right = T2;
    x->left = y;

    y->height = 1 + max(height(y->left),height(y->right));
    x->height = 1 + max(height(x->left),height(x->right));

    return x;
}

int getBalance(Node* x)
{
    if(x == nullptr)
    return 0;
    return height(x->left) - height(x->right);
}

Node* insert(Node* root, int key)
{
    if(root == NULL)
    root = new Node(key);

    if(root->key < key)
    {root->right = insert(root->right,key);}

    else if(root->key > key)
    {root->left = insert(root->left,key);}
    else
    return root;

    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);


    if(balance > 1 && key < root->left->key)
    {
        return rotateRight(root);
    }
    if(balance < -1 && key > root->right->key)
    {
        return rotateLeft(root);
    }
    if(balance > 1 && key > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance < -1 && key < root->right->key)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
}
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}
int deleteNode(Node* &root, int key)
{
  if (!root)
        return 0; // not found

    if (key < root->key)
        deleteNode(root->left, key);
    else if (key > root->key)
        deleteNode(root->right, key);
    else {
        // node found
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                delete root;
                root = nullptr;
            } else {
                *root = *temp;
                delete temp;
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return 1;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance factor
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        root = rotateRight(root);

    // Left Right
    else if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }

    // Right Right
    else if (balance < -1 && getBalance(root->right) <= 0)
        root = rotateLeft(root);

    // Right Left
    else if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }

    return 1;  
}