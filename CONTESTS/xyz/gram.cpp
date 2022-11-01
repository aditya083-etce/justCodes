#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<string,int> map;
    
    for(int i = 0; i<n-1; i++){
        map[s.substr(i,2)]++;
    }

    int max = 0;
    string ans = "";

    for(auto it: map)
    {
        if (it.second > max)
        {
            max = it.second;
            ans = it.first;
        }
    }
    cout << ans << endl;
    return 0;
}