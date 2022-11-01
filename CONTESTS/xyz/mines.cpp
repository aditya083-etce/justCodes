#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, char arr[][]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if (arr[i][j] >='0' && arr[i][j] <= '9')
            {
                if (arr[i - 1][])
            }
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    solve(n,m,arr);
    return 0;
}