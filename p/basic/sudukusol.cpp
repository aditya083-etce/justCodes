// <vARIATION 1 LEETCODE
// <<--- Variation 2 --->
class Solution {
public:
    bool isSafe(int row, int col, char c, vector<vector<char>>& arr) {
        
        // Row
        for(int i = 0; i < 9; i++) {
            
            if(arr[row][i] == c) {
                
                return false;
            }
        }
        
        // Column
        for(int i = 0; i < 9; i++) {
            
            if(arr[i][col] == c) {
                
                return false;
            }
        }
        
        // Sub-Matrix
        int x = (row / 3) * 3, y = (col / 3) * 3;
        
        for(int i = x; i < x + 3; i++) {
            
            for(int j = y; j < y + 3; j++) {
                
                if(arr[i][j] == c) {
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int solve(int row, int col, vector<vector<char>>& arr) {
        
        // Base Case
        if(row == 9) {
            
            return 1;
        } if(col == 9) {
            
            return solve(row + 1, 0, arr);
        }
        
        if(arr[row][col] == '.') {
            
            int ans = 0;
            
            for(int i = 1; i <= 9; i++) {
                
                char c = '0' + i;
                
                if(isSafe(row, col, c, arr)) {
                                        
                    arr[row][col] = c;
                    
                    ans += solve(row, col + 1, arr);
                    
                    arr[row][col] = '.';
                }
            }
            
            return ans;
        } else {
            
            return solve(row, col + 1, arr);
        }
    }
    
    void solveSudoku(vector<vector<char>>& arr) {
        
        cout << solve(0, 0, arr);
    }
};