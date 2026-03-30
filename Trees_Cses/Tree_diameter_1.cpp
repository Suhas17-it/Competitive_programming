#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];

int farthest , maxDist;
void dfs(int u,int p,int dist){
    if(dist > maxDist){
        maxDist = dist;
        farthest = u;
    }

    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u,dist + 1);
    }

}


int main(){


    int n;
    cin >> n;

    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    dfs(1,-1,0);

    int st = farthest;

    dfs(st,-1,0);

    cout << maxDist << endl;

}