#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
int sz[N];
int n;
void dfs(int u,int p){
    sz[u] = 1;

    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

int centroid(int u,int p){

    for(int v : adj[u]){
        if(v == p) continue;
        
        if(sz[v] > n / 2){
            return centroid(v,u);
        }
    }

    return u;
}
int main(){
    cin >> n;
    // n = n;

    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfs(1,-1);

    cout << centroid(1,-1) << endl;
}