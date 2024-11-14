#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,bot = 10001,top = -1,ans = 0;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int map[101][101] = {};
int bfs(int x,int y){
	int cnt = 0;
	queue<pair<int,int> > q;
	q.push({x,y});
	map[x][y] = bot;
	bool flag = true;
	while(!q.empty()){
		int f = q.front().first;
		int s = q.front().second;
		cnt++;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = f + dx[i];
			int ny = s + dy[i];
			if((nx == 0 || nx == n-1 || ny == 0 || ny == m-1) && map[nx][ny] < bot) flag = false;
			if(0 <= nx && nx < n && 0 <= ny && ny < m){
				if(map[nx][ny] < bot){
					q.push({nx,ny});
					map[nx][ny] = bot;
				}
			}
		}
	}
	return flag ? cnt : 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			bot = min(bot,map[i][j]);
			top = max(top,map[i][j]);
		}
	}
	while(bot < top){
		bot++;
		for(int i = 1; i < n-1; i++){
			for(int j = 1; j < m-1; j++){
				if(map[i][j] < bot) ans += bfs(i,j);
			}
		}
	}
	cout << ans;
}