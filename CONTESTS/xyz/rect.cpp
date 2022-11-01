#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin>>n;
    set <pair<int,int>> points;

    for (int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        points.insert({x, y});
    }

    int count = 0;

    for(auto i = points.begin(); i!=points.end(); i++)
    {
        for(auto j = i + 1; j!=points.end(); j++)
        {
            pair<int,int> a = *i;
            pair<int,int> b = *j;

            if(a.first == b.first || a.second == b.second)
                continue;

            pair<int,int> c = {a.first, b.second};
            pair<int,int> d = {b.first, a.second};

            if (points.find(c) != points.end() && points.find(d) != points.end())
            {
                count++;
            }
        }
    }

    cout<<count<<endl;
    return 0;
}