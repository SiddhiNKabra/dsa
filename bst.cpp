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

    friend class bst;
};

class bst{
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

    node* minval(node *temp){
        node *curr = temp;
        while(curr -> left != nullptr){
            curr = curr->left;
        }
        return curr;
    }

    
    public:

    void insert(int val){
        node *curr = root;
        node *prev = nullptr;
        if(curr == nullptr){
            root = new node(val);
        }

        else{
            while(curr != nullptr){
                if(val > curr -> data){
                    prev = curr;
                    curr = curr -> right;
                }
                else if(val < curr->data){
                    prev = curr;
                    curr = curr->left;
                }
                else{
                    cout<<"Node already exists"<<endl;
                    return;
                }
            }
            if(val > prev->data){
                node *temp = new node(val);
                prev -> right = temp;
            }
            else{
                node *temp = new node(val);
                prev->left = temp;
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
        cout<<"\nNumber of nodes in the longest path from root are: "<<height(root)<<endl;
    }

    void getminval(){
        cout<<"\nMinimum value in the tree is: "<<minval(root)->data<<endl;
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
        swap(root);
        cout<<"Swapped tree: ";
        inorder();
    }
};

int main(){

    bst tree;

    tree.insert(15);
    tree.insert(12);
    tree.insert(18);
    tree.insert(13);
    tree.insert(10);
    tree.insert(20);
    tree.insert(16);

    tree.getascending();
    tree.getHeight();
    tree.getminval();
    tree.printswap();
    // tree.del(18);

    return 0;
}