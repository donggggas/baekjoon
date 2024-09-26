#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<string> v(n+m),res;
    for(int i = 0; i < n+m; i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i = 0; i < n+m-1; i++){
        if(v[i] == v[i+1]) res.push_back(v[i]);
    }
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++) cout << res[i] << '\n';
}