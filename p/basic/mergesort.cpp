#include<bits/stdc++.h> 
using namespace std;

void merge(int arr[], int start, int mid, int end) {

    int tempArr[end - start + 1];

    int i = start, j = mid + 1, k = 0;

    while(i <= mid and j <= end) {

        if(arr[i] < arr[j]) {

            tempArr[k++] = arr[i++];
        } else {

            tempArr[k++] = arr[j++];
        }
    }

    while(i <= mid) {

        tempArr[k++] = arr[i++];
    }

    while(j <= end) {

        tempArr[k++] = arr[j++];
    }

    for(int i = start; i <= end; i++) {

        arr[i] = tempArr[i - start];
    }
}

void mergeSort(int arr[], int start, int end) {

    if(start == end) {

        return;
    }

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // merge the two sorted subarray 
    // 1st subarray [start, mid]
    // 2nd subaaray [mid + 1, end];

    merge(arr, start, mid, end);
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }

    return 0;
}

/* int main() {

    int m, n;
    cin >> m >> n;
    
    vector<int> arr1(m), arr2(n);

    for(int i = 0; i < m; i++) {

        cin >> arr1[i];
    }

    for(int i = 0; i < n; i++) {

        cin >> arr2[i];
    }

    int arr3[m + n];

    int i = 0, j = 0, k = 0;

    while(i < m and j < n) {

        if(arr1[i] < arr2[j]) {

            arr3[k++] = arr1[i++];
        } else {

            arr3[k++] = arr2[j++];
        }
    }

    while(i < m) {

        arr3[k++] = arr1[i++];
    }

    while(j < n) {

        arr3[k++] = arr2[j++];
    }

    int arr3[m + n], j = 0;

    for(int i = 0; i < m; i++) {

        arr3[j++] = arr1[i];
    }

    for(int i = 0; i < n; i++) {

        arr3[j++] = arr2[i];
    }

    sort(arr3, arr3 + m + n);

    for(int i = 0; i < m + n; i++) {

        cout << arr3[i] << " ";
    }


    return 0;
}*/
