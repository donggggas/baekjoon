#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    vector<set<int>> v(500001);
    set<int>::iterator iter;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        while(a--){
            int b;
            cin >> b;
            v[i].insert(b);
        }
    }
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int b,c;
            cin >> b >> c;
            if(v[b].size() > v[c].size()){
                for(iter = v[c].begin(); iter != v[c].end(); iter++) v[b].insert(*iter);
                v[c].clear();
            }
            else{
                for(iter = v[b].begin(); iter != v[b].end(); iter++) v[c].insert(*iter);
                v[b].clear();
                swap(v[b],v[c]);
            }
        }
        else{
            int b;
            cin >> b;
            cout << v[b].size() << '\n';
        }
    }
}