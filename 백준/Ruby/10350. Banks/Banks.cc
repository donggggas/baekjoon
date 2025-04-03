#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,res = 0;
    cin >> n;
    vector<ll> v(n+1),p(2*n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        p[i] = p[i-1]+v[i];
    }
    for(int i = n+1; i <= 2*n; i++) p[i] = p[i-1]+v[i-n];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n+i; j++){
            if(p[j]-p[i] < 0) res += ceil((double)(-p[j]+p[i])/p[n]);
        }
    }
    cout << res;
}