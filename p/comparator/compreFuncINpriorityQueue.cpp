#include <bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(int &a, int &b){
        return a < b;
    }
};

int main() {
    
    int n;
    cin>>n;

    priority_queue<int, vector<int>, compare > pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}
