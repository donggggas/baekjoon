#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	vector<bool> prime(5000001,true);
	vector<int> prefix(5000001);
	prime[0] = false;
	for(int i = 2; i <= sqrt(5000000); i++){
		if(prime[i]){
			for(int j = i+i; j <= 5000000; j += i) prime[j] = false;
		}
	}
	for(int i = 1; i <= 5000000; i++) prefix[i] = prefix[i-1]+prime[i];
	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		cout << prefix[b]-prefix[a-1] << '\n';
	}
}