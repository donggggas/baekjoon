#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> parent(100001);
ll find(ll x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(ll x,ll y){
    x = find(x),y = find(y);
    parent[y] = x;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,cnt = 0,res = 0;
    cin >> n >> m;
    priority_queue<pair<ll,pair<ll,ll>>> pq;
    iota(parent.begin(),parent.end(),0);
    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        pq.push({-c,{a,b}});
        res += c;
    }
    while(cnt < n-1 && !pq.empty()){
        int dis = -pq.top().first;
        int va = pq.top().second.first;
        int vb = pq.top().second.second;
        pq.pop();
        if(find(va) == find(vb)) continue;
        merge(va,vb);
        res -= dis;
        cnt++;
    }
    cout << (cnt == n-1 ? res : -1);
}