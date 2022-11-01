// ALL PATHS
class Solution{
    public:
    void solve(int r, int c, vector<vector<int>> &m, vector<vector<bool>> &v, string s, vector<string> &ans) {
        
        int n = m.size();
        
        if(r == n - 1 and c == n - 1) {
            
            ans.push_back(s);
            
            return;
        }
        
        v[r][c] = true;
        
        // Check all four adjacent cell
        // If unvisited call the solve function for that cell.
        // Include move in string s.
        // Mark the position in v.
        
        // Up
        if(r > 0 and m[r - 1][c] == 1 and !v[r - 1][c]) {
            
            solve(r - 1, c, m, v, s + 'U', ans);
        }
        
        // Down
        if(r < n - 1 and m[r + 1][c] == 1 and !v[r + 1][c]) {
            
            solve(r + 1, c, m, v, s + 'D', ans);
        }
        
        // Left
        if(c > 0 and m[r][c - 1] == 1 and !v[r][c - 1]) {
            
            solve(r, c - 1, m, v, s + 'L', ans);
        }
        
        // Right
        if(c < n - 1 and m[r][c + 1] == 1 and !v[r][c + 1]) {
            
            solve(r, c + 1, m, v, s + 'R', ans);
        }
        
        v[r][c] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
            
            return ans;
        }
        
        vector<vector<bool>> v(n, vector<bool> (n, false));
        
        solve(0, 0, m, v, "", ans);
        
        return ans;
    }
};


// ALL PATHS - Optimised
class Solution{
    public:
    void solve(int r, int c, vector<vector<int>> &m, string s, vector<string> &ans) {
        
        int n = m.size();
        
        if(r == n - 1 and c == n - 1) {
            
            ans.push_back(s);
            
            return;
        }
        
        m[r][c] = 2;
        
        // Check all four adjacent cell
        // If unvisited call the solve function for that cell.
        // Include move in string s.
        // Mark the position in v.
        
        // Up
        if(r > 0 and m[r - 1][c] == 1) {
            
            solve(r - 1, c, m,s + 'U', ans);
        }
        
        // Down
        if(r < n - 1 and m[r + 1][c] == 1) {
            
            solve(r + 1, c, m,s + 'D', ans);
        }
        
        // Left
        if(c > 0 and m[r][c - 1] == 1) {
            
            solve(r, c - 1, m,s + 'L', ans);
        }
        
        // Right
        if(c < n - 1 and m[r][c + 1] == 1) {
            
            solve(r, c + 1, m,s + 'R', ans);
        }
        
        m[r][c] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
            
            return ans;
        }
        
        
        solve(0, 0, m,"", ans);
        
        return ans;
    }
};


// ALL PATHS - Further Optimisd
class Solution{
    public:
    void solve(int r, int c, vector<vector<int>> &m, string &s, vector<string> &ans) {
        
        int n = m.size();
        
        if(r == n - 1 and c == n - 1) {
            
            ans.push_back(s);
            
            return;
        }
        
        m[r][c] = 2;
        
        // Check all four adjacent cell
        // If unvisited call the solve function for that cell.
        // Include move in string s.
        // Mark the position in v.
        
        // Up
        if(r > 0 and m[r - 1][c] == 1) {
            
            s.push_back('U');
            
            solve(r - 1, c, m,s, ans);
            
            s.pop_back();
        }
        
        // Down
        if(r < n - 1 and m[r + 1][c] == 1) {
            
            s.push_back('D');
            
            solve(r + 1, c, m,s, ans);
            
            s.pop_back();
        }
        
        // Left
        if(c > 0 and m[r][c - 1] == 1) {
            
            s.push_back('L');
            
            solve(r, c - 1, m,s, ans);
            
            s.pop_back();
        }
        
        // Right
        if(c < n - 1 and m[r][c + 1] == 1) {
            
            s.push_back('R');
            
            solve(r, c + 1, m,s, ans);
            
            s.pop_back();
        }
        
        m[r][c] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
            
            return ans;
        }
        
