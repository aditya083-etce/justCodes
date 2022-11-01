#include<bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    int n = s.size();
    if (s[0] == ')' || s[n-1] == '(') return false;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '?') cnt++;
    }

    return cnt % 2 == 0;
}

int main(){
    int t;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        if (solve(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}