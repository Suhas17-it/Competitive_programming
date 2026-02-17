#include <bits/stdc++.h>
using namespace std;


int main(){
    int n , m;
    cin >> n >> m;


    vector<vector<pair<long long,long long>>> adj(n + 1);
    for(int i = 0 ; i < m ; i ++){
        long long u , v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        // adj[v].push_back({u,wt});
    }

    vector<long long> dist(n + 1, LLONG_MAX);

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
    dist[1] = 0;
    pq.push({0,1}); // cost,city

    while(!pq.empty()){

        auto [cost,node] = pq.top();
        pq.pop();

        if(dist[node] < cost) continue;
        for(auto [next , wt] : adj[node]){

            long long newWt = wt + cost;
            if(newWt < dist[next]){
                dist[next] = newWt;
                pq.push({newWt,next});
            }
        }

    }

    for(int i = 1; i <= n ; i ++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}