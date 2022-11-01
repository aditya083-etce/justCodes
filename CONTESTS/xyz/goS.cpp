#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;

    while(t--)
    {
        cin>>s;
        set<char> s;
        for(int i=0; i<s.length(); i++)
        {
            if(i%2 == 0){
                s[i] = s[i] + 1;
            }else{
                s[i] = s[i] - 1;
            }
        }

        cout << s << endl;
    }
    return 0;
}