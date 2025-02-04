#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<bool> prime(1000001,true);
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(1000001); i++){
        if(prime[i]){
            for(int j = i+i; j <= 1000001; j += i) prime[j] = false;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n,res = 0;
        cin >> n;
        for(int i = 2; i < n; i++) res += (prime[n-i]+prime[i])/2;
        cout << (res+prime[n/2])/2 << '\n';
    }
}