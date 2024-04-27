#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree(400004),v(100001);
map<string,ll> mp;
ll n;
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
    while(1){
        ll res = 0;
        cin >> n;
        if(!n) return 0;
        tree.clear();
        tree.resize(400004);
        mp.clear();
        v.clear();
        v.resize(100001);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            mp[s] = i;
        }
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v[mp[s]] = i;
        }
        for(int i = 0; i < n; i++){
            int p = v[i];
            res += query(0,n-1,p+1,n-1,1);
            update(0,n-1,p,1);
        }
        cout << res << '\n';
    }
}