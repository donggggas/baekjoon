#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<tuple<string,int,int>> v(n);
  vector<bool> isprime(111111,true);
  isprime[0] = isprime[1] = false;
  vector<int> ps(111111);
  for(int i = 2; i*i < 111000; i++){
    if(isprime[i]){
      for(int j = i+i; j < 111000; j += i) isprime[j] = false;
    }
  }
  for(int i = 2; i < 111000; i++) ps[i] = ps[i-1]+isprime[i];
  for(int i = 0; i < n; i++){
    string s;
    long long t;
    cin >> s >> t;
    v[i] = {s,t/100000,t%100000};
  }
  string sa,sb;
  int aa = 987654321,bb = -1;
  for(int i = 0; i < n; i++){
    auto [s,a,b] = v[i];
    if(a > b) swap(a,b);
    int t = ps[b]-ps[a-1];
    if(t < aa){
      sa = s;
      aa = t;
    }
    else if(t == aa && sa > s) sa = s;
    if(t > bb){
      sb = s;
      bb = t;
    }
    else if(t == bb && sb > s) sb = s;
  }
  cout << sb << '\n' << sa;
}