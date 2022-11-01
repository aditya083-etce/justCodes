#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<< "People are standing in a circle each one has a sword. 1st kills the next person (i.e., no. 2) and gives the sword to the next (i.e., no. 3)."<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    int n;
    cout << "Enter how many people    : ";
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    int pos = 0;
    while (p.size() > 1)
    {
        pos = (pos + 1) % p.size();
        p.erase(p.begin() + pos);
    }

    cout<<"The one who will survive: "<<p[0]<<endl;
    return 0;
}