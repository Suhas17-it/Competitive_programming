#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int depth[N];
vector<int> adj[N];
const int l = 30;
int up[N][l];
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
int main(){

    int n , q ;
    cin >> n >> q;

    memset(up,-1,sizeof(up));

    for(int i = 1 ; i < n ; i ++){
        int t;
        cin >> t;
        adj[t].push_back(i + 1);
        adj[i + 1].push_back(t);
    }

    dfs(1,-1);

    for(int j = 0 ; j < l ; j ++){
        for(int i =  1 ; i <= n ; i ++){
            if(up[i][j - 1] != -1){
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    while(q--){
        int a , b;
        cin >> a >> b;

        cout << lca(a,b) << endl;
    }
}