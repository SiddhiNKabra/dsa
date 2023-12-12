#include<bits/stdc++.h>
using namespace std;
const int max = INT_MAX;

class graph{
    
    int **adjMatrix;
    int vertex;
    int edge;
    map<string, int> cities;
    map<int, string> inv_cities;

    void add(string c1, string c2, int d){
        adjMatrix[cities[c1]][cities[c2]] = d;
        adjMatrix[cities[c2]][cities[c1]] = d;
    }

    int minimum_key(int key[], bool mst[]){
        int minimum = INT_MAX;
        int min, i;
        for(i = 0; i < vertex; i++){
            if(mst[i] == 0 and key[i] < minimum){
                minimum = key[i];
                min = i;
            }
        }
        return min;
    }

    public:

    graph(){
        cout<<"Enter no. of vertex: ";
        cin>>vertex;
        cout<<"Enter no. of edges: ";
        cin>>edge;
        adjMatrix = new int*[vertex];
        for(int i = 0; i < vertex; i++){
            adjMatrix[i] = new int[vertex];
            for(int j = 0; j < vertex; j++){
                adjMatrix[i][j] = 0;
            }
        }
        cout<<"Add cities in order: "<<endl;
        for(int i = 0; i < vertex; i++){
            string city;
            cin>>city;
            cities.insert(pair<string, int>(city, i));
            inv_cities.insert(pair<int, string>(i, city));
        }
        cout<<"Add the "<<edge<<" edges: "<<endl;
        for(int i = 0; i < edge; i++){
            string u, v;
            int d;
            cout<<"City 1: ";
            cin>>u;
            cout<<"City 2: ";
            cin>>v;
            cout<<"Distance: ";
            cin>>d;
            add(u, v, d);
        }
    }

    void prims(graph g){
        int n = g.vertex;
        int parent[n];
        int key[n];
        bool mst[n];
        for(int i = 0; i < n; i++){
            key[i] = INT_MAX;
            mst[i] = 0;
        }
        key[0] = 0;
        parent[0] = -1;
        for(int count = 0; count < n-1; count++){
            int min_edge_vertex = minimum_key(key, mst);
            mst[min_edge_vertex] = 1;
            for(int v = 0; v < n; v++){
                if(g.adjMatrix[min_edge_vertex][v] and mst[v] == 0 and g.adjMatrix[min_edge_vertex][v] < key[v]){
                    parent[v] = min_edge_vertex;
                    key[v] = g.adjMatrix[min_edge_vertex][v];
                }
            }
        }
        cout<<"MST of given graph: \n"<<endl;
        cout<<"\n Edge \t Weight\n";
        for(int i = 1; i<n; i++){
            cout<<inv_cities[parent[i]]<<"  <->  "<<inv_cities[i]<<"  \t  "<<g.adjMatrix[i][parent[i]]<<endl;
        }
    }
};

int main(){

    graph g;
    g.prims(g);

    return 0;
}