#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if (n & 1){
        cout << -1 <<endl;
        return;
    }else{
        n /= 2;
        int b, c;
        b = 1;
        c = n ^ b;
        cout << b << " " << b << " " << c <<endl;
    }
}
int main(){
    int t; cin >> t;
    int n;
    while(t--){
        cin >> n;
        solve(n);
    }
    return 0;
}