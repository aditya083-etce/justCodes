#include<bits/stdc++.h>
using namespace std;

int towersOfHanoi(int n, char from, char to, char aux) {

    if(n == 0) {

        return 0;
    }

    int ans = towersOfHanoi(n - 1, from, aux, to);

    ans++;

    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;

    ans += towersOfHanoi(n - 1, aux, to, from);

    return ans;
}

int main() {

    int n;
    cin >> n;

    cout << towersOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}