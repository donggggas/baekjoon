#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,c = 1,l = 1,len = 1;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 1; i < n; i++){
        if(v[i-1] <= v[i]) l++;
        else{
            c++;
            len = max(len,l);
            l = 1;
        }
    }
    len = max(l,len);
    cout << c << ' ' << len;
}