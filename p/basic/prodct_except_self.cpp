#include <bits/stdc++.h>
using namespace std;

 vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        int leftproduct = 1;
        for(int i=0;i<n;++i)
        {
            leftproduct *= nums[i];
            output.push_back(leftproduct);            
        }
        int rightproduct = 1;
        for(int i=n-1;i>0;--i)
        {
            output[i] = output[i-1]*rightproduct;
            rightproduct *= nums[i];
        }
        output[0] = rightproduct;
        return output;
    }
int main()
{
    int n, ele;
    vector<int> input;
    vector<int> output;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        input.push_back(ele);
    }
    output = productExceptSelf(input);
    for(int i = 0; i<n; i++){
        cout<<output[i]<<" ";
    }
    return 0;
}