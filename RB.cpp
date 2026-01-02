#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left,*right,*parent;
    bool colour; //true is Red, false is Blue

    Node(int d)
    {
        data = d;
        left = right = parent = nullptr;
        colour = true;
    }
};


class RedBlack
{
    Node* root;
    public:
    RedBlack(int d)
    {
        root = new Node(d);
    }
    void BSTInsert(Node* &root, Node* &node)
    {
        if (!root){
            root = node;
            return;}
        if(node->data == root->data)
        {
            cout << "invalid" << endl;
            return;
        }
        if(node->data < root->data)
        {
            if(root->left)
            BSTInsert(root->left,node);
            else
        {
            root->left = node;
            node->parent = root;
        }
        }
        else
        {
            if(root->right)
            BSTInsert(root->right,node);
            else
            {
                root->right = node;
                node->parent = root;
            }
        } 
    }

    Node* leftRotate(Node* root)
    {
        Node* x = root->right;
        Node* y = x->left;
        x->left = root;
        root->right = y;
        root->parent = x;
        if(y)
        y->parent = root;
        return x;
    }
    Node* rightRotate2(Node* root)
    {
        Node* x = root->left;
        Node* y = x->right;
        y = x->right;
        y = root->left;
        root = x->right;
        root->parent = x;
        if(y)
        {
        y->parent = root;
        }
        return x;
    }
    void fixViolation(Node* &root,Node* &node)
    {
        while(node != root && node->parent->colour == true)
        {
            Node* parent = node->parent;
            Node* grand = parent->parent;
            if(parent == grand->left)
            {
                Node* uncle = grand->right;
                if(uncle && uncle->colour == true)
                {
                    parent->colour = false;
                    uncle->colour = false;
                    grand->colour = true;
                    node = grand;
                }
                else
                {
                    if(node = parent->right)
                    {
                        if (node == root) root = leftRotate(node);
                        else node->parent->left == node ? node->parent->left = leftRotate(node):node->parent->right = leftRotate(node);
                    }
                    parent->colour = false;
                    grand->colour = true;
                    if (grand == root) root = rightRotate2(grand);
                    else grand->parent->left == grand ? grand->parent->left = rightRotate2(grand):grand->parent->right = rightRotate2(grand);

                }
            }
            else
            {
                Node* uncle  = grand->left;
                if(uncle && uncle->colour == true)
                {
                    parent->colour = false;
                    grand->colour = true;
                    uncle->colour = false;
                    node = grand;
                }
                else
                {
                    if(node == parent->left)
                    {
                        node = parent;
                        parent = rightRotate2(parent);
                    }
                    parent->colour = false;
                    grand->colour = true;

                    Node* rotated = leftRotate(grand);
                    rotated->parent = grand->parent;
                    if(!rotated->parent)
                    root = rotated;

                    else if(rotated->parent->left == grand)
                    rotated->parent->left = rotated;

                    else 
                    rotated->parent->right = rotated;
                }
            }
        }
        root->colour = false;
    }
    void insert(Node* &root, int data) {
    Node* node = new Node(data);
    BSTInsert(root, node);
    fixViolation(root, node);
}
};
int main()
{

}



