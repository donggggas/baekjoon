#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v,tree(8000004),lazy(8000004);
void update_lazy(ll start,ll end,ll node){
    if(lazy[node]){
        tree[node] += (end-start+1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(ll start,ll end,ll left,ll right,ll dif,ll node){
    update_lazy(start,end,node);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        tree[node] += (end-start+1)*dif;
        if(start != end){
            lazy[node*2] += dif;
            lazy[node*2+1] += dif;
        }
        return;
    }
    ll mid = (start+end)/2;
    update(start,mid,left,right,dif,node*2);
    update(mid+1,end,left,right,dif,node*2+1);
    tree[node] = tree[node*2]+tree[node*2+1];
}
ll query(ll start,ll end,ll left,ll right,ll node){
    update_lazy(start,end,node);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start+end)/2;
    return query(start,mid,left,right,node*2)+query(mid+1,end,left,right,node*2+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        v.push_back(a);
        update(1,m,i,i,c,1);
    }
    while(1){
        ll a,b,c,d;
        cin >> a >> b >> c;
        b = upper_bound(v.begin(),v.end(),b)-v.begin();
        c = upper_bound(v.begin(),v.end(),c)-v.begin();
        if(!a) return 0;
        if(a == 1) cout << (b <= c ? query(1,m,b,c,1) : query(1,m,b,m,1)+query(1,m,1,c,1)) << '\n';
        else{
            cin >> d;
            if(b <= c) update(1,m,b,c,d,1);
            else{
                update(1,m,b,m,d,1);
                update(1,m,1,c,d,1);
            }
        }
    }
}