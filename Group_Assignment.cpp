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

bool solve(vector<int> arr){
    unordered_map<int, int> count;
    for(int val: arr){
        count[val]++;
    }

    int total = 0;
    for(auto it: count){
        total += it.second;
        if (it.second % it.first){
            return false;
        }
    }
    return true;
}
int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if (solve(arr)){
            cout << "YES" <<endl;
        }else{
            cout << "NO" <<endl; 
        }   
    }
    return 0;
}