#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int t,k,x;
//     cin>>t;
//     while (t--)
//     {
//         cin>>k>>x;
//         int sum = 0;
//         int count = 0;
//         int s = 1;
//         while(s<k){
//             if (sum >= x){
//                 break;
//             }
//             sum += s;
//             s++;
//             count++;
//         }
//         while(s>0){
//             if (sum >= x){
//                 break;
//             }
//             sum += s;
//             s--;
//             count++;
//         }
//         cout<<count<<endl;
//     }
//     return 0;
// }

long long int required(long long int x, long long int k, long long int l) {

    if(l <= k) {

        return l * (l + 1) / 2;
    } else  {

        long long int rem = 2 * k - 1 - l;

        return k * k - rem * (rem + 1) / 2;
    }
}

long long int solve(long long int x, long long int k) {

    long long int low = 1, high = 2 * k - 1;

    while(low < high) {

        long long int mid = low + (high - low) / 2;

        long long int req = required(x, k, mid);

        if(req == x) {
            
            return mid;
        } else if(req < x) {

            low = mid + 1;
        } else {

            high = mid - 1;
        }
    }

    long long int req = required(x, k, low);

    if(req < x) {

        low++;
    }

    return min(low, 2 * k - 1);
}

int main() {
    
    int t;
    cin >> t;

    while(t--) {

        long long int k, x;
        cin >> k >> x;
        
        cout << solve(x, k) <<endl;
    }

    return 0;
}