#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;

    return false;
}

string postfix_to_prefix(string s){
    stack<string> st;
    int n = s.size();

    for(int i = 0; i<n; i++){
        if (isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string exp = s[i] + op2 + op1;
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

    string post_exp; cin >> post_exp;
    cout << "Prefix exp: "<< postfix_to_prefix(post_exp) << endl;

    return 0;
}