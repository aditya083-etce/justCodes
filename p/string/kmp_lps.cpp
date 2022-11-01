#include<bits/stdc++.h>
using namespace std;

// S is main text.
// P is pattern.


// It will fill the LPS vector.
void preprocess(string &P, vector<int> &LPS) {

    LPS[0] = 0;

    int i = 1, len = 0, N = P.size();

    // len will store the length of the LPS in string P[0, i].

    while(i < N) {

        if(P[i] == P[len]) {

            LPS[i] = len + 1;

            len++;
            i++;
        } else {

            if(len == 0) {

                LPS[i] = 0;
                i++;
            } else {

                len = LPS[len - 1];
            }
        }
    }
}

void findPattern(string &S, string &P) {

    int M = S.size(), N = P.size();

    vector<int> LPS(N);

    preprocess(P, LPS);

    cout << "LPS OF PATTERN : ";
    for(int i: LPS){
        cout << i << " ";
    }
    cout << endl;

    int i = 0, j = 0;
    // i for S, j for P.

    while(i < M) {

        if(S[i] == P[j]) {

            i++;
            j++;
        }

        if(j == N) {

            cout << "Pattern found at index "<< i - N;

            j = LPS[N - 1];
        } else if(i < M and S[i] != P[j]) {

            if(j == 0) {

                i++;
            } else {

                j = LPS[j - 1];
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string S, P;
    cin >> S >> P;

    findPattern(S, P);

    return 0;
}