#include <bits/stdc++.h>
using namespace std;

int funcOR(vector<int> &arr) {
    int res = 0;
    for(int val: arr) {
        res = res | val;
    }
    return res;
}

int solve(int n, vector<int> &arr, int b) {
    sort(arr.begin(), arr.end());

    int no_of_ele = n / b;

    int ans = 0;
    
    int i = n-1;
    int cnt = 0;

    vector<int> temp;
    while(i >= 0) {
        if (cnt < no_of_ele) {
            temp.push_back(arr[i]);
            cnt++;
        } else {
            ans += funcOR(temp);
            temp.clear();
            cnt = 0;
        }
        i--;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, b; cin >> n >> b;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout << solve(n, arr, b) << endl;

    return 0;
}