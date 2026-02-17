#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({1,1});

    vector<int> dist(n + 1 , INT_MAX);
    dist[1] = 1;
    vector<int> parent(n + 1, 0);
    iota(parent.begin(),parent.end(),0);
    while(!pq.empty()){
    
        auto [distance , node] = pq.top();
        pq.pop();

        for(auto next : adj[node]){
            int newDistance = 1 + distance;

            if(newDistance < dist[next]){
                parent[next] = node;
                dist[next] = newDistance;
                pq.push({newDistance,next});
            }
        }

    }
    if(dist[n] == INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]<<endl;
    vector<int> path;
    for(int i = n ; i != 1 ; i = parent[i]){
        path.push_back(i);
    }
    path.push_back(1);
    reverse(path.begin(),path.end());

    for(auto it : path) cout<<it<<" ";
    cout<<endl;

}