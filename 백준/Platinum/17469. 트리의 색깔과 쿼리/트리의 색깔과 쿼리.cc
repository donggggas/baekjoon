#include <bits/stdc++.h>
using namespace std;
vector<int> parent(100001),p(100001);
vector<set<int>> color(100001);
set<int>::iterator iter;
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]); 
}
void merge(int x,int y){
    x = find(x),y = find(y);
    if(x == y) return;
    parent[x] = y;
    if(color[x].size() > color[y].size()){
        for(iter = color[y].begin(); iter != color[y].end(); iter++) color[x].insert(*iter);
        color[y].clear();
        swap(color[x],color[y]);
    }
    else{
        for(iter = color[x].begin(); iter != color[x].end(); iter++) color[y].insert(*iter);
        color[x].clear();
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    iota(parent.begin(),parent.end(),0);
    p[1] = 1;
    for(int i = 2; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        color[i].insert(a);
    }
    stack<pair<int,int>> query;
    stack<int> res;
    for(int i = 0; i < n+q-1; i++){
        int a,b;
        cin >> a >> b;
        query.push({a,b});
    }
    while(!query.empty()){
        int a = query.top().first;
        int b = query.top().second;
        query.pop();
        if(a == 1) merge(find(b),find(p[b]));
        else res.push(color[find(b)].size());
    }
    while(!res.empty()){
        cout << res.top() << '\n';
        res.pop();
    }
}