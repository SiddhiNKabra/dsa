#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    void heapify(int arr[], int n, int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int l1 = i;
        if(l < n and arr[l] > arr[l1]){
            l1 = l;
        }
        if(r < n and arr[r] > arr[l1]){
            l1 = r;
        }
        if(l1 != i){
            int temp;
            temp = arr[i];
            arr[i] = arr[l1];
            arr[l1] = temp;
            heapify(arr, n, l1);
        }
    }

    void buildmaxheap(int arr[], int n){
        for(int i = n/2; i >= 0; i--){
            heapify(arr, n, i);
        }
    }

    void heapsort(int arr[], int n){
        buildmaxheap(arr, n);
        for(int i = n-1; i >=0; i--){
            int t;
            t = arr[0];
            arr[0] = arr[i];
            arr[i] = t;
            heapify(arr, i, 0);
        }
    }
    void display(int arr[], int n){
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    heap h;
    int n;
    cout<<"Enter no. of entries: ";
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter value: ";
        cin>>a[i];
    }
    h.display(a, n);
    h.heapsort(a, n);
    h.display(a, n);

    return 0;
}