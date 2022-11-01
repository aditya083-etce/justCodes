#include <bits/stdc++.h>
using namespace std;
#define int                                  long long
#define vi                                   vector<int>
#define pb                                   push_back
#define ppb                                  pop_back
#define pf                                   push_front
#define ppf                                  pop_front
#define all(x)                               (x).begin(),(x).end()
#define allr(x)                              (x).rbegin(),(x).rend()
#define uniq(v)                              (v).erase(unique(all(v)),(v).end())
#define sz(x)                                (int)((x).size())
#define ff                                   first
#define ss                                   second
#define pii                                  pair<int,int>
#define rep(i,a,b)                           for(int i=a;i<b;i++)
#define mem1(a)                              memset(a,-1,sizeof(a))
#define mem0(a)                              memset(a,0,sizeof(a))
#define ppc                                  __builtin_popcount
#define ppcll                                __builtin_popcountll
#define nl                                   endl
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.ff>>a.ss;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.ff<<" "<<a.ss;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
const string yes = "YES";
const string no = "NO";
const int N = 2*100005+1;
const long long INF=1e17;
const long long NINF=-INF;
const int32_t M=1e9+7;
const int32_t MM=998244353;
const int MOD = 1000000007;

int32_t main(){
    FASTIO

    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        set<char> st;
        int ans=0;
        rep(i,0,s.size()){
            st.insert(s[i]);
            if(st.size()>3){
                ans++;
                st.clear();
                st.insert(s[i]);
            }
        }

        if(!st.empty()){
            ans++;
        }

        cout << ans << endl;

    }
    return 0;
}