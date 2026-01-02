#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

//--------------------------------------//
//         BASIC UTILITIES              //
//--------------------------------------//
struct Citizen {
    int id;
    string name;
    string address;
    Citizen(int i=0,string n="",string a=""):id(i),name(n),address(a){}
};

//--------------------------------------//
//           AVL TREE – Citizen DB      //
//--------------------------------------//
class AVLNode {
public:
    Citizen data;
    AVLNode *left, *right;
    int height;
    AVLNode(Citizen c):data(c),left(NULL),right(NULL),height(1){}
};

int height(AVLNode* n){ return n ? n->height : 0; }

int getBalance(AVLNode* n){ return n ? height(n->left)-height(n->right) : 0; }

AVLNode* rotateRight(AVLNode* y){
    if(!y || !y->left) return y; // Safety check
    AVLNode* x=y->left; 
    AVLNode* T2=x->right;
    x->right=y; 
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

AVLNode* rotateLeft(AVLNode* x){
    if(!x || !x->right) return x; // Safety check
    AVLNode* y=x->right; 
    AVLNode* T2=y->left;
    y->left=x; 
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}

AVLNode* insertAVL(AVLNode* node, Citizen key){
    if(!node) return new AVLNode(key);
    if(key.id < node->data.id) 
        node->left=insertAVL(node->left,key);
    else if(key.id > node->data.id) 
        node->right=insertAVL(node->right,key);
    else 
        return node; // duplicates not allowed

    node->height=1+max(height(node->left),height(node->right));
    int balance=getBalance(node);

    // Rotations with null checks
    if(balance>1 && key.id<node->left->data.id) 
        return rotateRight(node);
    if(balance<-1 && key.id>node->right->data.id) 
        return rotateLeft(node);
    if(balance>1 && key.id>node->left->data.id){ 
        node->left=rotateLeft(node->left); 
        return rotateRight(node);
    }
    if(balance<-1 && key.id<node->right->data.id){ 
        node->right=rotateRight(node->right); 
        return rotateLeft(node);
    }
    return node;
}

void inorder(AVLNode* root){
    if(!root) return;
    inorder(root->left);
    cout<<"ID: "<<root->data.id<<" | Name: "<<root->data.name<<" | Address: "<<root->data.address<<"\n";
    inorder(root->right);
}

//--------------------------------------//
//   LINKED LIST – Complaint System     //
//--------------------------------------//
struct Complaint {
    int cid;
    string desc;
    Complaint *next;
    Complaint(int c,string d):cid(c),desc(d),next(NULL){}
};

class ComplaintList {
    Complaint *head;
public:
    ComplaintList():head(NULL){}
    ~ComplaintList() { // Destructor to prevent memory leaks
        while(head) {
            Complaint* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void addComplaint(int id,string desc){
        Complaint* c=new Complaint(id,desc);
        if(!head){head=c;return;}
        Complaint* t=head;
        while(t->next)t=t->next;
        t->next=c;
    }
    
    void display(){
        if(!head){cout<<"No complaints.\n";return;}
        Complaint* t=head;
        while(t){cout<<"#"<<t->cid<<": "<<t->desc<<"\n";t=t->next;}
    }
};

//--------------------------------------//
//   STACK – Undo/Redo System           //
//--------------------------------------//
class Stack {
    vector<string> s;
public:
    void push(string x){ s.push_back(x); }
    void pop(){ if(!s.empty()) s.pop_back(); }
    string top(){ return s.empty()?"(empty)":s.back(); }
    bool empty(){ return s.empty(); }
    void display(){ 
        cout<<"Undo Stack: ";
        for(auto i:s) cout<<i<<" "; 
        cout<<"\n"; 
    }
};

//--------------------------------------//
//   QUEUE – Service Request Queue      //
//--------------------------------------//
class Queue {
    queue<string> q;
public:
    void enqueue(string s){ q.push(s); }
    void dequeue(){ 
        if(!q.empty()) q.pop(); 
        else cout<<"Queue is empty!\n";
    }
    void display(){
        if(q.empty()) {
            cout<<"Service queue is empty.\n";
            return;
        }
        queue<string> t=q;
        cout<<"Service Queue: ";
        while(!t.empty()){ cout<<t.front()<<" "; t.pop();}
        cout<<"\n";
    }
};

//--------------------------------------//
//   HASH TABLE – Property Records      //
//--------------------------------------//
class HashTable {
    static const int SIZE=10;
    vector<pair<int,string>> table[SIZE];
    int hashFunc(int key){ return key%SIZE; }
public:
    void insert(int id,string owner){
        int idx=hashFunc(id);
        table[idx].push_back({id,owner});
    }
    string search(int id){
        int idx=hashFunc(id);
        for(auto &p:table[idx]) 
            if(p.first==id) 
                return p.second;
        return "Not found";
    }
    void display(){
        bool isEmpty = true;
        for(int i=0;i<SIZE;i++){
            if(!table[i].empty()){
                isEmpty = false;
                cout<<"Bucket "<<i<<": ";
                for(auto &p:table[i]) 
                    cout<<"("<<p.first<<","<<p.second<<") ";
                cout<<"\n";
            }
        }
        if(isEmpty) cout<<"No properties found.\n";
    }
};

//--------------------------------------//
//   HEAP – Traffic Congestion System   //
//--------------------------------------//
struct Road {
    string name; 
    int congestion;
    Road(string n="", int c=0):name(n),congestion(c){}
    bool operator<(const Road& r) const {
        return congestion < r.congestion; // Max heap based on congestion
    }
};

class TrafficHeap {
    vector<Road> heap;
    
    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }
    
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        
        if (left < heap.size() && heap[largest] < heap[left])
            largest = left;
        if (right < heap.size() && heap[largest] < heap[right])
            largest = right;
            
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    void addRoad(string name, int level){ 
        heap.push_back(Road(name, level));
        heapifyUp(heap.size() - 1);
    }
    
    void topCongested(){
        if(heap.empty()) 
            cout<<"No roads.\n";
        else 
            cout<<"Most Congested: "<<heap[0].name<<" ("<<heap[0].congestion<<")\n";
    }
    
    void display(){
        if(heap.empty()) {
            cout<<"No traffic data available.\n";
            return;
        }
        cout<<"All Roads (by congestion level):\n";
        // Create a copy for display without modifying the original
        vector<Road> temp = heap;
        sort(temp.begin(), temp.end(), [](const Road& a, const Road& b) {
            return b < a; // Sort in descending order
        });
        for(auto& road : temp){
            cout<<road.name<<" ("<<road.congestion<<")\n";
        }
    }
};

//--------------------------------------//
//   GRAPH – Road Network (Dijkstra)    //
//--------------------------------------//
class Graph {
    int V;
    vector<pair<int,int>> *adj;
public:
    Graph(int v){ 
        V=v; 
        adj=new vector<pair<int,int>>[v]; 
    }
    
    ~Graph() {
        delete[] adj;
    }
    
    void addEdge(int u,int v,int w){
        if(u >= V || v >= V) {
            cout<<"Error: Invalid node index!\n";
            return;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    void shortestPath(int src){
        if(src >= V) {
            cout<<"Error: Source node doesn't exist!\n";
            return;
        }
        
        vector<int> dist(V,INT_MAX);
        vector<bool> visited(V,false);
        dist[src]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            int u=pq.top().second; 
            pq.pop();
            
            if(visited[u]) continue;
            visited[u] = true;
            
            for(auto &i:adj[u]){
                int v=i.first, w=i.second;
                if(!visited[v] && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        
        cout<<"Shortest distances from node "<<src<<":\n";
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX)
                cout<<"To "<<i<<" = Unreachable\n";
            else
                cout<<"To "<<i<<" = "<<dist[i]<<"\n";
        }
    }
};

//--------------------------------------//
//   MAIN SIMULATOR CLASS               //
//--------------------------------------//
class City {
    AVLNode* citizenRoot;
    ComplaintList complaints;
    Stack undoStack;
    Queue serviceQueue;
    HashTable properties;
    TrafficHeap traffic;
    Graph* roads;
    
public:
    City(){ 
        citizenRoot=NULL; 
        roads=new Graph(6); // Fixed: 6 nodes in graph
    }
    
    ~City() {
        // TODO: Add AVL tree cleanup
        delete roads;
    }
    
    void addCitizen(){
        int id; string name,addr;
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Address: ";
        getline(cin, addr);
        
        citizenRoot=insertAVL(citizenRoot,Citizen(id,name,addr));
        undoStack.push("Added citizen "+to_string(id));
        cout<<"Citizen added successfully!\n";
    }
    
    void showCitizens(){ 
        if(!citizenRoot) {
            cout<<"No citizens in database.\n";
            return;
        }
        cout<<"Citizens Database:\n";
        inorder(citizenRoot); 
    }
    
    void addComplaint(){
        int id; string d; 
        cout<<"Enter complaint id: ";
        cin>>id; 
        cout<<"Enter complaint description: ";
        cin.ignore();
        getline(cin,d);
        complaints.addComplaint(id,d);
        undoStack.push("Added complaint "+to_string(id));
        cout<<"Complaint added successfully!\n";
    }
    
    void showComplaints(){ complaints.display(); }
    
    void addProperty(){
        int id; string owner; 
        cout<<"Enter property id: ";
        cin>>id;
        cout<<"Enter owner name: ";
        cin>>owner;
        properties.insert(id,owner);
        undoStack.push("Added property "+to_string(id));
        cout<<"Property added successfully!\n";
    }
    
    void showProperties(){ properties.display(); }
    
    void addTraffic(){
        string name; int c; 
        cout<<"Enter road name: ";
        cin>>name;
        cout<<"Enter congestion level: ";
        cin>>c;
        traffic.addRoad(name,c);
        undoStack.push("Added road "+name);
        cout<<"Traffic data added successfully!\n";
    }
    
    void showTraffic(){ traffic.display(); }
    
    void showTopRoad(){ traffic.topCongested(); }
    
    void addRoadConnection(){
        int u,v,w; 
        cout<<"Enter first junction (0-5): ";
        cin>>u;
        cout<<"Enter second junction (0-5): ";
        cin>>v;
        cout<<"Enter distance: ";
        cin>>w;
        roads->addEdge(u,v,w);
        undoStack.push("Added road connection");
        cout<<"Road connection added successfully!\n";
    }
    
    void findRoute(){
        int s; 
        cout<<"Enter source junction (0-5): "; 
        cin>>s;
        roads->shortestPath(s);
    }
    
    void addService(){
        string s; 
        cout<<"Enter service request: "; 
        cin.ignore();
        getline(cin, s);
        serviceQueue.enqueue(s);
        undoStack.push("Added service: "+s);
        cout<<"Service request added to queue!\n";
    }
    
    void processService(){
        serviceQueue.dequeue(); 
        undoStack.push("Processed service request");
    }
    
    void showQueue(){ serviceQueue.display(); }
    
    void undo(){
        if(!undoStack.empty()){
            cout<<"Undoing: "<<undoStack.top()<<"\n";
            undoStack.pop();
        }else cout<<"Nothing to undo.\n";
    }
    
    void showUndoStack() { undoStack.display(); }
};

//--------------------------------------//
//                MAIN MENU             //
//--------------------------------------//
int main(){
    City city;
    int ch;
    
    cout<<"\n------ EvoCity: Smart City Simulation ------\n";
    
    do{
        cout<<"\nMain Menu:\n";
        cout<<"1. Citizen Management\n";
        cout<<"2. Complaint System\n"; 
        cout<<"3. Property Records\n";
        cout<<"4. Traffic Management\n";
        cout<<"5. Road Network\n";
        cout<<"6. Service Queue\n";
        cout<<"7. Undo Operations\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        
        switch(ch){
            case 1: {
                int citizenChoice;
                do {
                    cout<<"\n--- Citizen Management ---\n";
                    cout<<"1. Add Citizen\n";
                    cout<<"2. View All Citizens\n";
                    cout<<"0. Back to Main Menu\n";
                    cout<<"Choice: ";
                    cin>>citizenChoice;
                    switch(citizenChoice) {
                        case 1: city.addCitizen(); break;
                        case 2: city.showCitizens(); break;
                        case 0: break;
                        default: cout<<"Invalid option!\n";
                    }
                } while(citizenChoice != 0);
                break;
            }
            case 2: {
                int complaintChoice;
                do {
                    cout<<"\n--- Complaint System ---\n";
                    cout<<"1. Add Complaint\n";
                    cout<<"2. View All Complaints\n";
                    cout<<"0. Back to Main Menu\n";
                    cout<<"Choice: ";
                    cin>>complaintChoice;
                    switch(complaintChoice) {
                        case 1: city.addComplaint(); break;
                        case 2: city.showComplaints(); break;
                        case 0: break;
                        default: cout<<"Invalid option!\n";
                    }
                } while(complaintChoice != 0);
                break;
            }
            case 3: {
                int propertyChoice;
                do {
                    cout<<"\n--- Property Records ---\n";
                    cout<<"1. Add Property\n";
                    cout<<"2. View All Properties\n";
                    cout<<"0. Back to Main Menu\n";
                    cout<<"Choice: ";
                    cin>>propertyChoice;
                    switch(propertyChoice) {
                        case 1: city.addProperty(); break;
                        case 2: city.showProperties(); break;
                        case 0: break;
                        default: cout<<"Invalid option!\n";
                    }
                } while(propertyChoice != 0);
                break;
            }
            case 4: {
                int trafficChoice;
                do {
                    cout<<"\n--- Traffic Management ---\n";
                    cout<<"1. Add Traffic Data\n";
                    cout<<"2. View All Roads\n";
                    cout<<"3. View Most Congested Road\n";
                    cout<<"0. Back to Main Menu\n";
                    cout<<"Choice: ";
                    cin>>trafficChoice;
                    switch(trafficChoice) {
                        case 1: city.addTraffic(); break;
                        case 2: city.showTraffic(); break;
                        case 3: city.showTopRoad(); break;
                        case 0: break;
                        default: cout<<"Invalid option!\n";
                    }
                } while(trafficChoice != 0);
                break;
            }
            case 5: {
                int roadChoice;
                do {
                    cout<<"\n--- Road Network ---\n";
                    cout<<"1. Add Road Connection\n";
                    cout<<"2. Find Shortest Route\n";
                    cout<<"0. Back to Main Menu\n";
                    cout<<"Choice: ";
                    cin>>roadChoice;
                    switch(roadChoice) {
                        case 1: city.addRoadConnection(); break;
                        case 2: city.findRoute(); break;
                        case 0: break;
                        default: cout<<"Invalid option!\n";
                    }
                } while(roadChoice != 0);
                break;
            }
            case 6: {
                int serviceChoice;
                do {
                    cout<<"\n--- Service Queue ---\n";
                    cout<<"1. Add Service Request\n";
                    cout<<"2. Process Service Request\n";
                    cout<<"3. View Service Queue\n";
                    cout<<"0. Back to Main Menu\n";
                    cout<<"Choice: ";
                    cin>>serviceChoice;
                    switch(serviceChoice) {
                        case 1: city.addService(); break;
                        case 2: city.processService(); break;
                        case 3: city.showQueue(); break;
                        case 0: break;
                        default: cout<<"Invalid option!\n";
                    }
                } while(serviceChoice != 0);
                break;
            }
            case 7: {
                city.undo();
                break;
            }
            case 0: 
                cout<<"Exiting EvoCity Simulation...\n"; 
                break;
            default: 
                cout<<"Invalid option! Please try again.\n";
        }
    }while(ch!=0);
    
    return 0;
}