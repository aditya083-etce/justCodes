// Largest subsequence having GCD greater than 1
// https://www.geeksforgeeks.org/largest-subsequence-gcd-greater-1/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mx = *max_element(arr.begin(), arr.end());
    vector<bool> prime(mx + 1, true);
    prime[0] = prime[1] = false;
    int ans = 0;

    // Sieve
    for(int i = 2; i <= mx; i++) {
        if(prime[i]) {
            int j = 2 * i;
            // int j = i * i;
            while(j <= mx) {
                prime[j] = false;
                j += i;
            }
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                // factorial count
                if(arr[j] % i == 0) { 
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}