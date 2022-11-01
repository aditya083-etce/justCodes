#include<bits/stdc++.h> 
using namespace std;

vector<int> solve (vector <pair<int, int> > &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> ans; 
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i].second);
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=1; i<=n; i++)
    {
        int ele;
        cin>>ele;
        arr.push_back({ele, i});
    }
    vector <int> ans = solve(arr);

    for (int i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}