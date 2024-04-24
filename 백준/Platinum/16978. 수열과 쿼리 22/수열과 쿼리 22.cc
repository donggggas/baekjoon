#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree(400004),v(100001),res(100001);
vector<pair<pair<ll,ll>,pair<ll,ll>>> query;
queue<pair<ll,pair<ll,ll>>> of;
ll init(ll start,ll end,ll node){
    if(start == end) return tree[node] = v[start];
    ll mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2)+init(mid+1,end,node*2+1);
}
ll sum(ll start,ll end,ll left,ll right,ll node){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start+end)/2;
    return sum(start,mid,left,right,node*2)+sum(mid+1,end,left,right,node*2+1);
}
ll update(ll start,ll end,ll index,ll dif,ll node){
    if(index > end || index < start) return tree[node];
    if(start == end) return tree[node] = dif;
    ll mid = (start+end)/2;
    return tree[node] = update(start,mid,index,dif,node*2)+update(mid+1,end,index,dif,node*2+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,idx = 0,qcnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    init(1,n,1);
    cin >> m;
    while(m--){
        int a,b,c,d;
        cin >> a >> b >> c;
        if(a == 1) of.push({++idx,{b,c}});
        else{
            cin >> d;
            query.push_back({{b,qcnt++},{c,d}});
        }
    }
    sort(query.begin(),query.end());
    for(int i = 0; i < query.size(); i++){
        while(!of.empty() && of.front().first <= query[i].first.first){
            ll index = of.front().second.first;
            ll dif = of.front().second.second;
            of.pop();
            update(1,n,index,dif,1);
        }
        res[query[i].first.second] = sum(1,n,query[i].second.first,query[i].second.second,1);
    }
    for(int i = 0; i < qcnt; i++) cout << res[i] << '\n';
}