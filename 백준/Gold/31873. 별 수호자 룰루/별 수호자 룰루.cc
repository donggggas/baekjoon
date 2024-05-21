#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k,t = 1;
    cin >> n >> k;
    if(k == 1){
        cout << "NO";
        return 0;
    }
    if(n == k){
        if(n%2 == 0){
            cout << "YES\n";
            for(int i = 1; i <= n; i++) cout << i << ' ';
        }
        else cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<vector<ll>> v(n/k);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n/k; j++) v[j].push_back(t++);
    }
    ll sum = 0;
    for(int i = 0; i < k; i++) sum += v[0][i];
    if(sum%k){
        for(int i = 0; i < n/k; i++){
            for(int j = 0; j < k; j++) cout << v[i][j] << ' ';
            cout << '\n';
        }
        return 0;
    }
    for(int i = 0; i < n/k-1; i += 2) swap(v[i][0],v[i+1][0]);
    if(n/k%2) swap(v[n/k-1][0],v[n/k-2][0]);
    for(int i = 0; i < n/k; i++){
        for(int j = 0; j < k; j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
    return (0);
}