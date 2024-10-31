#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> parent(100001),sz(100001),depth(100001),C_num(100001),C_idx(100001),order(100001),rev(100001),dist(100001),tree(262145);
vector<vector<pair<int,int>>> v(100001);
vector<vector<int>> C(100001);
vector<pair<pair<int,int>,int>> edge(100001);
int cnt,n,m;
int init(int start,int end,int node){
	if(start == end) return tree[node] = dist[rev[start]];
	int mid = (start+end)/2;
	return tree[node] = max(init(start,mid,node*2),init(mid+1,end,node*2+1));
}

int mmax(int start,int end,int node,int left,int right){
	if(left > right || left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start+end)/2;
	return max(mmax(start,mid,node*2,left,right),mmax(mid+1,end,node*2+1,left,right));
}

int update(int start,int end,int node,int index,int dif){
	if(index < start || index > end) return tree[node];
	if(start == end) return tree[node] = dist[rev[index]] = dif;
	int mid = (start+end)/2;
	return tree[node] = max(update(start,mid,node*2,index,dif),update(mid+1,end,node*2+1,index,dif));
}

void dfs(int node, int par) {
    parent[node] = par;
    sz[node] = 1;
    for (auto [next,dis] : v[node]) {
        if (next != par) {
            dist[next] = dis;
            dfs(next, node);
            sz[node] += sz[next];
        }
    }
}

void HLD(int node, int par, int start, int dep) {
    depth[node] = dep;
    C_num[node] = start;
    C_idx[node] = C[start].size();
    C[start].push_back(node);

    order[node] = ++cnt;
    rev[cnt] = node;
    int heavy = -1;
    for (auto [next,dis] : v[node])
        if (next != par && (heavy == -1 || sz[next] > sz[heavy]))
        heavy = next;
    if (heavy != -1)
        HLD(heavy, node, start, dep);
    for (auto [next,dis] : v[node])
        if (next != par && next != heavy)
            HLD(next, node, next, dep + 1);
}

int lca(int a,int b){
    int res = 0;
    while(C_num[a] != C_num[b]){
        if(depth[a] < depth[b]) swap(a,b);
        res = max(res,mmax(1,n,1,order[C_num[a]],order[a]));
        a = parent[C_num[a]];
    }
    if(C_idx[a] > C_idx[b]) swap(a,b);
    return res = max(res,mmax(1,n,1,order[a]+1,order[b]));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        edge[i] = {{a,b},c};
    }
    dfs(1,0);
    HLD(1,0,1,0);
    init(1,n,1);
    cin >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1) update(1,n,1,parent[edge[b].first.first] == edge[b].first.second ? order[edge[b].first.first] : order[edge[b].first.second],c);
        else cout << lca(b,c) << '\n';
    }
}