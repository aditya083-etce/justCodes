#include<bits/stdc++.h>
using namespace std;

int ncr(int n, int r)
{
    if (r == 0 || n == r){
        return 1;
    }
    else{
        return (ncr(n-1,r) + ncr(n-1, r-1));
    }
}

void approach1(int rows)
{
    int space = rows;
    for(int i = 0; i<rows; i++){
        for(int i = 0; i<space; i++)
        {
            cout<<" ";
        }
        for(int j = 0; j<=i; j++)
        {
            cout<<ncr(i, j)<<" ";
        }
        cout<<endl;
        space--;
    }
}

void approach2(int rows)
{
    vector<vector<int>> v(rows+1,vector<int>(rows+1,1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i>=2 and j>0 and j<i)
            {
                v[i][j] = v[i-1][j] + v[i-1][j-1];
            }
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void approach3(int rows)
{
    vector<int> arr = {1, 1};

    for(int i = 0; i <= rows; i++) {
        vector<int> curr = {1};
        for(int j = 0; j <= i; j++) {
            if(i <= 1 or j == 0 or j == i) {
                cout << "1 ";
            } else {
                cout << arr[j - 1] + arr[j] << " ";
                curr.push_back(arr[j - 1] + arr[j]);
            }
        }
        cout << endl;
        curr.push_back(1);
        arr = curr;
    }

}

void approach4(int rows)
{
    vector<int> arr(rows + 1, 1);

    for(int i = 0; i <= rows; i++) {
        if(i >= 2) {
            int last = arr[1] + arr[0];
            for(int j = 2; j <= i; j++) {
                int curr = arr[j - 1] + arr[j];
                arr[j - 1] = last;
                last = curr;
            }
        }
        for(int j = 0; j <= i; j++) {
            cout << arr[j] <<  " ";
        }
        cout << endl;
    }
}


int main()
{
    int rows;
    cin>>rows;
    approach(rows);
    return 0;
}