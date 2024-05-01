#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n,blue[1111],dif = 0;
        cin >> n;
        memset(blue,0,sizeof(blue));
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int a;
                cin >> a;
                blue[i] += a;
                blue[j] += a;
            }
        }
        for(int i = 0; i < n; i++) dif += blue[i]*(n-1-blue[i]);
        cout << n*(n-1)*(n-2)/6-dif/2 << '\n';
    }
}