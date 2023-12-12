// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     node *left, *right;
//     int data, lthread, rthread;
//     public:
//     node(int data){
//         this -> data = data;
//         this -> left = nullptr;
//         this -> right = nullptr;
//         this -> lthread = 0;
//         this -> rthread = 0;
//     }
//     friend class tbt;
// };

// class tbt{
//     node *head, *root;
//     node *inordersuccessor(node *temp){
//         node *current = temp -> right;
//         if(temp -> rthread == 1){
//             while(current->lthread != 0){
//                 current = current->left;
//             }
//         }
//         return current;
//     }

//     void deletenode(node *parent, node *child){
//         if(child -> lthread == 1 and child->rthread == 1){
//             node *smallestrst = child -> right; //smallestrst = smallest right sub tree
//             while(smallestrst -> lthread == 1){
//                 parent = smallestrst;
//                 smallestrst = smallestrst->left;
//             }
//             int temp = child -> data;
//             child -> data = smallestrst -> data;
//             smallestrst -> data = temp;
//             parent = child;
//             child = smallestrst;
//             if(child -> lthread == 1){
//                 child -> left -> right = parent;
//                 parent -> left = child -> left;
//             }
//             else if(child -> rthread == 1){
//                 parent -> right = child -> right;
//             }
//             delete smallestrst;
//         }
//         else if(child -> lthread == 0 and child -> rthread == 0){
//             if(parent -> left == child){
//                 parent -> left = child -> left;
//                 parent -> lthread = child -> lthread;
//             }
//             else if(parent -> right == child){
//                 parent -> right = child -> right;
//                 parent -> rthread = child -> rthread;
//             }
//             delete child;
//         }
//         else{
//             if(child -> lthread == 1 and child -> rthread == 0){
//                 parent -> left = child -> left;
//                 child -> left -> right = parent;
//             }
//             else if(child -> rthread == 1 and child -> lthread == 0){
//                 parent -> right = child -> right;
//                 child -> right -> left = parent;
//             }
//             delete child;
//         }
//     }

//     public:
//     tbt(){
//         this -> head = new node(0);
//         this -> head -> rthread = 0;
//         this -> head -> lthread =0;
//         this-> head -> left = this -> head;
//         this -> head -> right = this -> head;
//         this -> root = nullptr;
//     }

//     void insert(int data){
//         if(this -> root == nullptr){
//             this -> root = new node(data);
//             this -> root -> lthread = 0;
//             this -> root -> rthread = 0;
//             this -> root -> left  = this -> head;
//             this -> root -> right = this -> head;
//             this -> head -> lthread = 1;
//             this -> head -> left = this -> root;
//         }
//         else{
//             node *current = this -> root;
//             node *previous = nullptr;
//             while(true){
//                 previous = current;
//                 if(data < current -> data){
//                     if(current -> lthread == 1){
//                         current = current -> left;
//                     }
//                     else{
//                         break;
//                     }
//                 }
            
//                 else{
//                     if(current -> rthread == 1){
//                         current = current -> right;
//                     }
//                     else{
//                         break;
//                     }
//                 }
//             }
//             node *newnode = new node(data);
//             if(data < previous -> data){
//                 newnode -> lthread = previous -> lthread;
//                 newnode -> left = previous -> left;
//                 newnode -> rthread = 0;
//                 newnode -> right = previous;
//                 previous -> lthread = 1;
//                 previous -> left = newnode;
//             }
//             else{
//                 newnode -> rthread = previous -> rthread;
//                 newnode -> right = previous -> right;
//                 newnode -> lthread = 0;
//                 newnode -> left = previous;
//                 previous -> rthread = 1;
//                 previous -> right = newnode;
//             }
//         }
//     }

//     void inorder(){
//         cout<<"Inorder Traversal: ";
//         node *curr = this -> head;
//         while(true){
//             curr = inordersuccessor(curr);
//             if(curr == this -> head){
//                 cout<<endl;
//                 return;
//             }
//             cout<<curr -> data<<" ";
//         }
//     }

//     void preorder(){
//         cout<<"Preorder traversal: ";
//         int flag = 1;
//         node *curr = this -> root;
//         while(curr != this -> head){
//             while(flag == 1){
//                 cout<<curr -> data<<" ";
//                 if(curr -> lthread == 1){
//                     curr = curr->left;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             flag = curr -> rthread;
//             curr = curr -> right;
//         }
//         cout<<endl;
//     }

//     void deletion(int val){
//         node *curr = this -> root;
//         node * previous = this -> head;
//         while(curr -> data != val){
//             previous = curr;
//             if(val > curr -> data){
//                 if(curr -> rthread == 1){
//                     curr = curr -> right;
//                 }
//                 else{
//                     break;
//                 }
//             }
//             else{
//                 if(curr -> lthread == 1){
//                     curr = curr -> left;
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         deletenode(previous, curr);
//     }
// };

