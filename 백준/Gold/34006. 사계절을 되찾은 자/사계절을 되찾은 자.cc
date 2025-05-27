#include <bits/stdc++.h>
using namespace std;
int check[2222][2222];
tuple<int,int,char> back[2222][2222];
int n,A,B,C,a,b,c;
queue<tuple<int,int>> q;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> A >> B >> C >> a >> b >> c;
    q.push({A,B});
    fill(&check[0][0],&check[2220][2220],-1);
    check[A][B] = 0;
    while(!q.empty()){
        auto [aa,bb] = q.front();
        q.pop();
        if(aa+a < 2*n && 3*n-aa-bb-a > 0 && check[aa+a][bb] == -1){
            q.push({aa+a,bb});
            check[aa+a][bb] = check[aa][bb]+1;
            back[aa+a][bb] = {aa,bb,'A'};
        }
        if(aa-b > 0 && bb+b < 2*n && check[aa-b][bb+b] == -1){
            q.push({aa-b,bb+b});
            check[aa-b][bb+b] = check[aa][bb]+1;
            back[aa-b][bb+b] = {aa,bb,'B'};
        }
        if(3*n-aa-bb+c < 2*n && bb-c > 0 && check[aa][bb-c] == -1){
            q.push({aa,bb-c});
            check[aa][bb-c] = check[aa][bb]+1;
            back[aa][bb-c] = {aa,bb,'C'};
        }
    }
    string res = "";
    cout << check[n][n] << '\n';
    if(check[n][n] != -1){
        int x = n,y = n;
        while(1){
            auto [xx,yy,cc] = back[x][y];
            res.push_back(cc);
            if(xx == A && yy == B) break;
            x = xx,y = yy;
        }
        reverse(res.begin(),res.end());
        cout << res;
    }
}