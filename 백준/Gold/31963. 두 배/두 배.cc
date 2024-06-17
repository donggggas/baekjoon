#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,res = 0;
    vector<long double> v(250001);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i] = log2l(v[i]);
    }
    for(int i = 1; i < n; i++){
        if(v[i-1] <= v[i]) continue;
        if(abs((v[i-1]-v[i])-(ll)(v[i-1]-v[i])) < 1e-8) res--,v[i]--;
        res += (ll)ceill(v[i-1]-v[i]);
        v[i] += (ll)ceill(v[i-1]-v[i]);
    }
    cout << res;
}