#include <bits/stdc++.h>
using namespace std;
vector<bool> check(5555);
vector<vector<int>> g(5555);
int n,m,k;
int dfs(int x){
    check[x] = true;
    int cnt = 1;
    for(int next : g[x]){
        if(!check[next]) cnt += dfs(next);
    }
    return cnt;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    while(m--){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(k--){
        int a;
        cin >> a;
        check[a] = true;
    }
    cout << dfs(1)-1;
}