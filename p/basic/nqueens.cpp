#include<bits/stdc++.h>
using namespace std;

//<--- Variation 1 --->
bool isSafe(int &n, vector<vector<int>> &arr) {

    // row -> i
    // col -> j
    // diagonal D1 -> i - j
    // diagonal D2 -> i + j

    unordered_set<int> R, C, D1, D2;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(arr[i][j] == 1) {

                if(R.find(i) != R.end()) {

                    return false;
                } else if(C.find(j) != C.end()) {

                    return false;
                } else if(D1.find(i - j) != D1.end()) {

                    return false;
                } else if(D2.find(i + j) != D2.end()) {

                    return false;
                }

                R.insert(i);
                C.insert(j);
                D1.insert(i - j);
                D2.insert(i + j);
            }
        }
    }

    return true;
}

bool Solve(int row, int &n, vector<vector<int>> &arr) {

    //Base Case.
    if(row == n) {

        return true;
    }

    for(int i = 0; i < n; i++) {

        arr[row][i] = 1;

        if(isSafe(n, arr) and Solve(row + 1, n, arr)) {

            return true;
        }

        arr[row][i] = 0;
    }

    return false;
}

bool Check(int &n) {

    vector<vector<int>> arr(n, vector<int> (n, 0));

    return Solve(0, n, arr);
}

int main() {

    int n;
    cin >> n;

    if(Check(n)) {

        cout << "Yes";
    } else {

        cout << "No";
    }
    
    return 0;
}



//<-- Variation 1 : Optimised -->
bool isSafe(int r, int c, int &n, vector<vector<int>> &arr) {

    int i, j;

    // Check Column
    i = r - 1;
    
    while(i >= 0) {

        if(arr[i][c] == 1) {

            return false;
        }

        i--;
    }

    // Check Diagonal D1
    i = r - 1, j = c - 1;

    while(i >= 0 and j >= 0) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j--;
    }

    // Check Diagonal D2
    i = r - 1, j = c + 1;

    while(i >= 0 and j < n) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j++;
    }

    return true;
}

bool Solve(int row, int &n, vector<vector<int>> &arr) {

    //Base Case.
    if(row == n) {

        return true;
    }

    for(int i = 0; i < n; i++) {

        arr[row][i] = 1;

        if(isSafe(row, i, n, arr) and Solve(row + 1, n, arr)) {

            return true;
        }

        arr[row][i] = 0;
    }

    return false;
}

bool Check(int &n) {

    vector<vector<int>> arr(n, vector<int> (n, 0));

    return Solve(0, n, arr);
}

int main() {

    int n;
    cin >> n;

    if(Check(n)) {

        cout << "Yes";
    } else {

        cout << "No";
    }
    
    return 0;
}



//<--- Variation 2 --->
bool isSafe(int r, int c, int &n, vector<vector<int>> &arr) {

    int i, j;

    // Check Column
    i = r - 1;
    
    while(i >= 0) {

        if(arr[i][c] == 1) {

            return false;
        }

        i--;
    }

    // Check Diagonal D1
    i = r - 1, j = c - 1;

    while(i >= 0 and j >= 0) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j--;
    }

    // Check Diagonal D2
    i = r - 1, j = c + 1;

    while(i >= 0 and j < n) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j++;
    }

    return true;
}

void printSol(int &n, vector<vector<int>> &arr) {

    cout << "Yes" << endl;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

bool Solve(int row, int &n, vector<vector<int>> &arr) {

    //Base Case.
    if(row == n) {

        printSol(n, arr);

        return true;
    }

    for(int i = 0; i < n; i++) {

        arr[row][i] = 1;

        if(isSafe(row, i, n, arr) and Solve(row + 1, n, arr)) {

            return true;
        }

        arr[row][i] = 0;
    }

    return false;
}

bool Check(int &n) {

    vector<vector<int>> arr(n, vector<int> (n, 0));

    return Solve(0, n, arr);
}

int main() {
    
    int n;
    cin >> n;

    if(!Check(n)) {

        cout << "No";
    }
    
    return 0;
}


// <--- Variation 3 ---> 
bool isSafe(int r, int c, int &n, vector<vector<int>> &arr) {

    int i, j;

    // Check Column
    i = r - 1;
    
    while(i >= 0) {

        if(arr[i][c] == 1) {

            return false;
        }

        i--;
    }

    // Check Diagonal D1
    i = r - 1, j = c - 1;

    while(i >= 0 and j >= 0) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j--;
    }

    // Check Diagonal D2
    i = r - 1, j = c + 1;

    while(i >= 0 and j < n) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j++;
    }

    return true;
}

int Solve(int row, int &n, vector<vector<int>> &arr) {

    //Base Case.
    if(row == n) {
        
        return 1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {

        arr[row][i] = 1;

        if(isSafe(row, i, n, arr)) {

            ans += Solve(row + 1, n, arr);
        }

        arr[row][i] = 0;
    }
    
    return ans;
}

int count(int &n) {

    vector<vector<int>> arr(n, vector<int> (n, 0));

    return Solve(0, n, arr);
}

int main() {

    int n;
    cin >> n;
    
    cout << count(n);
    
    return 0;
}



//<--- Variation 4 -->
bool isSafe(int r, int c, int &n, vector<vector<int>> &arr) {

    int i, j;

    // Check Column
    i = r - 1;
    
    while(i >= 0) {

        if(arr[i][c] == 1) {

            return false;
        }

        i--;
    }

    // Check Diagonal D1
    i = r - 1, j = c - 1;

    while(i >= 0 and j >= 0) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j--;
    }

    // Check Diagonal D2
    i = r - 1, j = c + 1;

    while(i >= 0 and j < n) {

        if(arr[i][j] == 1) {

            return false;
        }

        i--;
        j++;
    }

    return true;
}

void printSol(int &n, vector<vector<int>> &arr) {

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

int Solve(int row, int &n, vector<vector<int>> &arr) {

    //Base Case.
    if(row == n) {

        printSol(n, arr);

        cout << endl;
        
        return 1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {

        arr[row][i] = 1;

        if(isSafe(row, i, n, arr)) {

            ans += Solve(row + 1, n, arr);
        }

        arr[row][i] = 0;
    }
    
    return ans;
}

int count(int &n) {

    vector<vector<int>> arr(n, vector<int> (n, 0));

    return Solve(0, n, arr);
}

int main() {

    int n;
    cin >> n;
    
    count(n);
    
    return 0;
}