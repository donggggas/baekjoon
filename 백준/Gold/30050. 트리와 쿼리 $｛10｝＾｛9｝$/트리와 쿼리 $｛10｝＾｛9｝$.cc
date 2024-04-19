#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    map<ll,ll> mp;
    while(q--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1) mp[c] = b;
        else{
            ll res = 0;
            while(b != c){
                if(b > c) swap(b,c);
                res += c;
                if(mp.find(c) == mp.end()) c /= 2;
                else c = mp[c];
            }
            cout << res+b << '\n';
        }
    }
}