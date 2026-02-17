#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v;
    long long wt;
};

const int mod = 4e18;
int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    vector<Edge> edges;
    for(int i = 0 ; i < m ; i ++){
        int u , v ;
        long long wt;
        cin >> u >> v >> wt;
        adj[u].push_back(v);
        edges.push_back({u,v,-wt});
    }

    vector<long long> dist(n + 1 , mod);
    dist[1] = 0;
    for(int i = 1 ; i <= n - 1 ; i ++){
        for(auto &e : edges){
            if(dist[e.u] < mod && dist[e.u] + e.wt < dist[e.v]){
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    vector<int> bad(n + 1 , 0);
    for(int i = 1 ; i <= n; i ++){
        for(auto &e : edges){
            if(dist[e.u] < mod && dist[e.u] + e.wt < dist[e.v]){
                dist[e.v] = dist[e.u] + e.wt;
                bad[e.v] = 1; 
            }
        }
    }

    
    queue<int> q;
    
    for(int i = 1 ; i <= n ; i ++){
        if(bad[i]) q.push(i);
    }


    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(!bad[v]){
                bad[v] = 1;
                q.push(v);
            }
        }

    }

    if(bad[n]) cout<<-1<<"\n";
    else if(dist[n]==mod) cout<<-1<<"\n";
    else cout<<-dist[n]<<"\n";


    
}