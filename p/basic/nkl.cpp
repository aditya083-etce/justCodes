#include<bits\stdc++.h>
using namespace std;

int savemice()
{
    int n, k;
    cin>>n>>k;
    vector<int> micepos(k);
    for(int i = 0; i<k; i++)
    {
        cin>>micepos[i];
    }
    sort(micepos.begin(), micepos.end(), greater<int>());
    
    int catpos = 0;
    int saved = 0;
    for(int i = 0; i<k; i++)
    {
        if (catpos<micepos[i])
        {
            catpos = catpos + (n-micepos[i]);
            saved ++;
        }
        else{
            break;
        }
    }
    return saved;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<savemice()<<endl;
    }
    return 0;
}