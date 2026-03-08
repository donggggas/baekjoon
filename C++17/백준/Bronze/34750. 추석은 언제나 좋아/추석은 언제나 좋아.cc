#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int a = n >= 1000000 ? n*0.2 : n >= 500000 ? n*0.15 : n >= 100000 ? n*0.1 : n*0.05;
  int b = n >= 1000000 ? n*0.8 : n >= 500000 ? n*0.85 : n >= 100000 ? n*0.9 : n*0.95;
  cout << a << ' ' << b;
}