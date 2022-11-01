class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {

        int m = arr.size(), n = arr[0].size();

        bool row = false, col = false;

        // Check 0 in the first col.
        for(int i = 0; i < m; i++) {

            if(arr[i][0] == 0) {

                col = true;
            }
        }

        // Check 0 in first row.
        for(int i = 0; i < n; i++) {

            if(arr[0][i] == 0) {

                row = true;
            }
        }

        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                if(arr[i][j] == 0) {

                    arr[i][0] = arr[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++) {

            for(int j = 1; j < n; j++) {

                if(arr[i][0] == 0 or arr[0][j] == 0) {

                    arr[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < m; i++) {

            if(col) {

                arr[i][0] = 0;
            }
        }

        for(int i = 0; i < n; i++) {

            if(row) {

                arr[0][i] = 0;
            }
        }
    }
};
