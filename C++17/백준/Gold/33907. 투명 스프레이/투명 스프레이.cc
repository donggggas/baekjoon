#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n,m,k,res = -1;
  int board[777][777],dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> board[i][j];
  }
  int start = 0, end = 1e9;
  while(start <= end){
    int mid = (start+end)/2;
    int check[777][777];
    fill(&check[0][0],&check[770][770],-1);
    check[0][0] = 0;
    deque<tuple<int,int>> dq;
    dq.push_front({0,0});
    while(!dq.empty()){
      auto [x,y] = dq.front();
      dq.pop_front();
      if(x == n-1 && y == m-1) break;
      for(int i = 0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m){
          if(check[nx][ny] == -1){
            if(board[nx][ny] > mid){
              dq.push_back({nx,ny});
              check[nx][ny] = check[x][y]+1;
            } 
            else{
              dq.push_front({nx,ny});
              check[nx][ny] = check[x][y];
            }
          }
        }
      }
    }
    if(check[n-1][m-1] <= k){
      end = mid-1;
      res = mid;
    }
    else start = mid+1;
  }
  cout << res;
}