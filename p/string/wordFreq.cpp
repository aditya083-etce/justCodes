#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

void solve(string s) {
    s += ' ';
    string word = "";
    for(int i = 0; i<s.size(); i++) {
        if (s[i] == ' ' || i == s.size()) {
            mp[word]++;
            word = "";
        }else {
            word += s[i];
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    solve(s);

    for(auto it: mp) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}