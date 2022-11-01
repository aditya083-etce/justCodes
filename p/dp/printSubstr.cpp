#include <bits/stdc++.h>
using namespace std;

// total number is (n (n + 1) )/ 2

vector<string> res;

void printSubStr(string &str){
    int n = str.size();

    for(int i = 0; i<n; i++) {
        string sub = "";
        for(int j = i; j<n; j++) {
            sub += str[j];
            res.push_back(sub);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string str; cin >> str;

    printSubStr(str);

    for(auto &s: res){
        cout << s << endl;
    }
    return 0;
}