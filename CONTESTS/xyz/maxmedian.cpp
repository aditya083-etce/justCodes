#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    vector <int> arr(n);
    int ele;
    for (int i = 0; i < n; i++){
        cin>>ele;
        arr.push_back(ele);

    }

    sort(arr.begin(), arr.end());
    int mid = n / 2;
    while (k--)
    {
        arr[mid]++;

        sort(arr.begin() + mid, arr.end());
    }

    cout<<arr[mid]<<endl;
    return 0;
}

// int main()
// {
//     int n, k;
//     cin>>n>>k;
//     int arr[n];
//     for (int i = 0; i < n; i++){
//         cin>>arr[i];
//     }
    
//     int mid = n / 2;

//     while (k--)
//     {
//         sort(arr, arr+n);
//         arr[mid]++;
//     }

//     cout<<arr[mid]<<endl;
//     return 0;
// }