#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  string s1,s2,t1,t2;
  cin >> t1 >> t2;
  s1 = t1 + t2[1] + t2[0];
  s2 = t2 + t1[1] + t1[0];
  s1 += s1;
  s2 += s2;
  for(int i = 0; i < 4; i++){
    if(s1.substr(i,4) == "HEPC" || s2.substr(i,4) == "HEPC") return cout << "YES",0;
  }
  cout << "NO";
}