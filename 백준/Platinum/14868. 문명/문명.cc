#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int n,k,cnt,res;
int check[2001][2001],own[2001][2001];
vector<int> par(100001);
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
    queue<pair<int,int>> q,tq;
    for(int i = 1; i <= k; i++){
        int x,y;
        cin >> x >> y;
        check[x][y] = i;
        q.push({x,y});
    }
    tq = q;
    while(cnt < k-1){
        while(!tq.empty()){
            auto [x,y] = tq.front();
            tq.pop();
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                    if(check[nx][ny] && find(check[nx][ny]) != find(check[x][y])){
                        merge(check[nx][ny],check[x][y]);
                        cnt++;
                    }
                }
            }
        }
        if(cnt == k-1) break;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                    if(!check[nx][ny]){
                        check[nx][ny] = check[x][y];
                        tq.push({nx,ny});
                    }
                }
            }
        }
        q = tq;
        res++;
    }
    cout << res;
}