#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long a, b;
    while(t--){
        cin>>a>>b;

        long long res = 0;
        long long d = a-1;

        if(d % 4 == 0){
            res = d;
        }else if(d % 4 == 1){
            res = 1;
        }else if(d % 4 == 2){
            res = 2;
        }else{
            res = 0;
        }

        if (res == b){
            cout<<a<<endl;
        }else if((res^a) == b)
        {
            cout<<a+2<<endl;
        }else{
            cout<<a+1<<endl;
        }
    }
    return 0;
}

// https://www.youtube.com/watch?v=7GJ9herCBio