#include<bits/stdc++.h>
using namespace std;

// To generate all the subsequences of string s.

void printSubseqRecursive(string &s, int i, string r) {

    if(i == s.size()) {

        cout << r << endl;

        return;
    }

    printSubseqRecursive(s, i + 1, r);
    printSubseqRecursive(s, i + 1, r + s[i]);
}

void printSubseqIterative(string &s) {

    int n = s.size();

    int total = (1 << n);

    for(int i = 0; i < total; i++) {

        string r = "";

        for(int j = 0; j < n; j++) {

            if((i >> j) & 1) {

                r += s[j];
            }
        }

        cout << r << endl;
    }
}

int main() {
    
    string s;
    cin >> s;

    // printSubseqRecursive(s, 0, "");
    // printSubseqIterative(s);
    
    return 0;
}