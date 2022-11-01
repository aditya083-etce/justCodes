#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {

    for(int i = 1; i<n; i++) {
        for(int j = 0; j<n-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(vector<int> &arr, int n) {

    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j>=0){
            if (arr[j] > temp){
                arr[j+1] = arr[j];
            } else break;
            j--;
        }
        arr[j+1] = temp;
    }
}


void selectionSort(vector<int> &arr, int n) {

    for(int i = 0; i<n-1; i++) {
        int imin = i;
        for(int j = i+1; j<n; j++) {
            if (arr[j] < arr[imin]) {
                imin = j;
            }
        }
        swap(arr[i], arr[imin]);
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
