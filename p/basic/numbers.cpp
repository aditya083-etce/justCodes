#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> numbers { { "zero", 0 }, { "one", 1}, { "two", 2 },{ "three", 3}, { "four", 4 },{ "five", 5}, { "six", 6 },{ "seven", 7}, { "eight", 8 }, { "nine", 9} };

void solve(string s)
{
    vector<string> w;
    string temp = "";
    for(char c: s){
        if(c == ' '){
            w.push_back(temp);
            temp = "";
        }else{
            temp += c;
        }
    }

    long long int ans = 0;
    
    string word = "";
    for(int i = 0; i<w.size(); i++)
    {
        word = w[i];
        if(word == "double"){
            int d = numbers[w[i+]];
            int k = 1;
            while(k--){
                ans = ans*10 + d;
            }
        }else if(word == "triple"){
            int t = numbers[w[i+1]];
            int j = 2;
            while(j--){
                ans += ans*10 + t;
            }
        }else{
            ans = ans*10 + numbers[word];
        }
    }
    cout<<ans<<" ";
}
int main() {
    string s;
    getline(cin,s);
    solve(s);
    return 0;
}
