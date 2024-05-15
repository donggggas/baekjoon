#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll a[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
map<ll,ll> mp;
map<ll,ll>::iterator iter;
ll Power(__int128 x,__int128 y,__int128 mod){
    x %= mod;
    __int128 ret = 1;
    while(y > 0) {
        if(y%2 == 1) ret = (ret*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return (ll)ret;
}
bool checkPrime(ll n,ll a){
    if(a%n == 0) return true;
    ll k = n-1;
    while(1) {
        ll temp = Power(a,k,n);
        if(temp == n-1) return true;
        if(k%2 == 1) return (temp == 1 || temp == n-1);
        k /= 2;
    }
}
bool isPrime(ll n){
    if(n == 2 || n == 3) return true;
    if(n%2 == 0) return false;
    for(int i = 0; i < 12; i++)
        if(!checkPrime(n,a[i])) {
            return false;
            break;
        }
    return true;
}
ll gcd(ll a, ll b){
    return b ? gcd(b,a%b) : a;
}
ll findDiv(__int128 n){
    if(n%2 == 0) return 2;
    if(isPrime(n)) return n;
    __int128 x = rand()%(n-2) + 2, y = x, c = rand()%10 + 1, g = 1;
    while(g == 1) {
        x = (x*x%n + c)%n;
        y = (y*y%n + c)%n;
        y = (y*y%n + c)%n;
        g = gcd(x > y ? x-y : y-x,n);
        if(g == n) return findDiv(n);
    }
    if(isPrime(g)) return g;
    else return findDiv(g);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,res = 1;
    cin >> n;
    while(n > 1) {
        ll div = findDiv(n);
        n /= div;
        mp[div]++;
    }
    for(iter = mp.begin(); iter != mp.end(); iter++) res *= (ll)pow(iter->first,iter->second-1)*(iter->first-1);
    cout << res;
}