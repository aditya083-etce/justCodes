#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int &x, int n) {

    int carry = 0;

    for(int i = 0; i <= x; i++) {

        int curr = (arr[i] * n) + carry;

        arr[i] = curr % 100000;

        carry = curr / 100000;
    }

    if(carry > 0) {

        arr[++x] = carry;
    }
}

int main() {

    int n;
    cin >> n;
    
    vector<int> arr(250);

    int x = 0;

    arr[0] = 1;

    for(int i = 1; i <= n; i++) {

        solve(arr, x, i);
    }

    for(int i = x; i >= 0; i--) {

        if(arr[i] == 0) {

            cout << "00000";
        } else {

            cout << arr[i];
        }
    }

    return 0;
}
