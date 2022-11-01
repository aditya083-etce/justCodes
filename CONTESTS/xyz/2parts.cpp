#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int low = 0;
    int high = n-1;
    long long sumlow = 0;
    long long sumhigh = 0;
    long long ans = 0;

    while (low<=high)
    {
        if (sumlow < sumhigh){
            sumlow += arr[low];
            low++;
        }else{
            sumhigh += arr[high];
            high--;
        }

        if (sumlow == sumhigh){
            ans = max(ans,sumlow);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}