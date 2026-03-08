#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,qr;
int board[101][101],broke[101][101][101];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int INF = 987654321;
int res[101][101];
pair<int, int> mp[101][101];
bool safe(int x,int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> t >> qr;
    fill(&broke[0][0][0],&broke[100][100][100],INF);
    fill(&mp[0][0],&mp[100][100],make_pair(-1,-1));
    fill(&res[0][0],&res[100][100],INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> board[i][j];
    }
    while(k--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        mp[a-1][b-1] = {c-1,d-1};
    }
    priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
    pq.push({{0,0},{0,0}});
    broke[0][0][0] = 0;
    res[0][0] = 0;
    while(!pq.empty()){
        int dis = -pq.top().first.first;
        int tel = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(dis > broke[tel][x][y]) continue;
        int tx = mp[x][y].first;
        int ty = mp[x][y].second;
        if(tel < t && tx > -1 && ty > -1){
            if(broke[tel+1][tx][ty] > dis){
                broke[tel+1][tx][ty] = dis;
                pq.push({{-dis,tel+1},{tx,ty}});
                res[tx][ty] = min(res[tx][ty],dis);
            }
        }
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(safe(nx,ny)){
                int ndis = dis+board[nx][ny];
                if(broke[tel][nx][ny] > ndis){
                	broke[tel][nx][ny] = ndis;
                	pq.push({{-dis-board[nx][ny],tel},{nx,ny}});
                	res[nx][ny] = min(res[nx][ny],ndis);
                }
            }
        }
    }
    while(qr--){
        int power,x,y;
        cin >> power >> x >> y;
        cout << (res[x-1][y-1] <= power) << '\n';
    }
}