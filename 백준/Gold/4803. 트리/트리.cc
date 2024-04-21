#include <bits/stdc++.h>
using namespace std;
vector<int> parent(501);
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x,int y){
    x = find(x),y = find(y);
    if(x == y) return;
    parent[y] = x;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 1;
    while(1){
        vector<bool> check(501,true);
        int n,m;
        cin >> n >> m;
        if(!n) return 0;
        iota(parent.begin(),parent.end(),0);
        set<int> st;
        while(m--){
            int a,b;
            cin >> a >> b;
            if(find(a) == find(b)){
                check[find(a)] = false;
                check[find(b)] = false;
            }
            else if(!check[find(a)] || !check[find(b)]){
                check[find(a)] = false;
                check[find(b)] = false;
            }
            merge(a,b);
        }
        for(int i = 1; i <= n; i++){
            if(check[find(i)]) st.insert(find(i));
        }
        if(st.empty()) cout << "Case " << cnt++ << ": No trees.\n";
        else if(st.size() == 1) cout << "Case " << cnt++ << ": There is one tree.\n";
        else cout << "Case " << cnt++ << ": A forest of " << st.size() << " trees.\n";
    }
}