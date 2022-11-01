#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    if (arr[0] > k) return k;
    
    int lo = 0;
    int hi = arr.size() - 1;
    int closemid = 0;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (arr[mid] - (mid+1) < k) {
            closemid = mid + 1;
            lo = mid + 1;
        }else {
            hi = mid - 1;
        }
    }
    return k + closemid;
}

long long getMinimumCost(vector<int> &parcels, int k) {
    k = k - parcels.size();
    k++;
    long long ans = 0;

    while(k--) {
        ans += findKthPositive(parcels, k);
    }

    return ans;
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k; cin >> k;
    cout << getMinimumCost(arr, k) << endl;

    return 0;
}