#include <bits/stdc++.h>
using namespace std;

vector<int> euler;
int idx = 0;
void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){

    vis[node] = 1;
    euler.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
            euler.push_back(node);
        }
    }
}
int main(){

    int n , m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);

    for(int i = 0 ; i < m ; i ++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n,0);
    dfs(1,adj,vis);
    for(auto it : euler){
        cout<<it<<" ";
    }
}