// int main(){
//     tbt t;
//     t.insert(50);
//     t.insert(60);
// 	t.insert(30);
// 	t.insert(10);
// 	t.insert(20);
// 	t.insert(40);
// 	t.insert(80);
// 	t.insert(75);
//     t.inorder();
//     t.preorder();

//     t.deletion(50);
//     t.preorder();

//     return 0;
// }

#include <iostream>
using namespace std;

class Node{
    Node *left, *right;
    int data, lthread, rthread;   
    //thread -> 0  means thread present, 1 means child present

public:
    Node(int data){
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
        this -> lthread = 0;
        this -> rthread = 0;
    }

    friend class TBST;
};

class TBST{
    Node *head, *root;

    Node *inOrderSuccessor(Node *node){
        Node *current = node -> right;
        if(node -> rthread == 1){
            while(current -> lthread != 0){
                current = current -> left;
            }
        }
        return current;
    }

    void deleteNode(Node *parent,Node *child){
        if(child -> lthread == 1 && child -> rthread == 1){
            Node *smallestRST = child -> right; //smallest in right subtree
            while(smallestRST -> lthread == 1){
                parent = smallestRST;
                smallestRST = smallestRST -> left;
            }
            int temp = child -> data;
            child -> data = smallestRST -> data;
            smallestRST -> data = temp;

            parent = child;
            child = smallestRST;

            if(child -> lthread == 1){
                child -> left -> right = parent;
                parent -> left = child -> left;
            } 
            else if(child -> rthread == 1){
                parent -> right = child -> right;
            }
            
            delete smallestRST;
        }

        else if(child -> lthread == 0 && child -> rthread == 0){
            if( parent -> left == child ) {
				parent -> left = child -> left ;
				parent -> lthread = child -> lthread ;
			}
			else if( parent -> right == child ) {
				parent -> right = child -> right ;
				parent -> rthread = child -> rthread ;
			}
			delete child ;
        }

        else{
            if( child -> lthread == 1 && child -> rthread == 0 ) {
				parent -> left = child -> left ;
				child -> left -> right = parent ;
			}
			else if( child -> lthread == 0 && child -> rthread == 1 ) {
				parent -> right = child -> right ;
				child -> right -> left = parent ;
			}
			delete child ;
        }
    }

public:
    TBST(){
        this -> head = new Node(0);
        this -> head -> lthread = 0;
        this -> head -> rthread = 1;
        this -> head -> left = this -> head;
        this -> head -> right = this -> head;

        this -> root = nullptr;
    }

    void insert(int data){
        if(this -> root == nullptr){
            this -> root = new Node(data);
            this -> root -> lthread = 0;
            this -> root -> left = this -> head;
            this -> root -> rthread = 0;
            this -> root -> right = this -> head;

            this -> head -> lthread = 1;
            this -> head -> left = this -> root;
        }

        else{
            Node *current = this -> root;
            Node *previous = nullptr;

            while(true){
                previous = current;
                if(data < current -> data){
                    if(current -> lthread == 1){
                        current = current -> left;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(current -> rthread == 1){
                        current = current -> right;
                    }
                    else{
                        break;
                    }
                }
            }

            Node *newNode = new Node(data);
            if(data < previous -> data){
                newNode -> lthread = previous -> lthread;
                newNode -> left = previous -> left;
                newNode -> rthread = 0;
                newNode -> right = previous;
                previous -> lthread = 1;
                previous -> left = newNode;
            }
            else{
                newNode -> rthread = previous -> rthread;
                newNode -> right = previous -> right;
                newNode -> lthread = 0;
                newNode -> left = previous;
                previous -> rthread = 1;
                previous -> right = newNode;
            }
        }
    }

    void inOrder(){
        Node *current = this -> head;
        while(true){
            current = inOrderSuccessor(current);
            if(current == this -> head){
                cout<<endl;
                return;
            }
            cout<<current -> data<<" ";
        }
    }

    void preOrder(){
        int flag = 1;
        Node *current = this -> root;

        while(current != this -> head){
            while(flag == 1){
                cout<<current -> data<<" ";
                if(current -> lthread == 1){
                    current = current -> left;
                }
                else{
                    break;
                }
            }
            flag = current -> rthread;
            current = current -> right;
        }
        cout<<endl;
    }

    void deletion( int val ) {
		Node* current = this -> root; ;
		Node* previous = this -> head ;

		while( current -> data != val ) {
			previous = current ;
			if( val > current -> data ) {
				if( current -> rthread == 1 ) {
					current = current -> right ;
				}
				else { break; }
			}
			else {
				if( current -> lthread == 1 ) {
					current = current -> left ;
				}
				else {
					break;
				}
			}
		}
		deleteNode( previous , current ) ;
	}    
};

int main(){
    TBST t;
    t.insert(50);
    t.insert(60);
	t.insert(30);
	t.insert(10);
	t.insert(20);
	t.insert(40);
	t.insert(80);
	t.insert(75);
    t.inOrder();
    t.preOrder();

    t.deletion(50);
    t.inOrder();

    return 0;
}