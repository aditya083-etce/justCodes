#include <bits/stdc++.h>
using namespace std;
// ------------------------------------------------------------------------
vector<bool> seive(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            int j = i * 2;
            while(j <= n) {
                isPrime[j] = false;
                j += i;
            }
        }
    }
    return isPrime;
}
// ----------------------------------------------------------------------------
// BRUTE FORCE
bool check(int n, vector<bool>& isPrime) {
    int sum = 0;
    while(n!=0) {
        sum += n % 10;
        n = n / 10;
    } 
    
    return isPrime[sum];
}
int bruteforce(int L, int R) {
    vector<bool> isPrime = seive(100001);
    int cnt = 0;
    for(int i = L; i<=R; i++) {
        if (check(i, isPrime)) cnt++;
    }
    return cnt;
}
// ----------------------------------------------------------------------------------
// DIGIT DP
int dp[1000][100][2];
int solve(int sum, int len, string num, vector<bool>& isPrime, bool tight) {
    if (len == num.size()) {
        return isPrime[sum];
    }

    if (dp[sum][len][tight] != -1) return dp[sum][len][tight];

    int ub = tight ? (num[len] - '0') : 9;
    int res = 0;
    for(int dig = 0; dig <= ub; dig++) {
        res += solve(sum + dig, len + 1, num, isPrime, (tight & (dig == ub)));
    }

    return dp[sum][len][tight] = res;

}
int cntLRprime(int L, int R) {
    vector<bool> isPrime = seive(100001);

    string Lstr = to_string(L-1);
    string Rstr = to_string(R);

    memset(dp, -1, sizeof(dp));

    int cntL = solve(0, 0, Lstr, isPrime, 1);

    memset(dp, -1, sizeof(dp));

    int cntR = solve(0, 0, Rstr, isPrime, 1);

    return (cntR - cntL);
}
// --------------------------------------------------------------------------------------


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int L, R; cin >> L >> R;

    cout << bruteforce(L, R) << endl;
    cout << cntLRprime(L, R) << endl;
    
    return 0;
}