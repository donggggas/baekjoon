#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> tree(400004);
vector<pair<int,int>> v(100001);
pair<int,int> init(int start,int end,int node){
    if(start == end) return tree[node] = v[start];
    int mid = (start+end)/2;
    return tree[node] = min(init(start,mid,node*2),init(mid+1,end,node*2+1));
}
pair<int,int> minidx(int start,int end,int left,int right,int node){
    if(left > end || right < start) return {2020202020,0};
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return min(minidx(start,mid,left,right,node*2),minidx(mid+1,end,left,right,node*2+1));
}
pair<int,int> update(int start,int end,int index,pair<int,int> dif,int node){
    if(index < start || index > end) return tree[node];
    if(start == end){
        tree[node] = dif;
        return tree[node];
    }
    int mid = (start+end)/2;
    return tree[node] = min(update(start,mid,index,dif,node*2),update(mid+1,end,index,dif,node*2+1));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    init(1,n,1);
    cin >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1) update(1,n,b,{c,b},1);
        else cout << minidx(1,n,b,c,1).second << '\n';
    }
}