#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m)
{
    int arr[n][m];
    int val = 0;
    for(int i = 0; i<n; i++){
        val = 1 ^ val;
        for(int j = 0; j<m; j++){
            arr[i][j] = val;
            val = 1 ^ val;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout <<endl;
    }
}
int main(){
    int t; cin >> t;
    int n, m;
    while(t--){
        cin >> n >> m;
        solve(n,m);
    }
    return 0;
}