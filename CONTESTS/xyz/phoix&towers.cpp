#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x;
        int h[n];
        for(int i = 0; i<n; i++){
            cin>>h[i];
        }

        set< pair<int,int> > st, st1;
        
        for(int i = 0; i<n; i++){
            st.insert({h[i], i});
        }

        int rem = n - m;
        while (rem--)
        {
            pair<int,int> temp = *(st.begin());
            st.erase(st.begin());
            st1.insert(temp);
        }
        // m highest blocks in set st;
        // all others in st1;
        int res[n];
        int c = 1;
        for(auto i: st){
            res[i.second] = c++;
        }
        
        for(auto i = st1.rbegin(); i != st1.rend(); i--)
        {
            pair<int,int> temp = *(st.begin());
            st.erase(st.begin()); // minimum

            res[(*i).second] = res[temp.second];

            st.insert({temp.first + (*i).first, temp.second});
        }

        auto it = st.end();
        it--;
        if (it->first - (*st.begin()).first  > x)
        {
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i = 0; i<n; i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}