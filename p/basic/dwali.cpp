#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    int mod = 105;
    cin>>t;

    while(t--){
        cin>>n;
        cout<<long(pow(2,n)-1) % mod<<endl;
    }
}