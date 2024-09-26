#include <bits/stdc++.h>
using namespace std;
int sum(string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9') res += s[i]-'0';
    }
    return res;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<pair<int,int>,string>> v(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        v[i] = {{s.size(),sum(s)},s};
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++) cout << v[i].second << '\n';
}