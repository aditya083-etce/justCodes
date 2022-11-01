#include <bits/stdc++.h>
using namespace std;

void nextPermutation(string &nums) {
    int n = nums.size();
    
    int ind1 = -1;
    
    for(int i = n-2; i>=0; i--) {
        if (nums[i] < nums[i+1]) {
            ind1 = i;
            break;
        }
    }
    
    if (ind1 == -1) { 
        reverse(nums.begin(), nums.end());
        return;
    }
    
    int ind2 = -1;
    for(int i = n-1; i>=ind1; i--) {
        if (nums[i] > nums[ind1]) {
            ind2 = i;
            break;
        }
    }
    
    swap(nums[ind1],nums[ind2]);
    reverse(nums.begin() + ind1 + 1, nums.end());
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string str; cin >> str;
    string ori = str;
    nextPermutation(str);

    if (str > ori) cout << str << endl;
    else cout << -1 << endl;
}