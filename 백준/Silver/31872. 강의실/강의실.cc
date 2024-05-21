#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k,res = 0;
    cin >> n >> k;
    vector<ll> v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++) pq.push(v[i+1]-v[i]);
    while(k--) pq.pop();
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout << res;
    return (0);
}