        string s = "";
        solve(0, 0, m,s, ans);
        
        return ans;
    }
};

// NO OF PATHS
#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &m) {
        
    int n = m.size();
    
    if(r == n - 1 and c == n - 1) {
        
        return 1;
    }
    
    m[r][c] = 2;
    
    // Check all four adjacent cell
    // If unvisited call the solve function for that cell.
    // Include move in string s.
    // Mark the position in v.
    
    int ans = 0;
    
    // Up
    if(r > 0 and m[r - 1][c] == 1) {
        
        ans += solve(r - 1, c, m);
    }
    
    // Down
    if(r < n - 1 and m[r + 1][c] == 1) {
        
        ans += solve(r + 1, c, m);
    }
    
    // Left
    if(c > 0 and m[r][c - 1] == 1) {
        
        ans += solve(r, c - 1, m);
    }
    
    // Right
    if(c < n - 1 and m[r][c + 1] == 1) {
        
        ans += solve(r, c + 1, m);
    }
    
    m[r][c] = 1;
    
    return ans;
}

int findNumberOfPaths(vector<vector<int>> &m, int n) {
    
    if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
        
        return 0;
    }
    
    return solve(0, 0, m);
}

int main() {

    int n;
    cin >> n;
    
    vector<vector<int>> m(n, vector<int> (n));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> m[i][j];
        }
    }

    cout << solve(0, 0, m);
     
    return 0;
}


//MIN-LEN PATH
#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &m) {
        
    int n = m.size();
    
    if(r == n - 1 and c == n - 1) {
        
        return 0;
    }
    
    m[r][c] = 2;
    
    // Check all four adjacent cell
    // If unvisited call the solve function for that cell.
    // Include move in string s.
    // Mark the position in v.
    
    int ans = INT_MAX;
    
    // Up
    if(r > 0 and m[r - 1][c] == 1) {
        
        ans = min(ans, solve(r - 1, c, m));
    }
    
    // Down
    if(r < n - 1 and m[r + 1][c] == 1) {
        
        ans = min(ans, solve(r + 1, c, m));
    }
    
    // Left
    if(c > 0 and m[r][c - 1] == 1) {
        
        ans = min(ans, solve(r, c - 1, m));
    }
    
    // Right
    if(c < n - 1 and m[r][c + 1] == 1) {
        
        ans = min(ans, solve(r, c + 1, m));
    }
    
    m[r][c] = 1;
    
    return ans == INT_MAX ? ans : ans + 1;
}

int minLenPath(vector<vector<int>> &m, int n) {
    
    if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
        
        return -1;
    }

    int ans = solve(0, 0, m);

    return ans == INT_MAX ? -1 : ans;
}

int main() {

    int n;
    cin >> n;
    
    vector<vector<int>> m(n, vector<int> (n));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> m[i][j];
        }
    }

    cout << minLenPath(m, n);
     
    return 0;
}


// MIN-LEN PATH - Optimised
#include<bits/stdc++.h>
using namespace std;

void solve(int r, int c, vector<vector<int>> &m, int steps, int &ans) {

    if(steps > ans) {

        return;
    }
        
    int n = m.size();
    
    if(r == n - 1 and c == n - 1) {

        ans = min(ans, steps);
        
        return;
    }
    
    m[r][c] = 2;
    
    // Check all four adjacent cell
    // If unvisited call the solve function for that cell.
    // Include move in string s.
    // Mark the position in v.
    
    // Up
    if(r > 0 and m[r - 1][c] == 1) {
        
        solve(r - 1, c, m, steps + 1, ans);
    }
    
    // Down
    if(r < n - 1 and m[r + 1][c] == 1) {
        
        solve(r + 1, c, m, steps + 1, ans);
    }
    
    // Left
    if(c > 0 and m[r][c - 1] == 1) {
        
        solve(r, c - 1, m, steps + 1, ans);
    }
    
    // Right
    if(c < n - 1 and m[r][c + 1] == 1) {
        
        solve(r, c + 1, m, steps + 1, ans);
    }
    
    m[r][c] = 1;
}

