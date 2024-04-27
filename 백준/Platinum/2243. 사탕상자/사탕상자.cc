#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree(4000001),can(1000001);
ll update(ll start,ll end,ll index,ll dif,ll node){
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = dif;
    ll mid = (start+end)/2;
    return tree[node] = update(start,mid,index,dif,node*2)+update(mid+1,end,index,dif,node*2+1);
}
ll query(ll start,ll end,ll target,ll node){
    if(start == end) return start;
    ll mid = (start+end)/2;
    if(tree[node*2] >= target) return query(start,mid,target,node*2);
    else return query(mid+1,end,target-tree[node*2],node*2+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    while(n--){
        ll a,b,c;
        cin >> a >> b;
        if(a == 1){
			ll p = query(1,1000000,b,1);
            cout << p << '\n';
            update(1,1000000,p,--can[p],1);
        }
        else{
            cin >> c;
			can[b] += c;
            update(1,1000000,b,can[b],1);
        }
    }
}