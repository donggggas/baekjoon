#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> check(111111,-1);
    vector<vector<int>> v(111111);
    int n,k,m;
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < k; j++){
            int t;
            cin >> t;
            v[n+i].push_back(t);
            v[t].push_back(n+i);
        }
    }
    check[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(int x : v[c]){
            if(check[x] == -1){
                check[x] = check[c]+(x > n);
                q.push(x);
            }
        }
    }
    cout << check[n];
}