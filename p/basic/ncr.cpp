#include<bits/stdc++.h>
using namespace std;

// int factorial(int n)
// {
//     int fact = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         fact *= i;
//     }  
//     return fact;
// }

// int ncr(int n, int r)
// {
//     double ans = fact(n);
//     ans /= fact(n-r);
//     ans /= fact(r);
//     return ans;
// }


// TC - O(n)
void factorial(int n, int fac[]) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

// TC - O(1).
int nCr(int n, int r, int fac[]) {
    int ans = fac[n];
    ans /= fac[n - r];
    ans /= fac[r];
    return ans;
}

int main() {
    int n;
    cin >> n;
    int fac[n + 1];
    factorial(n, fac);
    for(int i = 0; i <= n; i++) {
        cout << nCr(n, i, fac) << " ";
    }
    return 0;
}


// Using recursion

long long int ncr_approach1(int n, int r)
{
    if (r == 0 || n == r){
        return 1;
    }
    else{
        return (ncr(n-1,r) + ncr(n-1, r-1));
    }
}

long long int ncr_approach2(int n, int r)
{
    if (r == 0 || n == r){
        return 1;
    }
    else{
        return ((n*ncr(n-1, r-1))/r);
    }
}

int main()
{
    int n, r;
    cin>>n>>r;

    cout<<ncr(n,r);
    return 0;
}