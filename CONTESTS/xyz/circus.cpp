#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    string a, b;
    cin>>a>>b;

    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;

    for(int i = 0; i < n; i++){
        x1 += (a[i] == '0' and b[i] == '0');
        x2 += (a[i] == '0' and b[i] == '1');
        x3 += (a[i] == '1' and b[i] == '0');
        x4 += (a[i] == '1' and b[i] == '1');
    }

    bool flag = false;

    for (int i = 0; i <= x2; i++) {
        for(int j = 0; j <= x3; j++) {

            int len1 = i+j, len2 = x2 + x3 - i - j;

            if (len1 <= n/2 and len2 <= n/2)
            {
                int s1 = j, s2 = x2 - i, d = abs(s1- s2);
                if (x4>=d and (x4-d)%2 == 0)
                {
                    if (s1 <= s2){
                    }
                }
            }
        }
    }
    return 0;
}