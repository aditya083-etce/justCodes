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

int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int op = 0;

        for(int i = 1; i<n; i++){
            if (s[i-1] == '1' && s[i] == '0') {
                op++;
            }
        }
        cout << op << endl;
    }
    return 0;
}