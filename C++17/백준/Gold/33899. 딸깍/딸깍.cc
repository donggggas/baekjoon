#include <bits/stdc++.h>
using namespace std;
int board[1111][1111];
bool check[1111][1111];
int n,m;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
bool safe(int x,int y){
  return 0 <= x && x < n && 0 <= y && y < m;
}
bool on(int f,int t,int d){
  if(!f){
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return true;
  }
  else if(f == 1){
    if(!d) return false;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return false;
    else return false;
  }
  else if(f == 2){
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 2 && t != 3 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return t != 2;
  }
  else if(f == 3){
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return false;
  }
  else if(f == 4){
    if(!d) return false;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return false;
    else return t != 5 && t != 6;
  }
  else if(f == 5){
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 3 && t != 5 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return t != 6 && t != 5;
  }
  else if(f == 6){
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 3 && t != 4 && t != 5 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return true;
  }
  else if(f == 7){
    if(!d) return false;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return false;
  }
  else if(f == 8){
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return true;
  }
  else{
    if(!d) return t != 1 && t != 4;
    else if(d == 1) return t != 1 && t != 3 && t != 7;
    else if(d == 2) return t != 1 && t != 4 && t != 7;
    else return t != 5 && t != 6;
  }
}
int dfs(int x,int y){
  check[x][y] = true;
  int cnt = 1;
  for(int i = 0; i < 4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(safe(nx,ny) && !check[nx][ny] && on(board[x][y],board[nx][ny],i)) cnt += dfs(nx,ny);
  }
  return cnt;
}
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) scanf("%1d",&board[i][j]);
  }
  vector<string> res = {"NO","YES"};
  cout << res[dfs(0,0) == n*m];
}