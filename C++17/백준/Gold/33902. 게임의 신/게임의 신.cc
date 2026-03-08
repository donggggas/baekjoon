#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  return b ? gcd(b,a%b) : a;
}
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int dp[1111] = {};
  fill(dp,dp+1100,true);
  int x,y;
  cin >> x >> y;
  for(int i = y; i >= x; i--){
    for(int j = i; j <= y; j++){
      if(gcd(i,j) == 1) dp[i] &= !dp[j];
    }
  }
  string res[2] = {"khj20006","putdata"};
  cout << res[dp[x]];
}