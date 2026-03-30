#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<long long> adj[N];
vector<long long> dp , sz , ans;
void dfs(long long u,long long p){
    sz[u] = 1;
    dp[u] = 0;

    for(long long v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        dp[u] += dp[v] + sz[v];
        sz[u] += sz[v];
    }
}

void dfs2(long long u,long long p){

    ans[u] = dp[u];
    for(long long v : adj[u]){
        if(v == p) continue;
        
        long long oldu = dp[u] , oldsz = sz[u];

        dp[u] -= dp[v] + sz[v] , sz[u] -= sz[v];

        dp[v] += dp[u] + sz[u];
        sz[v] += sz[u];

        dfs2(v,u);

        dp[u] = oldu , sz[u] = oldsz;
    }
}
int main(){
    int n;
    cin >> n;

    dp.resize(n + 1);
    sz.resize(n + 1);
    ans.resize(n + 1);

    for(int i = 1 ; i < n ; i ++){
        long long u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);
    dfs2(1,-1);


    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

}