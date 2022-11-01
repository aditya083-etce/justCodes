#include <bits/stdc++.h>
using namespace std;

#define pi (3.141592653589)
#define mod 1e9+7
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

bool solve(int marks[]){
    int total = 0;

    for(int i = 0; i<3; i++){
        if (marks[i] < 10) return false;
        total += marks[i];
    }

    if (total < 100) return false;

    return true;
}
int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    while(t--){
        int marks[3];
        for(int i = 0; i<3; i++){
            cin >> marks[i];
        }
        if (solve(marks)) cout << "PASS" << endl;
        else cout << "FAIL" << endl;
    }
    return 0;
}