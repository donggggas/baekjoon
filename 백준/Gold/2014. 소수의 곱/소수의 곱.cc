#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k,n,cnt,mm;
priority_queue<ll> pq;
vector<ll> v(111);
map<ll,bool> mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> v[i];
        pq.push(-v[i]);
        mp[v[i]] = true;
        mm = max(mm,v[i]);
    }
    while(!pq.empty()){
        ll cur = -pq.top();
        pq.pop();
        cnt++;
        if(cnt == n){
            cout << cur;
            return 0;
        }
        for(int i = 0; i < k; i++){
            ll t = cur*v[i];
            if(n < pq.size() && t > mm) continue;
            if(!mp[t]){
                mp[t] = true;
                pq.push(-t);
                mm = max(mm,t);
            }
        }
    }
}