# include<bits\stdc++.h>
using namespace std;

int findSqrt(int n, int s, int e)
{
    int mid = (s + e) /2;
    int sq = mid * mid;
    if (sq == n)
    {
        return mid;
    } 
    else if (sq < n){
        return findSqrt(n, mid+1, e);
    }

    return findSqrt(n, s, mid- 1);
}

int findSqrt_iter(int x)
{
    int s = 1;
    int e = x;
    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        int sq = mid * mid;
        if (sq == x)
        {
            return mid;
        }
        else if (sq < x){
            s = mid + 1;
            ans = mid;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int x;
    cin>>x;
    // cout<<findSqrt_iter(x);
    cout<<findSqrt(x,1,x);
    return 0;
}