#include <bits/stdc++.h>
using namespace std;

void solve1(vector<vector<char>>&ans,int i,int j,char c,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int sz = q.size();
        for(int k=0;k<sz;k++){
            auto v = q.front();
            q.pop();
            int x = v.first;
            int y = v.second;
            if(x<0 || y<0 || vis[x][y])continue;
            ans[x][y] = c;
            vis[x][y] = 1;
            q.push({x-1,y-1});
            q.push({x-1,y});
            q.push({x,y-1});
        }
        c = (c-'A'+1)%26+'A';
    }
}

void solve2(vector<vector<char>>&ans,int i,int j,char c,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int sz = q.size();
        for(int k=0;k<sz;k++){
            auto v = q.front();
            q.pop();
            int x = v.first;
            int y = v.second;
            if(x<0 || y>=ans.size() || vis[x][y])continue;
            ans[x][y] = c;
            vis[x][y] = 1;
            q.push({x-1,y+1});
            q.push({x-1,y});
            q.push({x,y+1});
        }
        c = (c-'A'+1)%26+'A';
    }
}

void solve3(vector<vector<char>>&ans,int i,int j,char c,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int sz = q.size();
        for(int k=0;k<sz;k++){
            auto v = q.front();
            q.pop();
            int x = v.first;
            int y = v.second;
            if(x>=ans.size() || y<0 || vis[x][y])continue;
            ans[x][y] = c;
            vis[x][y] = 1;
            q.push({x+1,y-1});
            q.push({x+1,y});
            q.push({x,y-1});
        }
        c = (c-'A'+1)%26+'A';
    }
}

void solve4(vector<vector<char>>&ans,int i,int j,char c,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int sz = q.size();
        for(int k=0;k<sz;k++){
            auto v = q.front();
            q.pop();
            int x = v.first;
            int y = v.second;
            if(x>=ans.size() || y>=ans.size() || vis[x][y])continue;
            ans[x][y] = c;
            vis[x][y] = 1;
            q.push({x+1,y+1});
            q.push({x+1,y});
            q.push({x,y+1});
        }
        c = (c-'A'+1)%26+'A';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    int n;
    cin>>n;
    int m = 2*n;
    vector<vector<char>>ans(m,vector<char>(m));
    vector<vector<int>>vis(m,vector<int>(m));

    solve1(ans,n-1,n-1,'A',vis);
    solve2(ans,n-1,n,'A',vis);
    solve3(ans,n,n-1,'A',vis);
    solve4(ans,n,n,'A',vis);
    
    for(auto&row:ans){
        for(auto&c:row)cout<<c;
        cout<<"\n";
    }
    return 0;
}