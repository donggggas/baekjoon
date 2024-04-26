#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree(4000001);
ll n,res;
ll update(ll start,ll end,ll index,ll node){
    if(start > index || end < index) return tree[node];
    if(start == end) return tree[node] += 1;
    ll mid = (start+end)/2;
    return tree[node] = update(start,mid,index,node*2)+update(mid+1,end,index,node*2+1);
}
ll query(ll start,ll end,ll left,ll right,ll node){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start+end)/2;
    return query(start,mid,left,right,node*2)+query(mid+1,end,left,right,node*2+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        res += query(1,n,a,n,1);
        update(1,n,a,1);
    }
    cout << res;
}