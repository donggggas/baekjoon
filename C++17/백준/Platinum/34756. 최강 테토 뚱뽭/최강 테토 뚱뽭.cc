#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree(200002);
vector<int> val(200002),ps(200002);
vector<bool> check(200002),valid(200002);
vector<set<int>> sets(400004),unvalid(200002);
int cnt,n,res,pb = 0,off = 200000;
void dfs(int cur,int parent){
  ps[cur] = ps[parent]+val[cur];
  check[cur] = true;
  bool leaf = cur != 1 && tree[cur].size() == 1;
  if(leaf && val[cur] == 1) return;
  if(leaf && val[cur] == -1){
    for(auto i : sets[ps[cur]+1+off]) valid[i] = true;
    sets[ps[cur]+1+off].clear();
  }
  else{
    if(val[cur] == 1) sets[ps[cur]+off].insert(cur);
    else{
      if(unvalid[cur].size() < sets[ps[cur]+2+off].size()) swap(unvalid[cur],sets[ps[cur]+2+off]);
      for(auto i : sets[ps[cur]+2+off]) unvalid[cur].insert(i);
      sets[ps[cur]+2+off].clear();
    }
  }
  for(int next : tree[cur]){
    if(!check[next]) dfs(next,cur);
  }
  if(val[cur] == -1){
    if(unvalid[cur].size() > sets[ps[cur]+2+off].size()) swap(unvalid[cur],sets[ps[cur]+2+off]);
    for(auto i : unvalid[cur]) sets[ps[cur]+2+off].insert(i);
    unvalid[cur].clear();
  }
  else{
    if(sets[ps[cur]+off].find(cur) != sets[ps[cur]+off].end()) sets[ps[cur]+off].erase(cur);
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    int a;
    cin >> a;
    val[i] = a ? -1 : 1;
  }
  for(int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1,0);
  for(int i = 1; i <= n; i++) res += valid[i];
  cout << res;
}