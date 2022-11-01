#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int k;
    cin>>k;
    string str="";
    for(int i = 1; i<= k; i++)
    {
        str +=to_string(i);
    }

    cout<<str[k - 1];
    return 0;
}