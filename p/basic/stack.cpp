string removeDuplicates(string s) {
        stack <char> st;
        int len = s.length();
        for(int i = 0; i<len; i++)
        {
            if (st.top() != s[i])
            {
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }