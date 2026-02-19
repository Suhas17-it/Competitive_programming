#include<bits/stdc++.h>
using namespace std;
 
void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
 
    vis[node] = 1;
    for(int x : adj[node]){
        if(!vis[x]){
            dfs(x,vis,adj);
        }
    }
}
int main(){
 
    int n , m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
 
    
    vector<int> vis(n + 1,0);
    dfs(1,vis,adj);
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<"1 "<<i<<endl;
            return 0;
        }
    }
 
 
    vector<int> vis2(n + 1 , 0);
    dfs(1,vis2,rev);
    for(int i = 1 ; i <= n ; i ++){
        if(!vis2[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<"1"<<endl;
            return 0;
        }
    }
    
 
    cout<<"YES\n";
    return 0;
}