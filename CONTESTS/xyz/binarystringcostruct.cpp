#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int a, b, x;
    cin>>a>>b>>x;
    int flag;
    if(a>=b){
        flag = 0;
    }
    else{
     flag = 1;
    }

    while(x>0)
    {
        if(x==1)
        {
            if(flag)
            {
                for(int i=0;i<b;i++) 
                {
                    cout<<"1";
                }
                for(int i=0;i<a;i++)
                {
                    cout<<"0";
                } 
            }
            else
            {
                for(int i=0;i<a;i++)
                {
                    cout<<"0";
                }
                for(int i=0;i<b;i++)
                {
                    cout<<"1";
                }
            }
        }
        else
        {
            cout<<flag;
            if(flag)
            {
                b--;
                flag = 0;
            }
            else
            {
                a--;
                flag = 1;
            }
        }
        x--;
    }
    cout<<endl;
    return 0;
 }

 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     
    return 0;
 }