// graph using adjacency list

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    string name;
    node *next;
    node *down;

    node(string n = ""){
        name = n;
        next = down = nullptr;
    }
};

class graph{
    node *head = nullptr;
    void add(string nodeA, string nodeB){
        if(head == nullptr){
            node *node1 = new node(nodeA);
            node *node2 = new node(nodeB);
            head = node1;
            node1->next = node2;
        }
        else{
            node *curr = head;
            node* prev = nullptr;
            bool found = false;
            while(curr != nullptr){
                if(curr->name == nodeA){
                    found = true;
                    node *currentlistnode = curr;
                    while(currentlistnode->next != nullptr){
                        currentlistnode = currentlistnode->next;
                    }
                    node *newnode = new node(nodeB);
                    currentlistnode->next = newnode;
                    break;
                }
                prev = curr;
                curr = curr->down;
            }
            if(!found){
                node *newnode1 = new node(nodeA);
                node *newnode2 = new node(nodeB);
                prev -> down = newnode1;
                newnode1->next = newnode2;
            }
        }
    }

    public:
    void addnode(string nodeA, string nodeB){
        add(nodeA, nodeB);
        add(nodeB, nodeA);
    }

    void print(){
        node *curr = head;
        while(curr != nullptr){
            node * currentlistnode = curr;
            while(currentlistnode != nullptr){
                cout<<currentlistnode->name<<" -> ";
                currentlistnode = currentlistnode->next;
            }
            cout<<endl;
            curr = curr->down;
        }
    }

    void printoutdegree(){
        node *curr = head;
        while(curr != nullptr){
            node *currentlistnode = curr;
            int degree = 0;
            while(currentlistnode != nullptr){
                degree++;
                currentlistnode = currentlistnode -> next;
            }
            cout<<curr->name<<" -> "<<degree<<endl;
            curr = curr->down;
        }
    }

    void printindegree(){
        node *curr = head;
        while(curr != nullptr){
            int count = 0;
            node *temp = head;
            while(temp != nullptr){
                node *neighbor = temp->next;
                while(neighbor != nullptr){
                    if(neighbor -> name == curr->name){
                        count++;
                    }
                    neighbor = neighbor->next;
                }
                temp = temp->down;
            }
            cout<<curr->name<<"\t: \t"<<count<<endl;
            curr = curr->down;
        }
    }

    void dfs (string place){
        stack<string> s1;
        vector<string> visited;
        s1.push(place);
        visited.push_back(place);
        while(true){
            if(!s1.empty()){
                place = s1.top();
                s1.pop();
                cout<<place<<" ";
            }
            else{
                cout<<endl;
                break;
            }
            node *curr = head;
            bool found = false;
            while(curr != nullptr){
                if(curr->name == place){
                    found = true;
                    node *currentlistnode = curr->next;
                    while(currentlistnode != nullptr){
                        if(find(visited.begin(), visited.end(), currentlistnode->name) == visited.end()){
                            s1.push(currentlistnode->name);
                            visited.push_back(currentlistnode->name);
                        }
                        currentlistnode = currentlistnode->next;
                    }
                    break;
                }
                curr = curr->down;;
            }
            if(!found){
                cout<<"Given node does not exist in the graph"<<endl;
                return;
            }
        }
    }

    void bfs(string place){
        queue<string> q1;
        vector<string> visited;
        q1.push(place);
        visited.push_back(place);
        while(true){
            if(!q1.empty()){
                place = q1.front();
                q1.pop();
                cout<<place<<" ";
            }
            else{
                cout<<endl;
                break;
            }
            node *curr = head;
            bool found = false;
            while(curr != nullptr){
                if(curr->name == place){
                    found = true;
                    node *currentlistnode = curr->next;
                    while(currentlistnode != nullptr){
                        if(find(visited.begin(), visited.end(), currentlistnode->name) == visited.end()){
                            visited.push_back(currentlistnode->name);
                            q1.push(currentlistnode->name);
                        }
                        currentlistnode = currentlistnode->next;
                    }
                    break;
                }
                curr = curr->down;
            }
            if(!found){
                cout<<"Given node does not exist in the graph"<<endl;
                return;
            }
        }
    }
 
};

int main() {
    graph g ; 
    g.addnode( "Katraj" , "PICT" ) ;
    g.addnode( "Bharti" , "Katraj" ) ; 
    g.addnode( "Bharti" , "PICT" ) ;
    g.addnode( "Katraj" , "SKNCOE" ) ; 
    g.addnode( "PICT" , "SKNCOE" ) ;
    g.addnode( "SKNCOE" , "Temple" ) ; 
    g.addnode( "Temple" , "Katraj" ) ; 
    g.addnode( "Temple" , "Kondhwa" ) ; 
    g.print() ; 
    g.printindegree();
    g.printoutdegree();
    g.bfs( "Katraj" ) ; 
    g.dfs( "Katraj" ) ;
    return 0;
}