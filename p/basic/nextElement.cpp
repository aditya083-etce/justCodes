#include <bits/stdc++.h>
using namespace std;

vector<long long> rightLargerElement(vector<long long> &arr, int n){
    vector<long long> ans(n);
    stack<long long> st;        
    int i = n-1;    
    while(i>=0)
    {
        while (!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }else{
             ans[i] = -1;
        }
        st.push(arr[i]);
        i--;
    }
    return ans;
}

vector<long long> leftLargerElement(vector<long long> &arr, int n){
    vector<long long> ans(n);
    stack<long long> st;        
    int i = 0;    
    while(i<n)
    {
        while (!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }else{
             ans[i] = -1;
        }
        st.push(arr[i]);
        i++;
    }
    return ans;
}

vector<long long> rightSmallerElement(vector<long long> &arr, int n){
    vector<long long> ans(n);
    stack<long long> st;        
    int i = n-1;    
    while(i>=0)
    {
        while (!st.empty() && st.top() > arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }else{
             ans[i] = -1; // ans [i] == n
        }
        st.push(arr[i]);
        i--;
    }
    return ans;
}

vector<long long> leftSmallerElement(vector<long long> &arr, int n){
    vector<long long> ans(n);
    stack<long long> st;        
    int i = 0;    
    while(i<n)
    {
        while (!st.empty() && st.top() > arr[i]){
            st.pop();
        }
        if (!st.empty()){
            ans[i] = st.top();
        }else{
             ans[i] = -1;
        }
        st.push(arr[i]);
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> arr;
    vector<long long> ans;

    for(int i = 0; i<n; i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    while (true)
    {
        cout<<"1: rightLargerElement || 2: leftLargerElement || 3: rightSmallerElement || 4: leftSmallerElement"<<endl;
        cout<<"enter ur choice (press 0 to exit): ";
        int c;
        cin>>c;
        if (c == 0){
            break;
        }
        switch(c)
        {
            case 1:
                ans = rightLargerElement(arr, n);
                for(long long ele: ans) {
                    cout<<ele<<" ";
                }
                break;
            case 2:
                ans = leftLargerElement(arr,n);
                for(long long ele: ans) {
                    cout<<ele<<" ";
                }
                break;
            case 3:
                ans = rightSmallerElement(arr,n);
                for(long long ele: ans) {
                    cout<<ele<<" ";
                }
                break;
            case 4:
                ans = leftSmallerElement(arr,n);
                for(long long ele: ans) {
                    cout<<ele<<" ";
                }
                break;
            default:
                cout<<"Wrong Choice!"<<endl;
                break;
        }
        cout<<endl;
    }
    return 0;
}
