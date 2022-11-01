#include<bits/stdc++.h>
using namespace std;


// flag = false, not buyed any stock.
// flag = true, buyed stock.

// Recursive
int solve1(int i, bool flag, vector<int> &arr) {

    if(i == arr.size()) {
        return flag ? INT_MIN : 0;
    } else if(flag) {

        return max(arr[i], solve1(i + 1, flag, arr));
    }

    // maximum profit if I will buy in future.
    int ans = solve1(i + 1, false, arr);

    // buying at ith day
    if(i < arr.size() - 1) {
        ans = max(ans, solve1(i + 1, true, arr) - arr[i]);
    }
 
    return ans;
}


// Memorization
vector<vector<int>> dp;
    
int solve2(int i, bool flag, vector<int> &arr) {

    int n = arr.size();

    if(i == n) {

        return flag ? INT_MIN : 0;
    }
    
    if(dp[i][flag] != -1) {
        
        return dp[i][flag];
    }
    
    if(flag) {

        return dp[i][flag] = max(arr[i], solve2(i + 1, flag, arr));
    }

    int ans = solve2(i + 1, false, arr);
    
    if(i < n - 1) {
        
        ans = max(ans, solve2(i + 1, true, arr) - arr[i]);
    }

    return dp[i][flag] = ans;
}

// Tabulation
int solve3(vector<int> &arr) {

    int n = arr.size();

    dp.resize(n + 1, vector<int>(2));

    dp[n][0] = 0;
    dp[n][1] = INT_MIN;

    // dp[i][0] = Max profit I can get if I buy stock today or in future.
    // dp[i][1] = Highest price of stock in range [i, n - 1]. 
    for(int i = n - 1; i >= 0; i--) {

        dp[i][1] = max(arr[i], dp[i + 1][1]); 

        dp[i][0] = dp[i + 1][0];
    
        if(i < n - 1) {
            
            dp[i][0] = max(dp[i][0], dp[i + 1][1] - arr[i]);
        }
    }

    return dp[0][0];
}

int solve3(vector<int> &arr) {

    int n = arr.size();

    dp.resize(n, vector<int>(2));

    // dp[i][0] = Max profit I can get if I sell stock today or past.
    // dp[i][1] = Minimum price of stock in range [0, i]. 

    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for(int i = 1; i < n; i++) {

        dp[i][0] = max(dp[i - 1][0], arr[i] - dp[i - 1][1]);

        dp[i][1] = min(dp[i - 1][1], arr[i]);
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {

        cin >> arr[i];
    }
     
    return 0;
}