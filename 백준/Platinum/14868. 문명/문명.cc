#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int n,k;
int check[2001][2001],own[2001][2001];
vector<int> par(100001),res;
int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}
void merge(int x,int y){
    x = find(x),y = find(y);
    par[x] = y;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    iota(par.begin(),par.end(),0);
    fill(&check[0][0],&check[2000][2000],-1);
    queue<pair<int,int>> q,tq;
    for(int i = 1; i <= k; i++){
        int x,y;
        cin >> x >> y;
        check[x][y] = 0;
        own[x][y] = i;
        q.push({x,y});
    }
    tq = q;
    while(!tq.empty()){
        auto [x,y] = tq.front();
        tq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                if(own[nx][ny] && find(own[nx][ny]) != find(own[x][y])){
                    merge(own[nx][ny],own[x][y]);
                    res.push_back(max(check[nx][ny],check[x][y]));
                }
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                if(check[nx][ny] == -1){
                    check[nx][ny] = check[x][y]+1;
                    own[nx][ny] = find(own[x][y]);
                    q.push({nx,ny});
                }
                else if(find(own[nx][ny]) != find(own[x][y])){
                    merge(own[nx][ny],own[x][y]);
                    res.push_back(max(check[nx][ny],check[x][y]));
                }
            }
        }
    }
    sort(res.begin(),res.end());
    cout << res[k-2];
}