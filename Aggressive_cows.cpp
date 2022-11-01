#include <bits/stdc++.h>
using namespace std;

bool isPossible(int miniDist, vector<int> &arr, int N, int cows) {
    int lastPlacedCow = arr[0];
    int cowcnt = 1;

    for(int i = 1; i < N; i++){
        if (arr[i] - lastPlacedCow >= miniDist) {
            cowcnt++;
            lastPlacedCow = arr[i];
        }
    }

    if (cowcnt >= cows) return true;

    return false;
}

int LargestMinDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr[N - 1] - arr[0];

    while(low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(mid, arr, N, C)){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T; cin >> T;

    while (T--)
    {
        int stalls; cin >> stalls;
        int cows; cin >> cows;
        vector<int> arr(stalls);

        for(int i = 0; i<stalls; i++){
            cin >> arr[i];
        }

        cout << LargestMinDistance(arr, stalls, cows) << endl;
    }

    return 0;
}