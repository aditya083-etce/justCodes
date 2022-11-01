#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> &points) {
    int cnt = 0;
    
    set<pair<int, int>> cor;
    for(auto p: points) cor.insert(p);

    for(auto p1: points) {
        for(auto p2: points) {
            if (p1.first != p2.first and p1.second != p2.second) {
                if (cor.find({p1.first, p2.second}) != cor.end() and cor.find({p2.first, p1.second}) != cor.end()) cnt++;
            }
        }
    }
    return cnt / 4;
}
int main() {
    int n; cin >> n;

    vector<pair<int, int>> points(n);

    for(int i=0; i<n; i++){
        cin >> points[i].first;
        cin >> points[i].second;
    }

    cout << "HOW MANY RECTANGLES CAN BE FORMED FROM GIVEN SET OF POINTS: " << solve(points) << endl;

    return 0;
}
