#include<bits/stdc++.h>
using namespace std;

bool goodarray(vector<int>arr)
{
    sort(arr.begin(), arr.end());
    int len = arr.size();
    int sum = 0;
    for(int i = 0; i < len- 1; i++)
    {
        sum += arr[i];
    }
    if (sum == arr[len - 1]){
        return true;
    }
    return false;
}
int main()
{
    int n; 
    cin>>n;
    vector<int> arr(n);
    int ele;
    for(int i=0; i<n; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    vector<int> temp;
    for(int i=0; i<n; i++)
    {
        
    }

    return 0;
}