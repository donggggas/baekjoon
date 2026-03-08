#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v(500001);
vector<ll> tree(2000004);
int n,m,k;
ll init(ll start,ll end,ll node){
	if(start == end) return tree[node] = v[start];
	ll mid = (start+end)/2;
	return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}
 
ll sum(ll start,ll end,ll node,ll left,ll right){
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	ll mid = (start+end)/2;
	return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}
 
ll update(ll start,ll end,ll node,ll index,ll dif){
	if(index < start || index > end) return tree[node];
	if(start == end) return tree[node] = v[index] = dif;
	ll mid = (start+end)/2;
	return tree[node] = update(start,mid,node*2,index,dif)+update(mid+1,end,node*2+1,index,dif);
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i];
	init(1,n,1);
    while(m--){
        ll a;
        cin >> a;
        cout << sum(1,n,1,1,a) << ' ';
        update(1,n,1,a,0);
    }
}