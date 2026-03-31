#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
int depth[N];
int const l = 20;
int up[N][l];
int dp[N];

void dfs(int u,int p){
    up[u][0] = p;

    for(int v : adj[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1; 
        dfs(v,u);
    }

}

int lift(int x,int k){

    for(int j = 0 ; j < l ; j ++){
        if(k & (1 << j)){
            x = up[x][j];
            if(x == -1) break;
        }
    }

    return x;
}

int lca(int a,int b){

    if(depth[a] < depth[b]) swap(a,b);

    a = lift(a , depth[a] - depth[b]);

    if(a == b) return a;

    for(int j = l - 1 ; j >= 0 ; j --){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];

}

void dfs2(int u,int p){
    
    for(int v : adj[u]){
        if(v == p) continue;
        dfs2(v,u);
        dp[u] += dp[v];
    }
}
int main(){

    int n ,q;
    cin >> n >> q;

    memset(up,-1,sizeof(up));

    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfs(1,-1);

    for(int j = 1 ; j < l ; j ++){
        for(int i = 1 ; i <= n ; i ++){
            if(up[i][j - 1] != -1){
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }


    while(q--){

        int a , b;
        cin >> a >> b;

        int c = lca(a,b);

        dp[a] += 1;
        dp[b] += 1;

        dp[c] -= 1;

        if(up[c][0] != -1){
            dp[up[c][0]] -= 1;
        }
    }


    dfs2(1,-1);

    for(int i = 1 ; i <= n ; i ++){
        cout << dp[i] << " ";
    }
}