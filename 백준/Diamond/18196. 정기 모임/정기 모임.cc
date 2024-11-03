#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> parent(300001),sz(300001),depth(300001),C_num(300001),C_idx(300001),order(300001),rev(300001),dist(300001),tree(1200004),qv(300001),qtree(1200004);
vector<vector<pair<int,int>>> v(300001);
vector<vector<int>> C(300001);
int cnt,n,m;
int init(int start,int end,int node){
	if(start == end) return tree[node] = dist[rev[start]];
	int mid = (start+end)/2;
	return tree[node] = max(init(start,mid,node*2),init(mid+1,end,node*2+1));
}

int init2(int start,int end,int node){
    if(start == end) return qtree[node] = qv[start];
    int mid = (start+end)/2;
    return qtree[node] = max(init2(start,mid,node*2),init2(mid+1,end,node*2+1));
}

int mmax(int start,int end,int node,int left,int right){
	if(left > right || left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start+end)/2;
	return max(mmax(start,mid,node*2,left,right),mmax(mid+1,end,node*2+1,left,right));
}

int mmmax(int start,int end,int node,int left,int right){
	if(left > right || left > end || right < start) return 0;
	if(left <= start && end <= right) return qtree[node];
	int mid = (start+end)/2;
	return max(mmmax(start,mid,node*2,left,right),mmmax(mid+1,end,node*2+1,left,right));
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
    cin >> n >> m;
    for(int i = 1; i <= n-1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1,0);
    HLD(1,0,1,0);
    init(1,n,1);
    for(int i = 1; i < n; i++) qv[i] = lca(i,i+1);
    init2(1,n,1);
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << mmmax(1,n,1,a,b-1) << '\n';
    }
}