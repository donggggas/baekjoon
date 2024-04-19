#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        priority_queue<ll> pq;
        int n;
        ll res = 0;
        cin >> n;
        while(n--){
            int a;
            cin >> a;
            pq.push(-a);
        }
        while(pq.size() > 1){
            ll t1 = pq.top();
            pq.pop();
            ll t2 = pq.top();
            pq.pop();
            res += -(t1+t2);
            pq.push(t1+t2);
        }
        cout << res << '\n';
    }
}