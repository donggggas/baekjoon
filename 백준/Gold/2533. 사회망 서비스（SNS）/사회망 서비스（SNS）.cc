#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree(1000001);
vector<bool> sns(1000001),check(1000001);
int n,res;
void dfs(int x,int prev){
    check[x] = true;
    for(int next : tree[x]){
        if(!check[next]) dfs(next,x);
    }
    if(!sns[x]) sns[prev] = true;
}
int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i++) res += sns[i];
    cout << res;
}