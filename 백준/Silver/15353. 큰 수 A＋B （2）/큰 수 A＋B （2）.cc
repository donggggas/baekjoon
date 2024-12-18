#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a,b;
    cin >> a >> b;
    vector<int> v(10001);
    if(a.size() < b.size()) swap(a,b);
    int la = a.size(),lb = b.size();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i = 0; i < la-lb; i++) b.push_back('0');
    for(int i = 0; i < la; i++) v[i] = a[i]-'0'+b[i]-'0';
    for(int i = 0; i < la-1; i++){
        v[i+1] += v[i]/10;
        v[i] %= 10;
    }
    for(int i = la-1; i >= 0; i--) cout << v[i];
}