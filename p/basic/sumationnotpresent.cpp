#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &nums, int low, int high, int element)
{
    if (low<=high)
    {
        int mid = (low+high)/2;
        if (nums[mid]==element){
            return mid;
        }
        if (nums[mid]>element)
        {
            return binary_search(nums,low,mid-1,element);
        }
        if(nums[mid]<element)
        {
            return binary_search(nums,mid+1,high,element);
        }
    }
    return -1;
}

int main() {
    int m,n;
    cin>>m>>n;
    int number;
    vector <int> arr1, arr2; 
    for(int i = 0; i<m; i++){
        cin>>number;
        arr1.push_back(number);
    }
    for(int i = 0; i<n; i++){
        cin>>number;
        arr2.push_back(number);
    }
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            int sum = arr1[i] + arr2[j];
            if ((binary_search(arr1, 0, m-1, sum) == -1) ||
                (binary_search(arr2, 0, n-1, sum) == -1))
                {
                    cout<<arr1[i]<<" "<<arr2[j]<<endl;
                }
        }
    }
    return 0;
}