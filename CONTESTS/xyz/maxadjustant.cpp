// Lily's homework hackrank
#include<bits/stdc++.h> 
using namespace std;

int homework(int arr[],int sarr[], int n)
{
    unordered_map<int, int> map;
    for(int i=0; i<n; i++){
        map[arr[i]] = i;
    }
    int i = 0;
    int swapcnt = 0;

    while(i<n)
    {
        if (arr[i] != sarr[i])
        {
            int val1 = arr[i], index1 = map[arr[i]];
            int val2 = sarr[i], index2 = map[sarr[i]];

            swap(arr[index1], arr[index2]);
            swap(map[val1],map[val2]);
            
            swapcnt++;
        } 
        i++;
    }
    return swapcnt;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n; i++)
    {
        cin>>arr[i];
    }

    int sarr[n];
    for(int i = 0; i<n; i++){
        sarr[i] = arr[i];
    }

    sort(sarr, sarr + n);

    int asdcnt = homework(arr,sarr,n);
    
    reverse(sarr, sarr + n);
    int descnt = homework(arr,sarr,n);
    cout<<min(asdcnt,descnt)<<endl;
    
    return 0;
}