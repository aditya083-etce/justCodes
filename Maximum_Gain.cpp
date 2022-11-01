#include <bits/stdc++.h>
using namespace std;

#define pi (3.141592653589)
#define mod 1e9+7
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) cc.begin(), c.end()
#define mini(a, b, c) min(c, min(a, b))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int solve(vector<int> A, int leftA, int rightA, vector<int> B, int leftB, int rightB, int k){
    if (k == 0) return 0;

    if (leftA > rightA){
        if (leftB > rightB){
            return 0;
        }else{
            int case1 = B[leftB] + solve(A, leftA, rightA, B, leftB + 1, rightB, k-1);
            int case2 = B[rightB] + solve(A, leftA, rightA, B, leftB, rightB - 1, k-1);
            
            return max(case1, case2);
        }
    }else{
        if (leftB > rightB){
            int case1 = A[leftA] + solve(A, leftA + 1, rightA, B, leftB, rightB, k-1);
            int case2 = A[rightA] + solve(A, leftA, rightA - 1, B, leftB, rightB, k-1);
            
            return max(case1, case2);
        }else{
            int case1 = A[leftA] + solve(A, leftA + 1, rightA, B, leftB, rightB, k-1);
            int case2 = A[rightA] + solve(A, leftA, rightA - 1, B, leftB, rightB, k-1);
            int case3 = B[leftB] + solve(A, leftA, rightA, B, leftB + 1, rightB, k-1);
            int case4 = B[rightB] + solve(A, leftA, rightA, B, leftB, rightB -  1, k-1);
            
            return max(case1 , max(case2, max(case3, case4)));
        }
    }
}

int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    int c = 1;
    while(t--){
        cout<<"Case #"<<c<<": ";
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        int m; cin >> m;
        vector<int> b(m);
        for(int i = 0; i<n; i++){
            cin >> b[i];
        }

        int k; cin >> k;
        cout << solve(a, 0, n-1, b, 0, m-1, k) << endl;
        c++;
    }
    return 0;
}