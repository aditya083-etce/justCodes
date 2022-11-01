#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n, q;
    cin>>n>>q;

    set<long long> bou;  // as insertion occurs sortedly
    bou.insert(0);
    bou.insert(n);

    while (q--)
    {
        int c;
        long long x;
        cin>>c>>x;
        if (c == 1)
        {
            bou.insert(x);
        }else{
            auto lower = bou.lower_bound(x);
            long long h = *lower;
            lower --;
            long long l = *lower;
            cout<<(h - l)<<endl;
        }
    }
    return 0;
}


/* 0 1 2 3 4 5              {0, 5}
1 2  2 me cut               {0, 2, 5}

1 4  4 me cut               {0, 2, 4, 5}

2 3  3 ka upperbound is 4 in set ager pechae a jau lower limit milega because only boundariers are
inserted in sorted manner

4 - 2 = 2 which is the length of wood where 3 is present */