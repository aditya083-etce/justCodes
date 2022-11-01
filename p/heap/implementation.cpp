// max heap
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int curr, int size){
    int L = 2*curr + 1;
    int R = 2*curr + 2;

    int largest = curr;

    if (L < size and arr[L] > arr[curr]){
        largest = L;
    }

    if (R < size and arr[R] > arr[largest]) {
        largest = R;
    }

    if (largest != curr){
        swap(arr[curr], arr[largest]);
        heapify(arr, largest, size);
    }
}

void buildHeap(vector<int> &arr){
    int size = arr.size();
    for(int i = (size/ 2) - 1; i >= 0; i--){
        heapify(arr, i, size);
    }
}

void heapSort(vector<int> &arr) {
    for(int i = arr.size() - 1; i >= 1; i--){
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}

void heapush(vector<int> &arr, int key) {
    if (arr.size() == INT_MAX){
        cout << "Heap overflow" << endl;
        return;
    }

    arr.push_back(key);
    int curr = arr.size() - 1;

    // Percolate up
    while(curr > 0 and arr[(curr - 1)/2] > arr[curr]){
        swap(arr[(curr - 1)/2], arr[curr]);
        curr = (curr - 1) / 2;
    }
}

int heapop(vector<int> &arr){
    int size = arr.size();

    if (size == 0){
        cout << "Heap underflow" << endl;
        return -1;
    }

    int mx = arr[0];
    arr[0] = arr[size - 1];
    arr.pop_back();
    size = size - 1;
    heapify(arr, 0, size);

    return mx;
}

void increaseKey(vector<int> &arr, int pos, int key){
    if (key < arr[pos]){
        cout << "Wrong operation" <<endl;
        return;
    }

    arr[pos] = key;
    // Percolate up
    while(pos > 0 and arr[(pos - 1)/2] > arr[pos]){
        swap(arr[(pos - 1)/2], arr[pos]);
        pos = (pos - 1) / 2;
    }
}

void decreaseKey(vector<int> &arr, int pos, int key){
    if (key > arr[pos]){
        cout << "Wrong operation" <<endl;
        return;
    }

    arr[pos] = key;
    heapify(arr, pos, arr.size());
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    buildHeap(arr);

    decreaseKey(arr, 1, 0); 
    // increaseKey(arr, 4, 50);

    
    // heapush(arr, 12);

    // cout << "Poped element: " << heapop(arr) << endl;
    // heapSort(arr);

    for(int val: arr){
        cout << val << " ";
    }

    return 0;
}