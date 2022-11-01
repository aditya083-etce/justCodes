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

void solve(){
    int x, y, z;
    cin >> x >> y;
    z = x ^ y;

    int ans[3] = {2,2,2};

    if (x & 1) ans[0] ^= x;
    if (y & 1) ans[1] ^= y;
    if (z & 1) ans[2] ^= z;

    sort(ans, ans + 3);

    cout << ans[0] << " " << ans[1] << " " << ans[2] <<endl;
}
int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}