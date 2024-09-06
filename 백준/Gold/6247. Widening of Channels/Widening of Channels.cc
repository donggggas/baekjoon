#include <bits/stdc++.h>
using namespace std;
vector<int> parent(1001);
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
    priority_queue<pair<int,pair<int,int>>> pq;
    iota(parent.begin(),parent.end(),0);
    int n,m,res = 0,k,cnt = 0;
    cin >> n >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({c,{a,b}});
    }
    cin >> k;
    while(cnt < n-1 && !pq.empty()){
        int dis = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(find(x) == find(y)) continue;
        merge(x,y);
        cnt++;
        if(dis < k) res++;
    }
    cout << res;
}