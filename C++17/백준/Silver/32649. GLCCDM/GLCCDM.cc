#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> res;
    for(int i = a; i <= b; i += a){
        if(b%i == 0) res.push_back(i);
    }
    if(res.size() < k) cout << -1;
    else{
        for(int i = 0; i < k-1; i++) cout << res[i] << ' ';
        cout << b;
    }
}