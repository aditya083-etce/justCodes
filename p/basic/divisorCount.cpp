#include<bits/stdc++.h>
using namespace std;

vector<int> findDivisorCount(int n) {

    if(n == 1) {

        return {0, 1};
    }

    vector<int> divCount(n + 1, 2);

    divCount[1] = 1;

    for(int i = 2; i <= n; i++) {

        int j = 2 * i;

        while(j <= n) {

            divCount[j]++;

            j += i;
        }
    }

    return divCount;
}

int main() {

    int n;
    cin >> n;

    vector<int> divCount = findDivisorCount(n);

    for(int i = 1; i <= n; i++) {

        cout << i << " " << divCount[i] << endl;
    } 

    return 0;
}