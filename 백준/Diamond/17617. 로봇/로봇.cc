#include <bits/stdc++.h>
using namespace std;
vector<int> v(1000001),dp(2000002);
int n,r,m,res,temp;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.begin()+n);
    v[n] = v[0]+m;
    for(int i = 0; i < n; i++) dp[i+n] = dp[i] = v[i+1]-v[i]-2*r;
    for(int i = 0; i < 2*n-1; i++){
        temp += dp[i];
        if(temp < 0) temp = 0;
        res = max(res,temp);
    }
    cout << (res+1)/2;
}