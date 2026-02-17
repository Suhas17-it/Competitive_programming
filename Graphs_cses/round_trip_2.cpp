#include <bits/stdc++.h>
using namespace std;

int st = -1 , en = -1;
bool cycle(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& parent){
    
    vis[node] = 1;

    for(auto next : adj[node]){

        if(vis[next] == 0){
            parent[next] = node;
            if(cycle(next,adj,vis,parent)){
                return true;
            }
        }
        else if(vis[next] == 1){
            st = next;
            en = node;
            return true;
        }  
          
    }
    vis[node] = 2;
    return false;
}
int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);

    }  
    
    vector<int> parent(n + 1, -1);

    vector<int> vis(n + 1, 0);
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i]){
            if(cycle(i,adj,vis,parent)){
                break;
            }
        }
    }

    if(st == -1 || en == -1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    

    vector<int> path;

    path.push_back(st);

    for(int v = en ; v != st ; v = parent[v]){
        path.push_back(v);
    }

    path.push_back(st);

    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(auto x : path){
        cout<<x<<" ";
    }
    return 0;


}