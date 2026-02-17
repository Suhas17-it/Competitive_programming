#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m , k;
    cin >> n >> m >>k;

    vector<vector<pair<int,long long>>> adj(n + 1);

    for(int i = 0 ; i < m ; i ++){
        int u , v;
        long long wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v,wt});
    }

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
    pq.push({0,1}); // cost , node

    vector<vector<long long>> dist(n + 1);
    
    while(!pq.empty()){

        auto [cost,node] = pq.top();
        pq.pop();

        if(dist[node].size() >= k) continue;
        dist[node].push_back(cost);

        for(auto[next,wt]: adj[node]){
            pq.push({cost+wt,next});
        }
    }


    for(long long x : dist[n]){
        cout<<x<<" ";
    }
    cout<<endl;

  

}