#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n, b, ans=0;
    cin>>n>>b;
        
    vector<int> arr(n);
    
    for(int i=0; i<n; i++) cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=b)
        {
            ans++;
            b=b-arr[i];
        }else{
            break;
        }
    }
    return ans;
}
int main()
{
    int t, j=1;
    
    cin>>t;
    
    while(t--)
    {
        cout<<"Case #"<<j<<": "<<solve()<<"\n";
        j++;
    }
}