#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int ans = 0;

        for(int i = 0; i < n-1; i++){
            ans += (s[i] - '0');
            if ((s[i] - '0') > 0){
                ans++;
            }
        }
        ans += s[n-1] - '0';
        cout<<ans<<endl;
    }
    return 0;
}