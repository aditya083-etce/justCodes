#include <bits/stdc++.h>
using namespace std;

// total number is 2 ^ n

vector<vector<int>> res;

// using power set
void powersetSubSEQ(vector<int>& nums) {  
    int n = nums.size();
    
    for(int num = 0; num < (1 << n); num++){
        vector<int> sub;
        
        for(int i = 0; i<n; i++){
            if (num & (1 << i)){
                sub.push_back(nums[i]);
            }
        }
        
        res.push_back(sub);
    }
}

void printSubSeq(int ind, int n, vector<int> &arr, vector<int> &seq){
    if (ind == n){
        res.push_back(seq);
        return;
    }

    seq.push_back(arr[ind]);
    printSubSeq(ind + 1, n, arr, seq); // take
    seq.pop_back();

    printSubSeq(ind + 1, n, arr, seq); // nottake
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }


    vector<int> seq;
    printSubSeq(0, n, arr, seq);
    // powersetSubSEQ(arr);


    for(auto &vec: res){
        cout << "[ ";
        for(int val: vec){
            cout << val << " ";
        }
        cout << " ]" << endl;
    }
    return 0;
}