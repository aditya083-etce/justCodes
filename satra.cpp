#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());

    int ans = INT_MIN;
    for(int i = n-1; i>=0; i--) {
        int currPower = arr[i] * (n-i);
        ans = max(ans, currPower);
    }

    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, n) << endl;

    return 0;
}
