#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
int in[N] , out[N];
long long bit[N];
int timer = 0;
int m ;
void dfs(int u,int p){
    in[u] = ++timer;

    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
    }

    out[u] = timer;
}

void update(int i,int x){
    for(; i < m + 1 ; i += i & -i){
        bit[i] += x;
    }
}

long long sum(int i){
    long long s = 0 ;
    for(; i > 0; i -= i & -i){
        s += bit[i];
    }

    return s;
}

long long query(int l,int r){

    return sum(r) - sum(l - 1);
}

int main(){

    int n , q;
    cin >> n >> q;
    m = n;
    vector<int> val(n + 1);

    for(int i = 1 ; i <= n ; i ++){
        cin >> val[i];
    }


    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    dfs(1,-1);
    for(int i = 1 ; i <= n ; i ++){
        update(in[i],val[i]);
    }   

    while(q--){
        int type;
        cin >>type;

        if(type == 1){
            int node , v;
            cin >> node >> v;
            
            update(in[node],v - val[node]);
            val[node] = v;
        }
        else{
            int a;
            cin >> a ;

            cout << query(in[a],out[a]) << endl;
        }
    }
}
