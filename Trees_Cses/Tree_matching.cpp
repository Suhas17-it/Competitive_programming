#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int dp[N][2];

void dfs(int u,int p){
    
    int total = 0;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        
        total += max(dp[v][0], dp[v][1]);
    }

    dp[u][0] = total;

    dp[u][1] = 0;

    for(int v : adj[u]){
        if(v == p) continue;
        int candidate = 1 + dp[v][0] + (total - max(dp[v][0], dp[v][1]));
        dp[u][1] = max(dp[u][1], candidate);
    }
}
int main(){
    int n;
    cin >> n;

    for(int i = 1 ; i < n ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);

    cout << max(dp[1][0], dp[1][1]) << endl;
}