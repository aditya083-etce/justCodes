// All possible combinations of k numbers chosen from the range [1, n].

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void solve(int curr, int n, int k, vector<int> &sub){
    if (curr > n){
        if (sub.size() == k) ans.push_back(sub);
        return;
    }
    
    // include
    sub.push_back(curr);
    solve(curr + 1, n, k, sub);
    sub.pop_back();
    
    // exclude
    solve(curr + 1, n, k, sub);
}

int main() {
    int n, k; cin >> n >> k;

    vector<int> sub;
    solve(1, n, k, sub);
    
    for(auto vec: ans) {
        for(int i: vec) {
            cout << i <<" ";
        }
        cout << endl;
    }
    return 0;
}
