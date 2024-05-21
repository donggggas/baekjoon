#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dist[100][100];
ll N, M;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dist[i][j] = -98765432111111LL;
        }
    }
    
    for (int i = 0; i < M; i++) {
        ll u, v, d;
        cin >> u >> v >> d;
        dist[u][v] = max(dist[u][v], d);
    }
    ll res = -98765432111111LL;
    vector<int> perm(N);
    for (int i = 0; i < N; i++)
    {
        perm[i] = i + 1;
    }
    
    do{
        ll semi_res = dist[0][perm[0]];
        for (int i = 0; i < N - 1; i++) {
            semi_res += dist[perm[i]][perm[(i+1)]];
        }
        semi_res += dist[perm[N-1]][0];
        
        res = max(semi_res, res);
    }while(next_permutation(perm.begin(),perm.end()));
    if(res < 0){
        cout<<-1<<'\n';
    }else{
        cout << res<<'\n';
    }
    return (0);
}

/* 0 - 1 ~ N - 0*/