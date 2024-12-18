#include <bits/stdc++.h>
using namespace std;
vector<int> parent(1001);
int n,m,res;
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x,int y){
    x = find(x),y = find(y);
    parent[y] = x;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    iota(parent.begin(),parent.end(),0);
    priority_queue<tuple<int,int,int>> pq;
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({-c,a,b});
    }
    while(!pq.empty()){
        auto [dis,va,vb] = pq.top();
        pq.pop();
        if(find(va) == find(vb)) continue;
        merge(va,vb);
        res += -dis;
    }
    cout << res;
}