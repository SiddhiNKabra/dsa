#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
using namespace std;

class Record{
    int id, sal,exp;
    string name;

    public:
    Record(string title, int i1, int salary, int years){
        this -> name = title;
        this -> id = i1;
        this -> sal = salary;
        this -> exp = years;
    }

    string convert(){
        string output;
        return output + to_string(id) + "-" + name +"-" + to_string(exp) + "-" + to_string(sal);
    }
    friend class File;
};

class File{
    int tablesize;
    string fname;
    int *table;
    int hash(int id){
        return id % this -> tablesize;
    }
    public:
    File(string name, int size){
        this -> fname = name;
        this -> tablesize = size;
        this -> table = new int[tablesize];
        for(int i = 0; i < tablesize; i++){
            table[i] = -1;
        }
    }

    void insert(Record r){
        ofstream output;
        output.open(this -> fname, ios::app);
        int index = hash(r.id);
        int address = output.tellp();
        table[index] = address;
        output.write(r.convert().c_str(), r.convert().length());
        output.write("\n", 1);
        output.close();
    }

    void deleterecord(int id){
        int index = hash(id);
        this -> table[index] = -1;
        ifstream input;
        input.open(this -> fname, ios::in);
        vector<string> lines;
        while(!input.eof()){
            string record;
            input>>record;
            if((int(record[0]) - 48) != id){
                lines.push_back(record);
            }
        }
        input.close();
        ofstream output;
        output.open(this -> fname, ios::out);
        for(int i = 0; i < lines.size(); i++){
            int loc = output.tellp();
            string line = lines[i];
            output.write(line.c_str(), line.length());
            output.write("\n", 1);
            int index = hash(int(line[0]) - 48);
            this -> table[index] = loc;
        }
        output.close();
    }

    void display(){
        ifstream input;
        input.open(this -> fname, ios::in);
        input.seekg(ios::beg);
        while(!input.eof()){
            string line;
            input>>line;
            cout<<line;
            cout<<endl;
        }
        input.close();
    }

    void displaytable(){
        for(int i = 0; i < this -> tablesize; i++){
            cout<<table[i]<<endl;
        }
    }
};

int main(){
    File f("data.txt",5);
	f.insert(Record("Advait",1,34,5));
	f.insert(Record("Shubham",2,12,2));
	f.insert(Record("Kaustubh",3,26,4));
	f.insert(Record("Krishna",4,10,1));
	f.displaytable();
	cout<<endl;
	f.display();
	f.deleterecord(2);
	f.displaytable();
	cout<<endl;
	f.display();

    return 0;
}