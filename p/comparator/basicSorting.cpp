#include <bits/stdc++.h>
using namespace std;

bool compare(int &a, int &b){
    return b < a;
}


int main() {
    
    int n;
    cin>>n;

    vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    sort(vec.begin(), vec.end(), compare);

    for(int i: vec){
        cout<<i<<" ";
    }
    return 0;
}
