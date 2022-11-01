#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int end, int mid) {

    vector<int> temp(arr.size());
    int i = start, j = mid + 1, k = 0;

    while(i <= mid and j <= end) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];

    while(j <= end) temp[k++] = arr[j++];

    for(int i = end; i >= start; i--) {
        arr[i] = temp[--k];
    }
}

void mergeSort(vector<int> &arr, int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end, mid);
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
