#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
class BinaryTree
{
    public:
    Node* root;
    BinaryTree(int value)
    {
        root = new Node(value);
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
        cout << root->data << endl;
    }
    void levelOrder(Node* root)
    {
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
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
    void InsertNode(Node*& root,int value)
    {
        Node* newNode = new Node(value);
        if(!root) 
        root = newNode;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
        Node* temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = newNode;
            return;
        }
        else{q.push(temp->left);}
        if(!temp->right)
        {
            temp->right = newNode;
            return;
        }
        else{q.push(temp->right);}
        }
        return;
    }
    bool search(Node* root,int value)
    {
        if(!root) return false;
        if(root->data == value) return true;
        while(root)
        {
            return search(root->left,value)||search(root->right,value);
        }
    }
    int height(Node *root) {
    if (root == nullptr)
        return -1;
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;
}
    void delDeepestNodebyDnode(Node*& root,Node* delNode)
    {
        if(!root)
        {
            cout << "not found" << endl;
            return;
        }
        queue<Node*> q;
        q.push(root);
        Node* temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp == delNode)
            {
                temp = nullptr;
                delete (delNode);
                return;
            }
            if(temp->right)
            {
                if(temp->right == delNode)
                {
                    temp->right = nullptr;
                    delete (delNode);
                    return;
                }
                q.push(temp->right);
            }
            if(temp->left)
            {
                if(temp->left == delNode)
                {
                    temp->left = nullptr;
                    delete(delNode);
                    return;
                }
                q.push(temp->left);
            }
        }

    }
    void delbyValue(Node*& root, int value)
    {
        if(!root)
        {cout<<"not found"; return;}
        if(!root->left && !root->right)
        {
            if(root->data == value)
            {
                delete root;
                root = nullptr;
            }
            return;
        }
        queue<Node*> q;
        Node* temp;
        q.push(root);
        Node* keyNode = nullptr;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->data == value)
            {
                keyNode = temp;
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        if(!keyNode)
        return;
        int x = temp->data;
        delDeepestNodebyDnode(root,temp);
        keyNode->data = x;
    }
    bool FIndPath(Node* root, int target, int sum = 0, vector<int>& path)
    {
        if(!root) return false;
        path.push_back(root->data);
        sum += root->data;
        bool found = false;
        if(!root->left && !root->right && sum == target)
        {
            cout << "Path found: ";
            for(int i : path)
            cout << i << " ";
            found = true;
            // path.pop_back();
        }
        if (FIndPath(root->left, target, sum, path)) found = true;
        if (FIndPath(root->right, target, sum, path)) found = true;
        path.pop_back();
        return found;
    }
    //better one
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

    vector<Node*> viewRight(Node* root)
    {
     vector<Node*> ans;
     vector<int> levelCounts;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        levelCounts.push_back(size);
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == size - 1) {
                ans.push_back(curr);
            } // just change i = 0 or just ans.push_back() for left view

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return ans;
    }



    vector<Node*> topView(Node* root) {
    vector<Node*> ans;
    if (!root) return ans;

    map<int, Node*> mp; // horizontal distance -> first node
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, hd] = q.front();
        q.pop();

        // If no node is stored for this HD, store the first (topmost)
        if (mp.find(hd) == mp.end()) {
            mp[hd] = curr;
        }

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    // Traverse map in order of HD
    for (auto& p : mp) ans.push_back(p.second);
    return ans;
}



vector<Node*> bottomView(Node* root) {
    vector<Node*> ans;
    if (!root) return ans;

    map<int, Node*> mp; // horizontal distance -> latest node seen
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, hd] = q.front();
        q.pop();

        // Update with the last node at this HD (downward most)
        mp[hd] = curr;

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto& p : mp) ans.push_back(p.second);
    return ans;
}





};
class BST {
public:
    Node* root;

    BST() { root = nullptr; }

    // Insert a node into the BST
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root; // unchanged root
    }

    
    Node* insertIterative(Node* root, int val) {
    Node* newNode = new Node(val);

    if (!root) return newNode;

    Node* curr = root;
    Node* parent = nullptr;

    while (curr) {
        parent = curr;

        if (val < curr->data)
            curr = curr->left;
        else if (val > curr->data)
            curr = curr->right;
        else
            return root; // value already exists, do nothing
    }

    // attach newNode to the correct side
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}


    void insert(int val) {
        root = insert(root, val);
    }

    // Search for a node
    bool search(Node* root, int val) {
        if (!root) return false;
        if (root->data == val) return true;
        if (val < root->data) return search(root->left, val);
        return search(root->right, val);
    }

    // Find the minimum node (used in deletion)
    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    // Delete a node from the BST
    Node* deleteNode(Node* root, int val) {
        if (!root) return root;

        if (val < root->data)
            root->left = deleteNode(root->left, val);
        else if (val > root->data)
            root->right = deleteNode(root->right, val);
        else {
            // Node found
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                // Two children: replace with inorder successor (min in right subtree)
                Node* succ = findMin(root->right);
                root->data = succ->data;
                root->right = deleteNode(root->right, succ->data);
            }
        }
        return root;
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
};



int main()
{
    BinaryTree bt(10);
}