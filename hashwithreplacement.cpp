#include<bits/stdc++.h>
using namespace std;

class node{
    node *ptr;
    string word;
    string meaning;
    public:

    node(string key, string value){
        this -> word = key;
        this -> meaning = value;
        this -> ptr = nullptr;
    }

    friend class dictionary;
};

class dictionary{
    int dictionarysize;
    node **headnode;

    int hash(string word){
        int ascii = 0;
        for(int i = 0; i < word.length(); i++){
            ascii = ascii + int(word[i]);
        }
        return ascii % dictionarysize;
    }

    void insertnode(node *head, node *newentry){
        node *curr = head;
        while(curr -> ptr != nullptr){
            curr = curr -> ptr;
        }
        curr -> ptr = newentry;
    }

    void print(node *head){
        node *curr = head;
        while(curr != nullptr){
            cout.width(5);
            cout<<curr -> word<<"  -  "<<curr -> meaning<<", ";
            curr = curr -> ptr;
        }
    }

    public:
    dictionary(int size){
        this -> dictionarysize = size;
        headnode = new node*[size];
        for(int i = 0; i < size; i++){
            headnode[i] = nullptr;
        }
    }

    void insert(string key, string value){
        int index = hash(key);
        if(headnode[index] == nullptr){
            headnode[index] = new node(key, value);
        }
        else{
            node *newnode = new node(key, value);
            insertnode(headnode[index], newnode);
        }
    }

    void display(){
        for(int i = 0; i < dictionarysize; i++){
            cout.width(5);
            cout<<i<<" ";
            print(headnode[i]);
            cout<<"\0"<<endl;
        }
    }

    void search(string key){
        int index = hash(key);
        int count = 1;
        node *curr = headnode[index];
        while(curr != nullptr){
            if(curr -> word == key){
                cout<<"Word found."<<endl;
                cout<<curr -> word<<"  -  "<<curr -> meaning<<endl;
                cout<<"No. of comparisons: "<<count<<endl;
                break;
            }
            curr = curr -> ptr;
            count++;
        }
        if(curr == nullptr){
            cout<<" Word not found."<<endl;
            cout<<"No of comparisons: "<<count<<endl;
        }
    }

    void deleteword(string key){
        int index = hash(key);
        if(headnode[index] -> word == key){
            node *newhead = headnode[index] -> ptr;
            delete headnode[index];
            headnode[index] = newhead;
        }
        else{
            node *curr = headnode[index];
            node *prev = nullptr;
            while(curr != nullptr){
                if(curr -> word == key){
                    break;
                }
                prev = curr;
                curr = curr -> ptr;
            }
            prev -> ptr = curr -> ptr;
            delete curr;
        }
    }
};

int main(){
    
    dictionary d(10);
    d.insert("abc" , "godd");
    d.insert("bac" , "dsbjv");
    d.insert("gggg" , "ashv");
    cout<<"Display: "<<endl;
    d.display();
    d.deleteword("abc");
    d.search("bac");
    cout<<"Display after deletion of abc: "<<endl;
    d.display();
    d.search("cab");

    return 0;
}