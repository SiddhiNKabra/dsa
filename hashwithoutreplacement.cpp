#include<bits/stdc++.h>
using namespace std;

class record{
    string clientname;
    int phone;

    public:
    record(){
        this -> clientname = "----";
        this -> phone = 0;
    }

    record(string name, int num){
        this -> clientname = name;
        this -> phone = num;
    }

    void print(){
        cout<<"Name: "<<clientname<<" Phone number: "<<phone<<endl;
    }

    bool isempty(){
        return this -> phone == 0;
    }

    friend class hashtable;
};

class hashtable{
    int tablesize;
    record *newrecord;
    int hash(string clientname){
        int ascii = 0;
        for(int i = 0; i < clientname.length(); i++){
            ascii = ascii + int(clientname[i]);
        }
        return ascii % tablesize;
    }
    public:
    hashtable(int i){
        this -> tablesize = i;
        this -> newrecord = new record[tablesize];
    }

    void display(){
        for(int i = 0; i < tablesize; i++){
            newrecord[i].print();
        }
    }

    void insert_without_replacement(record r){
        int index = hash(r.clientname);
        if(newrecord[index].isempty()){
            newrecord[index] = r;
        }
        else{
            int curr = index;
            while(!newrecord[curr].isempty()){
                curr = (curr + 1) % tablesize;
            }
            newrecord[curr] = r;
        }
    }

    void insertwithreplacement(record r){
        int index = hash(r.clientname);
        if(newrecord[index].isempty()){
            newrecord[index] = r;
        }
        else{
            record existing = newrecord[index];
            int actualindex = hash(existing.clientname);
            if(actualindex == index){
                int curr = index;
                while(!newrecord[curr].isempty()){
                    curr = (curr + 1) % tablesize;
                }
                newrecord[curr] = r;
            }
            else{
                newrecord[index] = r;
                int curr = index;
                while(!newrecord[curr].isempty()){
                    curr = (curr + 1) % tablesize;
                }
                newrecord[curr] = existing;
            }
        }
    }

    void search(string name){
        int index = hash(name);
        int comparisons = 0;
        if(newrecord[index].clientname == name){
            newrecord[index].print();
        }
        else{
            int curr = index;
            int passes = 0;
            while(newrecord[curr].clientname != name and passes != tablesize){
                curr = (curr + 1) % tablesize;
                passes++;
                comparisons++;
            }
            if(passes != tablesize){
                newrecord[curr].print();
            }
            else{
                cout<<"No record found"<<endl;
            }
        }
        cout<<"No. of comparisons: "<<comparisons<<endl;
    }
};

int main(){
    hashtable ht(10);
    ht.insert_without_replacement(record("abcd",78));
    ht.insert_without_replacement(record("bcda",758));
    ht.insert_without_replacement(record("dabc",56));
    ht.insert_without_replacement(record("cdab",3));
    ht.insert_without_replacement(record("cbda",23));
    ht.display();

    ht.search("cdab");
    ht.search("ggg");

    return 0;
}

