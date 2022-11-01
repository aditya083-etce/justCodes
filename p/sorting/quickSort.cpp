#include <bits/stdc++.h>
using namespace std;

// --------------- to randomise pivot -->
// int randomisePartition(vector<int> &arr, int start, int end) {
//     int pivotindex = rand(start, end);
//     swap(arr[pivotindex], arr[end]);
//     partition(arr, start, end);

//     return pivotindex;
// }

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];
    int pindex = start;

    for(int i = start; i <= end - 1; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex], arr[end]);
    return pindex;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end) return;

    // int pivotindex = randomisePartition(arr, start, end);

    int pivotindex = partition(arr, start, end);
    quickSort(arr, start, pivotindex - 1);
    quickSort(arr, pivotindex + 1, end);
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
