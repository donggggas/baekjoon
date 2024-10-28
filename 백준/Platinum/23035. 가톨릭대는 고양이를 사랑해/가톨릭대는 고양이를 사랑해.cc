#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
    vector<pair<ll,ll>> cat;
    vector<ll> dp;
    for(int i = 0; i < t; i++){
        ll x,y;
        cin >> x >> y;
        if(0 <= x && x <= n && 0 <= y && y <= m) cat.push_back({x,y});
    } 
    sort(cat.begin(),cat.end());
	for(int i = 0; i < cat.size(); i++){
        ll x = cat[i].second;
        auto pos = upper_bound(dp.begin(),dp.end(),x);
        if(pos == dp.end()) dp.push_back(x);
        else if(dp[dp.size()-1] <= x) dp.push_back(x);
        else *pos = x;
    }
    cout << dp.size();
}