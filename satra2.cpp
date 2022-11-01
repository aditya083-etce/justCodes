#include <bits/stdc++.h>
using namespace std;

int solve(string s, int n) {
    int zerocnt = 0;
    int onecnt = 0;

    for(char c: s) {
        if (c == '1') onecnt++;
        else if (c == '0') zerocnt++;
    }

    int ans = 0;

    for(char c: s) {
        if (c == '0') {
            ans += (onecnt + zerocnt - 1);
        } else if (c == '1') {
            ans += zerocnt;
        }
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
    string s; cin >> s;

    cout << solve(s, n) << endl;

    return 0;

    return 0;
}