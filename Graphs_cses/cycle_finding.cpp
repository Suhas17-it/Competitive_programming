#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u , v;
    long long wt;
};
const long inf = 4e18;
int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<Edge> edges;
    for(int i = 0 ; i < m ; i ++){
        int u , v , wt;
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
        adj[u].push_back(v);
    }

    vector<long long> dist(n + 1 , 0);
    vector<int> parent(n + 1 , -1);
    int relax = -1;
    for(int i = 1 ; i <= n ; i ++){
        relax = -1;

        for(auto &e : edges){

            if(dist[e.u] < inf && dist[e.u] + e.wt < dist[e.v]){
                dist[e.v] = dist[e.u] + e.wt;
                parent[e.v] = e.u;
                relax = e.v;
            }
        }
    }

    if(relax == -1){
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i = 1 ; i <= n ; i ++){
        relax = parent[relax];
    }

    int curr = relax;
    vector<int> ans;

    do{
        ans.push_back(curr);
        curr = parent[curr];
    }while(curr != relax);

    ans.push_back(relax);
    reverse(ans.begin(),ans.end());

    cout<<"YES"<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
}