#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> parent(100001),v(100001,1),check(100001,1);
vector<pair<ll,ll>> mer(100001);
stack<ll> st;
ll n,m,q,res;
ll find(ll x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(ll x,ll y){
    x = find(x),y = find(y);
    if(x == y) return;
    v[x] += v[y];
    v[y] = 0;
    parent[y] = x;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    iota(parent.begin(),parent.end(),0);
    for(int i = 1; i <= m; i++) cin >> mer[i].first >> mer[i].second;
    while(q--){
        ll a;
        cin >> a;
        check[a] = false;
        st.push(a);
    }
    for(int i = 1; i <= m; i++) if(check[i]) merge(mer[i].first,mer[i].second);
    while(!st.empty()){
        ll cur = st.top();
        st.pop();
        if(find(mer[cur].first) == find(mer[cur].second)) continue;
        res += v[find(mer[cur].first)]*v[find(mer[cur].second)];
        merge(mer[cur].first,mer[cur].second);
    }
    cout << res;
}