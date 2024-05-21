#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000030LL
int main(){
    cin.tie(0)->sync_with_stdio(0);

    priority_queue<pair<ll, ll>> job;
    priority_queue<tuple<ll, ll, ll>> wait;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        ll cost, dead;
        cin>>cost>>dead;
        job.push({-dead, cost});
    }
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        ll in, cost, dead;
        cin>>in>>cost>>dead;
        wait.push({-in, -dead, cost});
    }

    ll time = 0;
    ll nowDead, nowRemain;
    tie(nowDead, nowRemain) = job.top();
    job.pop();
    nowDead *= -1;

    while(true){
        ll jobCost = INF, jobDead = -INF;
        ll waitIn = -INF, waitCost = INF, waitDead = -INF;
        if(job.empty() && wait.empty()) break;
        if(!job.empty()) tie(jobDead, jobCost) = job.top();
        if(!wait.empty()) tie(waitIn, waitDead, waitCost) = wait.top();
        waitIn *= -1;
        waitDead *= -1;
        jobDead *= -1;
        if(!wait.empty() && time+nowRemain > waitIn){
            wait.pop();
            nowRemain -= waitIn - time;
            if(nowRemain > 0) job.push({-nowDead, nowRemain});
            job.push({-waitDead, waitCost});
            time = waitIn;
            tie(nowDead, nowRemain) = job.top();
            job.pop();
            nowDead *= -1;
        }else{
            time += nowRemain;
            if(time > nowDead){
                cout<<"NO\n";
                return 0;
            }
            if(job.empty()){
                wait.pop();
                time = waitIn;
                job.push({-waitDead, waitCost});
            }
            tie(nowDead, nowRemain) = job.top();
            job.pop();
            nowDead *= -1;
        }
    }
    
    if(time + nowRemain > nowDead){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<time + nowRemain<<'\n';
    
    return (0);
}