#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n;
    int sq = sqrt(n);
    vector<int> v(n+1),parse;
    vector<vector<int>> vv;
    for(int i = 1; i <= n; i += sq) parse.push_back(i);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 0; i < parse.size(); i++){
        vector<int> t;
        int idx = 0;
        for(int j = parse[i]; j < min(parse[i]+sq,n+1); j++) t.push_back(v[j]);
        sort(t.begin(),t.end());
        vv.push_back(t);
    }
    cin >> m;
    while(m--){
        int a,b,c,d;
        cin >> a >> b >> c;
        if(a == 1){
            cin >> d;
            int cnt = 0;
            int s = (b-1)/sq;
            int e = (c-1)/sq;
            if(c-b < sq){
                for(int i = b; i <= c; i++) cnt += v[i] > d;
            }
            else{
                for(int i = b; i < parse[s+1]; i++) cnt += v[i] > d;
                for(int i = parse[e]; i <= c; i++) cnt += v[i] > d;
                for(int i = s+1; i < e; i++) cnt += vv[i].size()-(upper_bound(vv[i].begin(),vv[i].end(),d)-vv[i].begin());
            }
            cout << cnt << '\n';
        }
        else{
            int t = v[b];
            v[b] = c;
            int s = (b-1)/sq;
            int idx = 0;
            vv[s][lower_bound(vv[s].begin(),vv[s].end(),t)-vv[s].begin()] = c;
            sort(vv[s].begin(),vv[s].end());
        }
    }
}