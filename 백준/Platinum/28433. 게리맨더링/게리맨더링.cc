#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll m = 0,p = 0,sum = 0;
        while(n--){
            ll a;
            cin >> a;
            if(a > 0){
                if(sum < 0){
                    if(sum+a > 0) sum += a;
                    else{
                        m++;
                        sum = a;
                    }
                }
                else sum = a;
                p++;
            }
            else if(!a){
                if(!n && sum < 0) m++;
            }
            else{
                if(sum < 0) sum += a;
                else{
                    if(sum+a > 0) sum += a;
                    else sum = a;
                }
                if(!n && sum < 0) m++;
            }
        }
        cout << (p > m ? "YES\n" : "NO\n");
    }
}