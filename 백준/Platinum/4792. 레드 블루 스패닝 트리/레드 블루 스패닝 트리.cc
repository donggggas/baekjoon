#include <bits/stdc++.h>
using namespace std;
vector<int> parent(1001);
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x,int y){
    x = find(x),y = find(y);
    parent[y] = x;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        iota(parent.begin(),parent.end(),0);
        priority_queue<pair<int,pair<int,int>>> pq1,pq2;
        int n,m,k,cnt = 0,bmin = 0,bmax = 0;
        cin >> n >> m >> k;
        if(!n) return 0;
        while(m--){
            char a;
            int b,c;
            cin >> a >> b >> c;
            pq1.push({a=='B',{b,c}});
            pq2.push({a!='B',{b,c}});
        }
        while(cnt < n-1 && !pq1.empty()){
            int col = pq1.top().first;
            int va = pq1.top().second.first;
            int vb = pq1.top().second.second;
            pq1.pop();
            if(find(va) == find(vb)) continue;
            merge(va,vb);
            bmax += col;
            cnt++;
        }
        cnt = 0;
        iota(parent.begin(),parent.end(),0);
        while(cnt < n-1 && !pq2.empty()){
            int col = pq2.top().first;
            int va = pq2.top().second.first;
            int vb = pq2.top().second.second;
            pq2.pop();
            if(find(va) == find(vb)) continue;
            merge(va,vb);
            bmin += !col;
            cnt++;
        }
        cout << (bmin <= k && k <= bmax) << '\n';
    }
}