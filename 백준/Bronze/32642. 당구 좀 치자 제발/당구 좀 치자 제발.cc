#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll n,cur = 0,res = 0;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		cur += t ? 1 : -1;
		res += cur;
	}
	cout << res;
}