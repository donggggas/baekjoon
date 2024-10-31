#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> par(30001),parent(30001),sz(30001),depth(30001),C_num(30001),C_idx(30001),order(30001),rev(30001),pen(30001),tree(120004);
vector<vector<int>> v(30001);
vector<vector<int>> C(30001);
vector<tuple<string,int,int>> query(300001);
vector<bool> ok(300001);
int cnt,n,q;
int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x,int y){
    x = find(x),y = find(y);
    par[y] = x;
}

int init(int start,int end,int node){
	if(start == end) return tree[node] = pen[rev[start]];
	int mid = (start+end)/2;
	return tree[node] = init(start,mid,node*2)+init(mid+1,end,node*2+1);
}

int sum(int start,int end,int node,int left,int right){
	if(left > right || left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start+end)/2;
	return sum(start,mid,node*2,left,right)+sum(mid+1,end,node*2+1,left,right);
}

int update(int start,int end,int node,int index,int dif){
	if(index < start || index > end) return tree[node];
	if(start == end) return tree[node] = pen[rev[index]] = dif;
	int mid = (start+end)/2;
	return tree[node] = update(start,mid,node*2,index,dif)+update(mid+1,end,node*2+1,index,dif);
}

void dfs(int node, int par) {
    parent[node] = par;
    sz[node] = 1;
    for (int next : v[node]) {
        if (next != par) {
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
    for (int next : v[node])
        if (next != par && (heavy == -1 || sz[next] > sz[heavy]))
        heavy = next;
    if (heavy != -1)
        HLD(heavy, node, start, dep);
    for (int next : v[node])
        if (next != par && next != heavy)
            HLD(next, node, next, dep + 1);
}

int lca(int a,int b){
    int res = 0;
    while(C_num[a] != C_num[b]){
        if(depth[a] < depth[b]) swap(a,b);
        res += sum(1,n,1,order[C_num[a]],order[a]);
        a = parent[C_num[a]];
    }
    if(C_idx[a] > C_idx[b]) swap(a,b);
    return res + sum(1,n,1,order[a],order[b]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    iota(par.begin(),par.end(),0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> pen[i];
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        int a,b;
        cin >> s >> a >> b;
        query[i] = {s,a,b};
        if(s == "excursion") ok[i] = find(a) == find(b);
        else if(s == "bridge"){
            if(find(a) == find(b)) ok[i] = false;
            else{
                ok[i] = true;
                merge(a,b);
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!parent[i]){
            dfs(i,0);
            HLD(i,0,i,0);
        }
    }
    init(1,n,1);
    for(int i = 0; i < q; i++){
        auto [s,a,b] = query[i];
        if(s == "excursion"){
            if(ok[i]) cout << lca(a,b) << '\n';
            else cout << "impossible\n";
        }
        else if(s == "bridge") cout << (ok[i] ? "yes\n" : "no\n");
        else update(1,n,1,order[a],b);
    }
}