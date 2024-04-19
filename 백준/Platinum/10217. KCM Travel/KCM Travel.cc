#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,inf = 987654321,d[111][11111];
vector<vector<pair<int,pair<int,int>>>> v(11111);
void dij(){
    fill(&d[0][0],&d[110][11000],inf);
    d[1][0] = 0;
    queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{0,1}});
    while(!pq.empty()){
        int dis = -pq.front().first;
        int cos = pq.front().second.first;
        int cur = pq.front().second.second;
        pq.pop();
        if(d[cur][cos] < dis) continue;
        for(auto next : v[cur]){
            int ndis = dis+next.second.second;
            int ncos = cos+next.second.first;
            int nvtx = next.first;
            if(ncos > m) continue;
            if(d[nvtx][ncos] > ndis){
                pq.push({-ndis,{ncos,nvtx}});
                d[nvtx][ncos] = ndis;
            }
        }
    }
    int res = inf;
    for(int i = 0; i <= m; i++) res = min(res,d[n][i]);
    if(res == inf) cout << "Poor KCM";
    else cout << res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        v.clear();
        cin >> n >> m >> k;
        while(k--){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            v[a].push_back({b,{c,d}});
        }
        dij();
    }
}