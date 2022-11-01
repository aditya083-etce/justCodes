#include <bits/stdc++.h>
using namespace std;

int countsubarray(vector<int> &arr, int n)
{
    int count = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                break;
            }
            count++;
        }
    }
    return count;
}

    int main()
    {
        int t, n;
        cin >> t;
        vector<int> input;
        while (t--)
        {
            cin >> n;
            int element;
            for (int i = 0; i < n; i++)
            {
                cin >> element;
                input.push_back(element);
            }
            cout<<countsubarray(input, n)<<endl;
        }
        return 0;
    }
