#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    priority_queue<int> pq;
    while(n--){
        int a;
        cin >> a;
        if(pq.size() < k) pq.push(-a);
        else{
            if(-pq.top() < a){
                cout << -pq.top() << ' ';
                pq.pop();
                pq.push(-a);
            }
            else cout << a << ' ';
        }
    }
    while(!pq.empty()){
        cout << -pq.top() << ' ';
        pq.pop();
    }
}