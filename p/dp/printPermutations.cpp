#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void permute(int ind, int n, string s){
    if (ind == n){
        cout << s << endl;
        return;
    }

    for(int i = ind; i < n; i++) {
        swap(s[ind], s[i]);
        permute(ind+1, n, s);
        swap(s[ind], s[i]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    string s; cin >> s;

    permute(0, n, s);

    for(auto &vec: res){ 
        cout << "[ ";
        for(int val: vec){
            cout << val << " ";
        }
        cout << " ]" << endl;
    }
    return 0;
}
