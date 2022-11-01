#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int s; cin>>s;
        int x = 1; 
        long long sum = 0;
        int c = 0;

        while(sum < s)
        {
            sum += x;
            x += 2;
            c++;
        }
        cout<<c<<endl;
    }
    return 0;
}

//https://www.youtube.com/watch?v=zeMPEJiZad0