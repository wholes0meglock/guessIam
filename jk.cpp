#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class BinaryTree
{
    public:
    Node* root;
    BinaryTree(int val)
    {
        root = new Node(val);
    }
    void inorder(Node* root)
    {
        if(!root) return;
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
    void preorder(Node* root)
    {
        if(!root) return;
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root)
    {
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data  << endl;
    }
    void inorderI(Node* root)
    {
        stack<Node*> s;
        Node* curr = root;
        while(curr != NULL || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << endl;
            curr = curr->right;
        }
    }
    void PreOrderI(Node* root)
    {
        if(root == nullptr) return;
        stack<Node*> s;
        s.push(root);
        Node* curr;
        while(!s.empty())
        {
            curr = s.top();
            s.pop();
            cout << curr->data << endl;
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
    }
    void PostorderI(Node* root)
    {
        if(root == nullptr) return;
        stack<Node*> st1,st2;
        st1.push(root);
        while(!st1.empty())
        {
            Node* curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        while(!st2.empty())
        {
            cout << st2.top()->data << endl;
            st2.pop();
        }
    }
    bool findpath(Node* &root, vector<int>& path)
    {
        if(!root) return false;
        path.push_back(root->data);
        bool found = false;
        if(!root->left && !root->right)
        {
            for(int i : path)
            {
                cout << i << endl;
            }
            found = true;
        }
        if(findpath(root->left,path)) found = true;
        if(findpath(root->right,path)) found = true;
        path.pop_back();
        return found;
    }
};

class BST
{
    public:
    Node* root;
    BST(int val)
    {
        root = new Node(val);
    }
    // inorder postorder preorder is the same.


};