#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    if(n == 1){
        cout << 0;
        return 0;
    }
    n--;
    for(int i = 0; i < n/2; i++,m ? m-- : 0) cout << min(1,m) << ' ';
    n -= n/2;
    int t = m/n,tt = m%n;
    for(int i = 0; i < n-tt; i++) cout << t << ' ';
    for(int i = 0; i < tt; i++) cout << t+1 << ' ';
    cout << 0;
}