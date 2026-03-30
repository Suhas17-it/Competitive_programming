#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
const int l = 40;
int up[N][l];

void dfs(int u,int p){
    up[u][0] = p;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
    }
}


int main(){

    int n , q;
    cin >> n >> q; 

    memset(up,-1,sizeof(up));
    for(int i = 1 ; i < n ; i ++){
        int t;
        cin >> t;
        adj[t].push_back(i + 1);
        adj[i + 1].push_back(t);
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
        int x , k;
        cin >> x >> k;
        
        for(int j = 0 ; j < l ; j ++){
            if(k & (1LL << j)){
                x = up[x][j];
                if(x == -1) break;
            }
        }

        cout << x << endl;
    }




    
}