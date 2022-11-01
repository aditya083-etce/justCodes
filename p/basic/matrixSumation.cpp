#include <bits/stdc++.h>
using namespace std;

void viewMatrix(vector<vector<int>> arr, int m, int n) {
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    viewMatrix(arr, m, n);
    vector<vector<int>> ans = arr;

    for(int i = m-1; i>=0; i--) {
        for(int j = n-1; j>=0; j--) {
            if (i >= 1 and j >= 1) {
                ans[i][j] = ans[i][j] - ans[i-1][j] - ans[i][j-1] + ans[i-1][j-1];
            } else  if (j >= 1) {
                ans[i][j] -= ans[i][j-1];
            } else  if (i >= 1) {
                ans[i][j] -= ans[i-1][j];
            }
        }
    }

    viewMatrix(ans, m, n);
    return 0;
}
