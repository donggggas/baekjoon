#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--){
        ll n,m,bu[5111],dif = 0;
        memset(bu,0,sizeof(bu));
        cin >> n >> m;
        while(m--){
            int a,b;
            cin >> a >> b;
            bu[a]++;
            bu[b]++;
        }
        for(int i = 1; i <= n; i++) dif += bu[i]*(n-1-bu[i]);
        cout << n*(n-1)*(n-2)/6-dif/2 << '\n';
    }
}