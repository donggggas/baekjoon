#include <iostream>
#include <queue>
using namespace std;
int n,INF = 200000000;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int map[150][150],d[150][150];
int dijkstra(int x,int y){
	priority_queue<pair<int,pair<int,int> > > pq;
	pq.push({-d[x][y],{0,0}});
	while(!pq.empty()){
		int dis = -pq.top().first;
		int f = pq.top().second.first;
		int s = pq.top().second.second;
		pq.pop();
		for(int i = 0; i < 4; i++){
			int nx = f + dx[i];
			int ny = s + dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < n){
				int ndis = dis + map[nx][ny];
				if(d[nx][ny] > ndis){
					d[nx][ny] = ndis;
					pq.push({-ndis,{nx,ny}});
				}
			}
		}
	}
	return d[n-1][n-1];
}

int main(){
	int t = 1;
	while(1){
		cin >> n;
		if(n == 0) return 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> map[i][j];
				d[i][j] = INF;
			}
		}
		d[0][0] = map[0][0];
		cout << "Problem " << t++ << ": " << dijkstra(0,0) << '\n';
	}
}