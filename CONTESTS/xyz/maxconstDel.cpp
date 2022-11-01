#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int t;
    cin>>t;
    long long n,a,b;
    while (t--)
    {
        cin>>n>>a>>b;
        string str;
        cin>>str;

        long long c = 1;
        for(long long i = 1; i<n; i++)
        {
            if (str[i] != str[i -1])
                c++;
        }

        if (b>=0)
        {
            cout<<(a*n + b*n)<<endl;
        }else{
            cout<<(a*n + (c/2 + 1)*b)<<endl;
        }
    }
    return 0;
}


/* al + b
Suppose u deleted in following length order:
{            }
 3  4   2   5  <-- length deleated  == total = 14  which is const in  whatever pattern is used in deletion.

 so al is const.
 sum = (a*3 + b) + (a*4 + b) + (a*2 + b) + (a*5 + b)
     = a(3 + 4 + 2 + 5) + b(4)
     = a (14) + b(4)
     = a(size of string) + b(no of operations)

Now,a and b can be + ve and - ve

sum = a(size of string) + b(no of operations)
            ^                       ^
      (this part is const)     Case 1: b is +ve
                                     sum = an + bn  (n is no of operation = size of string)
                                     because we have to maximize operation

                    Case 2: b is -ve 
                        we have to minimise no of operation
                        :-> if 1 is the first char delete all 0, grp all 1 then delete them.
                        :-> if 0 is the first char delete all 1,grp all 0 then delete them.
                        sum = an + b(c/2 + 1)

                        c -> changes btw adjacent

                        1 0 1 0 1
                        c = 5

            https://www.youtube.com/watch?v=Ut8NRAnb0NM
*/


