#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n) {

    vector<int> div[n + 1];

    for(int i = 1; i <= n; i++) {

        int j = i;

        while(j <= n) {

            div[j].push_back(i);

            j += i;
        }
    }

    for(int i = 1; i <= n; i++) {

        cout << i << " " << div[i].size() << " ";

        for(int j : div[i]) {

            cout << j << " ";
        }

        cout << endl;
    }
}

int main() {

    int n;
    cin >> n;

    printDivisors(n);

    return 0;
}