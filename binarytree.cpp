#include <bits/stdc++.h>
using namespace std;

class node{
    int data;
    node *right, *left;

    node(){
        data = 0;
        left = right = nullptr;
    }

    node(int val){
        data = val;
        left = right = nullptr;
    }

    friend class bt;
};

class bt{
    node *root = nullptr;

    int height(node *temp){
        if(temp == nullptr){
            return 0;
        }
        int l = height(temp -> left);
        int r = height(temp -> right);

        return max(l, r) + 1;
    }

    void swap(node *temp){
        if(temp == nullptr){
            return;
        }
        if(temp -> left or temp -> right){
            node *x = temp->left;
            temp->left = temp->right;
            temp->right = x;
        }
        swap(temp->right);
        swap(temp->left);
    }

    void preorder(){
        node *curr = root;
        stack<node*> s1;
        while(!s1.empty() or curr != nullptr){
            while(curr != nullptr){
                s1.push(curr);
                cout<<curr->data<<" ";
                curr = curr->left;
            }
            curr = s1.top();
            s1.pop();
            curr = curr->right;
        }
    }

    void inorder(){
        node *curr = root;
        stack<node*> s1;
        while(!s1.empty() or curr != nullptr){
            while(curr != nullptr){
                s1.push(curr);
                curr = curr->left;
            }
            curr = s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }

    void postorder(){
        stack<node*>s1, s2;
        s1.push(root);
        while(!s1.empty()){
            node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->right){
                s1.push(temp->right);
            }
            if(temp->left){
                s1.push(temp->left);
            }
        }
        while(!s2.empty()){
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
    }


    
    public:
    queue<node *> q;
    void insert(int item){
        if(root == nullptr){
            root = new node(item);
            q.push(root);
        }

        else{
            node *newnode = new node(item);
            node *current = q.front();

            while(true){
                if(current -> left!=nullptr && current -> right!=nullptr){
                    q.push(current -> left);
                    q.push(current -> right);
                    q.pop();
                    current = q.front();
                }

                else if(current -> left == nullptr){
                    current -> left = newnode;
                    break;
                }

                else{
                    current -> right = newnode;
                    break;
                }
            }
        }
    }

    void search(int val){
        node *curr = root;
        while(curr != nullptr){
            if(val > curr->data){
                curr = curr->right;
            }
            else if(val < curr->data){
                curr = curr->left;
            }
            else{
                cout<<"\nNode found"<<endl;
                return;
            }
        }
        cout<<"\n Node not found"<<endl;
    }
    
    // void del(int key){
    //     root = deletesubtree(root, key);
    // }

    void getHeight(){
        cout<<"\nNumber of nodes in the longest path from root are(height of the tree): "<<height(root);
    }

  

    void getascending(){
        cout<<"\nValues in preorder are: ";
        preorder();
        cout<<"\nValues in inorder are: ";
        inorder();
        cout<<"\nValues in postorder are: ";
        postorder();
    }

    void printswap(){
        cout<<endl;
        swap(root);
        cout<<"Swapped tree: ";
        inorder();
    }

    void nodesCount(){
        stack <node *> s;
        s.push(this -> root);
        node *current = nullptr;
        int leafnode = 0;
        int internalnode = 0;

        while(!s.empty()){
            current = s.top();            
            s.pop();
            if(current -> left == nullptr && current -> right == nullptr){
                leafnode++;
            }
            else{
                internalnode++;
            }
            if(current -> right != nullptr){
                s.push(current -> right);
            }
            if(current -> left != nullptr){
                s.push(current -> left);
            }
        }
        cout<<"\nNo of leafnodes: "<<leafnode<<endl;
        cout<<"No of internal nodes: "<<internalnode<<endl;
    }

    bt operator=(bt &tree){
        bt b;
        queue <node *> q;
        q.push(tree.root);
        node *current = nullptr;
        while(!q.empty()){
            current = q.front();
            b.insert(current -> data);
            q.pop();

            if(current -> left != nullptr){
                q.push(current -> left);
            }
            if(current -> right != nullptr){
                q.push(current -> right);
            }
        }
        return b;
    }

    void deletenodes(){
        stack <node *> s1,s2;
        s1.push(this -> root);
        node *current = nullptr;
        while(!s1.empty()){
            current = s1.top();
            s2.push(current);
            s1.pop();
            if(current -> left != nullptr){
                s1.push(current -> left);
            }
            if(current -> right != nullptr){
                s1.push(current -> right);
            }
        }
        while(!s2.empty()){
            delete s2.top();
            s2.pop();            
        }
    }
};

int main(){
    bt tree;
    tree.insert(15);
    tree.insert(12);
    tree.insert(18);
    tree.insert(13);
    tree.insert(10);
    tree.insert(20);
    tree.insert(16);
    tree.getascending();
    tree.getHeight();
    bt b = tree;
    b.getascending();
    tree.printswap();
    tree.nodesCount();
    return 0;
}