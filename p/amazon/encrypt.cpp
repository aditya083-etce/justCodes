#include <bits/stdc++.h>
using namespace std;

string getEncryptedNumber(vector<int> &nums) {
    for(int i = nums.size(); i > 2; i--) {
        for(int j = 0; j < i - 1; j++) {
            nums[j] = (nums[j] + nums[j+1]) % 10;
        }
    }
    return to_string(nums[0]) + to_string(nums[1]);
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getEncryptedNumber(arr) << endl;
    return 0;
}