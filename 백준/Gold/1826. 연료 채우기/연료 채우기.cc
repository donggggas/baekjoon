#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,p,l,res = 0;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    cin >> p >> l;
    sort(v.begin(),v.end());
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++){
        if(l < v[i].first){
            while(!pq.empty() && l < v[i].first){
                l += pq.top();
                pq.pop();
                res++;
            }
            if(l < v[i].first){
                cout << -1;
                return 0;
            }
        }
        pq.push(v[i].second);
    }
    while(!pq.empty() && l < p){
        l += pq.top();
        pq.pop();
        res++;
    }
    cout << (l < p ? -1 : res);
}