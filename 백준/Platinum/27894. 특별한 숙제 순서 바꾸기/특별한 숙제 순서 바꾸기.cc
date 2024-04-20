#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vv(n),v(n);
    for(int i = 0; i < n; i++) cin >> vv[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n-2; i++){
        vector<int> t1(3),t2,t3;
        t1[0] = v[i];
        t1[1] = v[i+1];
        t1[2] = v[i+2];
        t2 = t1;
        sort(t2.begin(),t2.end());
        t3 = t2;
        reverse(t3.begin(),t3.end());
        if(vv == v || t1 == t2 || t1 == t3){
            cout << "POSSIBLE";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}