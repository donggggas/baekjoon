#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,res = 0;
    cin >> n;
    vector<int> v(100);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) res += v[i]-min(v[i],v[i-1])+1;
    cout << res+v[0];
}