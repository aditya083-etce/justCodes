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

void solve()
{
    int n; cin >> n;
    vector<int> s(n);
    for(int i = 0; i<n; i++){
        cin >> s[i];
    }

    int m; cin >> m;
    vector<int> key(m);
    for(int i = 0; i<m; i++){
        cin >> key[i];
    }

    unordered_map<int, vector<int>> my_map;

    for(int i = 0; i<m; i++){
        my_map[key[i]].push_back(i);
    }

    int time = 0;
    for(int i = 1; i<n; i++){
        time += abs(my_map[s[i]][0] - my_map[s[i-1]][0]);
    }

    cout << time << endl;
}
int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    int c = 1;
    while(t--){
        cout<<"Case #"<<c<<": ";
        solve();
        c++;
    }
    return 0;
}