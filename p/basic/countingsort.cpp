#include<bits/stdc++.h> 
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {

        arr[i] = 0;
    }

    for(int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    // Maximum value of arr[i] should be 10^7.
    // Minimum value of arr[i] should be -10^7.

    const int max = 1e7;
    
    // posCount will hold the frequency of the elements from 0 to max.
    // negCount will hold the frequency of the elements from -max to -1;
    int posCount[max + 1], negCount[max + 1];

		// Intialized the both arrays with 0.		
    memset(posCount, 0, sizeof posCount);
    memset(negCount, 0, sizeof negCount);

    for(int i = 0; i < n; i++) {
    
    		// Updating the frequency of arr[i] in posCount and negCount.
        if(arr[i] >= 0) {

            posCount[arr[i]]++;
        } else {

            negCount[-arr[i]]++;
        }
    }

    int j = 0;

    for(int i = max; i > 0; i--) {

        int cnt = negCount[i];

        while(cnt--) {

            arr[j++] = -i;
        }
    }

    for(int i = 0; i <= max; i++) {

        int cnt = posCount[i];

        while(cnt--) {

            arr[j++] = i;
        }
    }
    
    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }

    return 0;
}
