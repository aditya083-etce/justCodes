#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    unordered_map<long long,long long> count;
    for(int i = 0; i<n; i++)
    {
        count[arr[i]]++;
    }
    
    long long max_count = 0;
    for (auto i : count) {
        max_count = max(max_count, i.second);
    }
    cout<<max_count<<endl;
    return 0;
}