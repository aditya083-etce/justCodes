#include<bits/stdc++.h>
using namespace std;

int gcd1(int a, int b) {
    if(a == 0 and b == 0) {
        return -1;
    } else if(a == 0 or b == 0) {
        return max(a, b);
    } else if(a == b) {
        return a;
    } else if(a > b) {
        if(a % b == 0) {
            return b;
        }
        return gcd(a - b, b);
    } else {
        if(b % a == 0) {
            return a;
        }
        return gcd(a, b - a);
    }
}

int gcd2(int a, int b) {
    if(a == 0 and b == 0) {
        return -1;
    } else if(a == 0 or b == 0) {
        return max(a, b);
    } else if(a == b) {
        return a;
    } else if(a > b) {
        return gcd(a % b, b);
    } else {
        return gcd(a, b % a);
    }
}

int gcd3(int a, int b) {
    if(a == 0 and b == 0) {
        return -1;
    } else if(a == 0 or a == b) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

//O(log base b n)
int gcd4(int a, int b) {
    if (b == 0) return a;
    return (b, a % b);
}

int lcm(int a, int b) {
    return (a*b) / gcd(a, b);
}


int main() {
    int a,b;
    cin>>a>>b;
    cout<<"GCD Algorithm 1: "<<gcd1(a,b)<<endl;
    cout<<"GCD Algorithm 2: "<<gcd1(a,b)<<endl;
    cout<<"GCD Algorithm 3: "<<gcd1(a,b)<<endl;
    cout<<"LCM: "<<lcm(a,b)<<endl;
    return 0;
}

// o(log(max(a,b)))