#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll c = (n+1)/2;
        ll res = c*c;
        ll s = n/3,p = 1;
        if(!s%2) s--;
        while(s > 0){
            c = (s+1)/2;
            res += c*c*p;
            s /= 3,p *= 2;
            if(!s%2) s--;
        }
        cout << res << '\n';
    }
}