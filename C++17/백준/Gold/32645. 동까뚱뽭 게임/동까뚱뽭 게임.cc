#include <bits/stdc++.h>
using namespace std;int n,u,v,w[111111],i,c[111111];vector<vector<int>> g(111111);string r[2]={"uppercut","donggggas"};
void dfs(int x,int y){c[x]=1;for(int t:g[x])if(!c[t])dfs(t,x);w[y]|=!w[x];}
int main(){cin>>n;for(i=0;i<n;i++){cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}dfs(1,0);for(i=1;i<=n;i++){cout<<r[w[i]]<<'\n';}}