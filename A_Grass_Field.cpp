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

int solve(int arr[][]){
    int cnt = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            if (arr[i][j] == 1){


            }
        }
    }
}
int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    while(t--){
        int arr[2][2];
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                cin >> arr[i][j];
            }
        }

        cout << solve(arr) << endl;
    }
    return 0;
}