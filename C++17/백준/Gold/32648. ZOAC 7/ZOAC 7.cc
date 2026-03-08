#include <bits/stdc++.h>
using namespace std;
int n,m;
char board[2002][2002];
int dp[2002][2002][4],bdp[2002][2002][4];
int dx[2] = {0,1},dy[2] = {1,0};
int bdx[2] = {0,-1},bdy[2] = {-1,0};
char zoac[4] = {'Z','O','A','C'};
int res[4];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> board[i][j];
	}
	for(int i = 0; i < 4; i++){
		dp[1][1][i] += board[1][1] == zoac[i];
		bdp[n][m][i] += board[n][m] == zoac[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 0; k < 2; k++){
				int nx = i+dx[k],ny = j+dy[k];
				for(int l = 0; l < 4; l++) dp[nx][ny][l] = max(dp[nx][ny][l],dp[i][j][l]+(board[nx][ny] == zoac[l]));
			}
		}
	}
	for(int i = n; i; i--){
		for(int j = m; j; j--){
			for(int k = 0; k < 2; k++){
				int nx = i+bdx[k],ny = j+bdy[k];
				for(int l = 0; l < 4; l++) bdp[nx][ny][l] = max(bdp[nx][ny][l],bdp[i][j][l]+(board[nx][ny] == zoac[l]));
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 0; k < 4; k++) res[k] = max(res[k],dp[i][j][k]+max(bdp[i+1][1][k],bdp[1][j+1][k]));
		}
	}
	for(int i : res) cout << i << ' ';
}