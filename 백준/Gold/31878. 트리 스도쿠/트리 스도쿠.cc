#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> g[200000];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        mp[arr[i]] = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> check(n + 1);
    vector<int> ans(n+1);
    check[1] = 1;
    int cnt = 0;
    ans[1] = mp[arr[cnt++]];
    queue<int> bfsQ;
    bfsQ.push(1);
    while(!bfsQ.empty()){
        int now = bfsQ.front();
        bfsQ.pop();
        for (auto &&next : g[now])
        {
            if(check[next]==0){
                ans[next] = mp[arr[cnt++]];
                check[next] = 1;
                bfsQ.push(next);
            }
        }
    }
    cout<<"YES\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    
    return (0);
}