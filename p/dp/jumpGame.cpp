#include <bits/stdc++.h>
using namespace std;

class Pair{
public:
    int indx;
    int size;
    int jumps;
    string psf;

    Pair(int i, int s, int j, string str){
        indx = i;
        size = s;
        jumps = j;
        psf = str;
    }
};

class Solution{
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        
        for(int i = n-2; i>=0; i--){
            int steps = nums[i];
            
            int mn = INT_MAX;
            for(int j = 1; j<=steps && i + j < n; j++){
                if(dp[i + j] != -1){
                    mn = min(mn, dp[i+j]);
                }
            }
            
            if (mn != INT_MAX){
                dp[i] = mn + 1;
            }
        }

        queue<Pair*> Q;
        Q.push(new Pair(0, nums[0], dp[0], ""));

        while(!Q.empty()){
            Pair pr = Q.front();
            Q.pop();
            //pr.size -> steps

            if (pr.jumps == 0){
                cout << pr.psf + "." <<endl;
            }

            for(int j = 1; j <= pr.size && pr.size + j < n; j++){
                int currIdx = pr.indx + j;
                if (dp[currIdx] != -1 && dp[currIdx] == pr.jumps - 1){
                    Q.push(new Pair(currIdx, nums[currIdx], dp[currIdx], pr.psf + " -> " + to_string(currIdx)));
                }
            }
        }
        return dp[0];
    }
};

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol; 

    cout << "Minimum number of Jumps needed: "<< sol.jump(arr) <<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Pair{
public:
    int indx;
    int size;
    int jumps;
    string psf;

    Pair(int i, int s, int j, string str){
        indx = i;
        size = s;
        jumps = j;
        psf = str;
    }
};

class Solution{
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        
        for(int i = n-2; i>=0; i--){
            int steps = nums[i];
            
            int mn = INT_MAX;
            for(int j = 1; j<=steps && i + j < n; j++){
                if(dp[i + j] != -1){
                    mn = min(mn, dp[i+j]);
                }
            }
            
            if (mn != INT_MAX){
                dp[i] = mn + 1;
            }
        }

        queue<Pair*> Q;
        Q.push(new Pair(0, nums[0], dp[0], ""));

        while(!Q.empty()){
            Pair pr = Q.front();
            Q.pop();
            //pr.size -> steps

            if (pr.jumps == 0){
                cout << pr.psf + "." <<endl;
            }

            for(int j = 1; j <= pr.size && pr.size + j < n; j++){
                int currIdx = pr.indx + j;
                if (dp[currIdx] != -1 && dp[currIdx] == pr.jumps - 1){
                    Q.push(new Pair(currIdx, nums[currIdx], dp[currIdx], pr.psf + " -> " + to_string(currIdx)));
                }
            }
        }
        return dp[0];
    }
};

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol; 

    cout << "Minimum number of Jumps needed: "<< sol.jump(arr) <<endl;
    return 0;
}
