#include<bits/stdc++.h>
using namespace std;

class node{
    int key;
    node *left = nullptr, *right = nullptr;
    public:
    friend class obst;
};

class obst{
    int r[100][100];
    int c[100][100];
    node *root = nullptr;
    int sumoffrequency(int *arr, int low, int high){
        int sum = 0;
        for(int i = low; i < high; i++){
            sum = sum + arr[i];
        }
        return sum;
    }

    void findoptsubtree(int *freq, int num, int n){
        for(int j = 0; j < n - num; j++){
            int i = num + j;
            int mincost = 9999;
            int minroot = r[j][i-1];
            for(int k = j+1; k <= i; k++){
                int cost = c[j][k-1] + c[k][j];
                if(cost < mincost){
                    mincost = cost;
                    minroot = k;
                }
            }
            c[j][i] = mincost + sumoffrequency(freq, j, i);
            r[j][i] = minroot;
        }
    }

    node *constructobst(int i, int j, int *values){
        if(i == j){
            return nullptr;
        }
        else{
            node *temp = new node();
            temp -> key = values[r[i][j] - 1];
            temp -> left = constructobst(i, r[i][j] - 1, values);
            temp -> right = constructobst(r[i][j], j, values);
            return temp;
        }
    }

    void inorder(node *temp){
        if(temp == nullptr){
            return;
        }
        else{
            inorder(temp -> left);
            cout<<temp->key<<" ";
            inorder(temp->right);
        }
    }
    public:
    void display(){
        inorder(this -> root);cout<<endl;
    }

    void findobst(int *val, int *freq, int total){
        int n = total + 1;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j++){
                c[i][j] = 0;
                r[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            int j = i + 1;
            c[i][j] = freq[i];
            r[i][j] = j;
        }
        for(int i = 2; i < n; i++){
            findoptsubtree(freq, i, n);
        }
        cout<<"Cost of OBST is: "<<c[0][n-1]<<endl;
        this -> root = new node();
        this -> root = constructobst(0, n-1, val);
    }
};

int main(){
    obst t;
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    int val[n];
    int freq[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter value and frequency: ";
        cin>>val[i]>>freq[i];
    }
    cout<<endl;
    t.findobst(val, freq, n);
    t.display();
    return 0;
}