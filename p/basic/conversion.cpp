#include<bits/stdc++.h>
using namespace std;


string to_binary(int n)
{
    string bi="";
    int rem;
    while(n>0)
    {
        if (n % 2 == 1)
        {
            bi = '1' + bi;
        }else{
            bi = '0' + bi;
        }
        n = n / 2;
    }
    return bi;
}

int to_decimal(string bi){
    int ans = 0;
    int n = bi.size();

    for(int i = 0; i < n; i++)
    {
        ans += 2^(n-i) * (bi[i] - '0');
    }
    return ans;
}

int lsb(int n)
{
    int cnt=0;
    while(n>0)
    {
        if(n%2 == 1){
            break;
        }
        n >> 1;
        cnt++;
    }
    return cnt - 1;
}


int main()
{
    int n;

    return 0;
}


int count(int n, int i)
{
    int x = (1 << (i+1));  // 2^i+1
    int y = (1 << i);       // 2^i
    return ((n+1)/x)* y + max(0, (n+1) % x - y);
}

int nonZero(int l, int r)
{
    
    int msb = log2(r);
    int ans = 0;
    for(int i = 0; i<=msb; i++)
    {
        int cnt = count(r, i) - count(l - 1, i);
        ans = max(cnt, ans);
    }

    return (r - l + 1 - ans);
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int l, r;
        cin>>l>>r;
        cout<<nonzero(l,r)<<endl;
    }
    return 0;
}
