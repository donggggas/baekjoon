#include <bits/stdc++.h>
using namespace std;
int dist[1111][33333],n,m,k,s,d,res,INF = 987654321,tax;
vector<vector<pair<int,int>>> v(1111);
priority_queue<pair<int,pair<int,int>>> pq;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> s >> d;
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    fill(&dist[0][0],&dist[1100][33330],INF);
    dist[s][0] = 0;
    pq.push({0,{0,s}});
    while(!pq.empty()){
        int dis = -pq.top().first;
        int cnt = -pq.top().second.first;
        int cur = pq.top().second.second;
        pq.pop();
        if(dis > dist[cur][cnt] || cnt > n) continue;
        for(auto next : v[cur]){
            int ndis = dis+next.second;
            int ncur = next.first;
            if(ndis < dist[ncur][cnt+1]){
                if(ncur != d) pq.push({-ndis,{-cnt-1,ncur}});
                dist[ncur][cnt+1] = ndis;
            }
        }
    }
    res = INF;
    int cnt;
    for(int i = 1; i < 33000; i++){
        if(res > dist[d][i]){
            res = dist[d][i];
            cnt = i;
        }
    }
    cout << res << '\n';
    while(k--){
        int a,t = INF;
        cin >> a;
        tax += a;
        for(int i = cnt; i >= 0; i--){
            if(t > dist[d][i]+tax*i){
                t = dist[d][i]+tax*i;
                cnt = i;
            }
        }
        cout << t << '\n';
    }
}