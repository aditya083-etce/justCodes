#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;

    return false;
}

string prefix_to_postfix(string s){
    stack<string> st;
    int n = s.size();

    for(int i = n-1; i>=0; i--){
        if (isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string exp = op1 + op2 + s[i];
            st.push(exp);
        }else{
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string pre_exp; cin >> pre_exp;
    cout << "Postfix exp: "<< prefix_to_postfix(pre_exp) << endl;

    return 0;
}