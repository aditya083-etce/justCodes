#include<bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin >> n;

    vector<int>arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(auto it = arr.begin(); it != arr.end(); it++)
    {
        if(*it % 2 != 0){
            arr.erase(it);
            it--;
        }
    }

    for(int i: arr) cout<<i<<" ";

    return 0;
}
