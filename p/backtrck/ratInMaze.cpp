#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<vector<bool>> v;

// path representation
void solve(int r, int c, vector<vector<int>> &m, string s) {
    int n = m.size();
    
    if(r == n - 1 and c == n - 1) {
        ans.push_back(s);
        return;
    }
    
    if(r < 0 || c < 0 || r >= n || c >= n || v[r][c] == true || m[r][c] == 0) return;
    
    v[r][c] = true;
    
    solve(r - 1, c, m, s + 'U'); // Up
    
    solve(r + 1, c, m, s + 'D'); // Down
    
    solve(r, c - 1, m, s + 'L'); // Left
    
    solve(r, c + 1, m, s + 'R'); // Right
    
    v[r][c] = false;
}
    
vector<string> findPaths(vector<vector<int>> &m, int n) {

    if(m[0][0] == 0 or m[n - 1][n - 1] == 0) return ans;
    
    v.resize(n, vector<bool> (n, false));
    
    solve(0, 0, m, "");
    
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    findPaths(arr, n);
    for(auto i: ans){
        cout << i <<" ";
    }
    return 0;
}
