#include<bits/stdc++.h>
using namespace std;

// Recursive
int solve1(int i, int j, string &s1, string &s2) {

    if(i == -1 or j == -1) {

        return 0;
    }

    if(s1[i] == s2[j]) {

        return solve1(i - 1, j - 1, s1, s2) + 1;
    }
    
    int case1 = solve1(i - 1, j, s1, s2);
    int case2 = solve1(i, j - 1, s1, s2);

    return max(case1, case2);
}

// Memorization
int solve2(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {

    if(i == -1 or j == -1) {

        return 0;
    }

    // dp[i][j] = Length of LCS in strings s1[0, i] & s2[0, j].
    if(dp[i][j] != -1) {

        return dp[i][j];
    }

    if(s1[i] == s2[j]) {

        return dp[i][j] = solve2(i - 1, j - 1, s1, s2, dp) + 1;
    }
    
    int case1 = solve2(i - 1, j, s1, s2, dp);
    int case2 = solve2(i, j - 1, s1, s2, dp);

    return dp[i][j] = max(case1, case2);
}

// Tabulation
int solve3(string &s1, string &s2) {

    int n1 = s1.size(), n2 = s2.size();

    vector<vector<int>> dp(n1, vector<int> (n2));
    // dp[i][j] = Length of LCS in strings s1[0, i] & s2[0, j].

    for(int i = 0; i < n1; i++) {

        for(int j = 0; j < n2; j++) {

            if(s1[i] == s2[j]) {

                dp[i][j] = (i > 0 and j > 0 ? dp[i - 1][j - 1] : 0) + 1;
            } else {
                
                int case1 = (i > 0 ? dp[i - 1][j] : 0);
                int case2 = (j > 0 ? dp[i][j - 1] : 0);

                dp[i][j] = max(case1, case2);
            }
        }
    }

    return dp[n1 - 1][n2 - 1];
}

// Tabulation
int solve4(string &s1, string &s2) {

    int n1 = s1.size(), n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1));
    // dp[i][j] = Length of LCS in prefixs s1 of length i & s2 of length j.

    for(int i = 0; i <= n1; i++) {

        for(int j = 0; j <= n2; j++) {

            if(i == 0 or j == 0) {

                dp[i][j] = 0;
            } else if(s1[i - 1] == s2[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[n1][n2];
}

int main() {
    
    string s1, s2;

    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();

    // Approach 1
    cout << solve1(n1 - 1, n2 - 1, s1, s2);

    // Approach 2
    vector<vector<int>> dp(n1, vector<int> (n2, -1));
    cout << solve2(n1 - 1, n2 - 1, s1, s2, dp);

    // Approach 3
    cout << solve3(s1, s2);
     
    return 0;
}