int minLenPath(vector<vector<int>> &m, int n) {
    
    if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
        
        return -1;
    }

    int ans = INT_MAX;

    solve(0, 0, m, 0, ans);

    return ans == INT_MAX ? -1 : ans;
}

int main() {

    int n;
    cin >> n;
    
    vector<vector<int>> m(n, vector<int> (n));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> m[i][j];
        }
    }

    cout << minLenPath(m, n);
     
    return 0;
}

//MAX-LEN PATH
#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &m) {
        
    int n = m.size();
    
    if(r == n - 1 and c == n - 1) {
        
        return 0;
    }
    
    m[r][c] = 2;
    
    // Check all four adjacent cell
    // If unvisited call the solve function for that cell.
    // Include move in string s.
    // Mark the position in v.
    
    int ans = INT_MIN;
    
    // Up
    if(r > 0 and m[r - 1][c] == 1) {
        
        ans = max(ans, solve(r - 1, c, m));
    }
    
    // Down
    if(r < n - 1 and m[r + 1][c] == 1) {
        
        ans = max(ans, solve(r + 1, c, m));
    }
    
    // Left
    if(c > 0 and m[r][c - 1] == 1) {
        
        ans = max(ans, solve(r, c - 1, m));
    }
    
    // Right
    if(c < n - 1 and m[r][c + 1] == 1) {
        
        ans = max(ans, solve(r, c + 1, m));
    }
    
    m[r][c] = 1;
    
    return ans == INT_MIN ? ans : ans + 1;
}

int maxLenPath(vector<vector<int>> &m, int n) {
    
    if(m[0][0] == 0 or m[n - 1][n - 1] == 0) {
        
        return -1;
    }

    int ans = solve(0, 0, m);

    return ans == INT_MIN ? -1 : ans;
}

int main() {

    int n;
    cin >> n;
    
    vector<vector<int>> m(n, vector<int> (n));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> m[i][j];
        }
    }

    cout << maxLenPath(m, n);
     
    return 0;
}

// (X,Y) in path (no of paths)
#include<bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<vector<int>> &m, int x, int y, bool &flag) {

    int n = m.size();
    
    if(r == n - 1 and c == n - 1) {
        
        return flag;
    }
    
    m[r][c] = 2;

    if(r == x and c == y) {

        flag = true;
    }
    
    // Check all four adjacent cell
    // If unvisited call the solve function for that cell.
    // Include move in string s.
    // Mark the position in v.

    int ans = 0;
    
    // Up
    if(r > 0 and m[r - 1][c] == 1) {
        
        ans += solve(r - 1, c, m, x, y, flag);
    }
    
    // Down
    if(r < n - 1 and m[r + 1][c] == 1) {
        
        ans += solve(r + 1, c, m, x, y, flag);
    }
    
    // Left
    if(c > 0 and m[r][c - 1] == 1) {
        
        ans += solve(r, c - 1, m, x, y, flag);
    }
    
    // Right
    if(c < n - 1 and m[r][c + 1] == 1) {
        
        ans += solve(r, c + 1, m, x, y, flag);
    }

    if(r == x and c == y) {

        flag = false;
    }
    
    m[r][c] = 1;

    return ans;
}

int countPathIncludingXY(vector<vector<int>> &m, int &n, int &x, int &y) {

    bool flag = false;

    return solve(0, 0, m, x, y, flag);
}

int main() {

    int n;
    cin >> n;
    
    vector<vector<int>> m(n, vector<int> (n));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cin >> m[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    cout << countPathIncludingXY(m, n, x, y);
     
    return 0;
}

