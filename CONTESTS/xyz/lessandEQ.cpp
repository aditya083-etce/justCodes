#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int k, n;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    if (k == 0)
    {
        if (arr[0] == 1){
            cout<<-1;
        }
        else{
            cout<<1;
        }
    }
    else
    {
        if (arr[k-1] == arr[k]){
            cout<<-1;
        }
        else{
            cout<<arr[k-1];
        }
    }

    return 0;
}