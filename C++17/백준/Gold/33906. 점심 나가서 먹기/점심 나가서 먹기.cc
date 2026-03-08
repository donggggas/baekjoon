#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> sik(111111),caf(111111);
vector<vector<tuple<ll,ll>>> v(111111);
ll INF = 1e18;
ll n,m,sik_num,caf_num,smin = 1e18,cmin = 1e18;
bool check[111111];
vector<ll> dist1(111111,INF),dist2(111111,INF);
int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> sik[i];
  for(int i = 1; i <= n; i++) cin >> caf[i];
  while(m--){
    ll a,b,c;
    cin >> a >> b >> c;
    v[a].push_back({b,c});
    v[b].push_back({a,c});
  }
  priority_queue<tuple<ll,ll>> pq1,pq2;
  pq1.push({0,1});
  dist1[1] = 0;
  while(!pq1.empty()){
    auto [dis,cur] = pq1.top();
    pq1.pop();
    dis *= -1;
    if(sik[cur] && smin > sik[cur]){
      sik_num = cur;
      smin = sik[cur];
    }
    if(caf[cur] && cmin > caf[cur]){
      caf_num = cur;
      cmin = caf[cur];
    }
    if(dist1[cur] < dis) continue;
    for(auto [next,next_dist] : v[cur]){
      ll ndis = dis+next_dist;
      if(ndis < dist1[next]){
        pq1.push({-ndis,next});
        dist1[next] = ndis;
      }
    }
  }
  pq2.push({0,sik_num});
  dist2[sik_num] = 0;
  while(!pq2.empty()){
    auto [dis,cur] = pq2.top();
    pq2.pop();
    dis *= -1;
    if(dist2[cur] < dis) continue;
    for(auto [next,next_dist] : v[cur]){
      ll ndis = dis+next_dist;
      if(ndis < dist2[next]){
        pq2.push({-ndis,next});
        dist2[next] = ndis;
      }
    }
  }
  cout << dist1[sik_num]+dist1[caf_num]+dist2[caf_num];
}