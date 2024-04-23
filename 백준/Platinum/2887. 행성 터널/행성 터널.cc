#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<pair<ll,ll>,pair<ll,ll>>> pla(100001);
vector<ll> parent(100001);
bool comparex(pair<pair<ll,ll>,pair<ll,ll>> a,pair<pair<ll,ll>,pair<ll,ll>> b){
    return a.first.second < b.first.second;
} 
bool comparey(pair<pair<ll,ll>,pair<ll,ll>> a,pair<pair<ll,ll>,pair<ll,ll>> b){
    return a.second.first < b.second.first;
}
bool comparez(pair<pair<ll,ll>,pair<ll,ll>> a,pair<pair<ll,ll>,pair<ll,ll>> b){
    return a.second.second < b.second.second;
}
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
    ll n,res = 0,cnt = 0;
    cin >> n;
    iota(parent.begin(),parent.end(),0);
    priority_queue<pair<ll,pair<ll,ll>>> pq;
    for(ll i = 0; i < n; i++){
        cin >> pla[i].first.second >> pla[i].second.first >> pla[i].second.second;
        pla[i].first.first = i;
    } 
    sort(pla.begin(),pla.begin()+n,comparex);
    for(ll i = 0; i < n-1; i++) pq.push({-(abs(pla[i].first.second-pla[i+1].first.second)),{pla[i].first.first,pla[i+1].first.first}});
    sort(pla.begin(),pla.begin()+n,comparey);
    for(ll i = 0; i < n-1; i++) pq.push({-(abs(pla[i].second.first-pla[i+1].second.first)),{pla[i].first.first,pla[i+1].first.first}});
    sort(pla.begin(),pla.begin()+n,comparez);
    for(ll i = 0; i < n-1; i++) pq.push({-(abs(pla[i].second.second-pla[i+1].second.second)),{pla[i].first.first,pla[i+1].first.first}});
    while(!pq.empty() && cnt < n-1){
        ll dis = -pq.top().first;
        ll va = pq.top().second.first;
        ll vb = pq.top().second.second;
        pq.pop();
        if(find(va) == find(vb)) continue;
        merge(va,vb);
        res += dis;
        cnt++;
    }
    cout << res;
}