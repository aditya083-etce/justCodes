#include<bits/stdc++.h> 
using namespace std;

int main()
{
    long long k, n;
    cin>>n>>k;

    while(k--)
    {
        int r = n% 10;
        if (r == 0)
        {
            n = n/10;
        }
        else
        {
            n--;
        }
    }
    cout<<n<<endl;
}