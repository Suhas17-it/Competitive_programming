#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){

    vis[node] = 1;

    for(auto it : adj[node]){

        if(!vis[it]){
            dfs(it,vis,adj);
        }
        
    }


}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> vis(n + 1);
    vector<vector<int>> res;
    int cnt = 0;
    for(int i = 1 ; i < n + 1 ; i ++){
        if(!vis[i]){
            if(i != 1){
                res.push_back({i - 1, i });
            }
            dfs(i,vis,adj);
            cnt++;
        }
    }

    cout<<cnt - 1<<endl;
    for(auto it : res) cout<<it[0]<<" "<<it[1]<<endl;
}