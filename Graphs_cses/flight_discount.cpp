#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n ,m;
    cin >> n >> m;


    vector<vector<pair<int,long long>>> adj(n + 1);

    for(int i = 0 ; i < m ; i ++){
        int  u , v , wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }

    vector<vector<long long>> dist(n + 1 , vector<long long>(2,LLONG_MAX));

    dist[1][0] =  dist[1][1] = 0;
    priority_queue<array<long long,3>,vector<array<long long,3>>,greater<>> pq;
    pq.push({0,1,0});

    while(!pq.empty()){

        auto [cost,node,used] = pq.top();
        pq.pop();

        if(cost > dist[node][used]) continue;

        for(auto [next,wt] : adj[node]){

            long long newCost = cost + wt;
            if(newCost < dist[next][used]){
                dist[next][used] = newCost;
                pq.push({newCost,next,used});
            }
            if(used == 0){
                newCost = (cost + (wt/2));
                if(newCost < dist[next][1]){
                    dist[next][1] = newCost;
                    pq.push({newCost,next,1});
                }
            }
            
        }
    }


    cout<<min(dist[n][0], dist[n][1])<<endl;
}