#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
bool removed[N];
int sz[N];
int K;
int freq[N];
long long ans = 0LL;
void dfs_sz(int u,int p){
    sz[u] = 1;

    for(int v : adj[u]){
        if(v == p || removed[v]) continue;
        dfs_sz(v,u);
        sz[u] += sz[v];
    }
}

int centroid(int u,int p,int total){
    
    for(int v : adj[u]){
        if(v == p || removed[v]) continue;
        if(sz[v] > total / 2){
            return centroid(v,u,total);
        }
    }

    return u;
}

void dfs_dist(int u,int p,vector<int>& dist,int d){
    if(d > K) return;
    dist.push_back(d);

    for(int v : adj[u]){
        if(v == p || removed[v]) continue;
        dfs_dist(v,u,dist,d + 1);
    }

}

void solve(int u){
    dfs_sz(u,-1);

    int c = centroid(u,-1,sz[u]);

    removed[c] = true;

    freq[0] = 1;

    vector<vector<int>> all_dist;

    for(int v : adj[c]){
        if(removed[v]) continue;

        vector<int> dist;
        dfs_dist(v,c,dist,1);
        all_dist.push_back(dist);
    }

    for(auto &dist : all_dist){
        for(int d : dist){
            if(K - d >= 0)
                ans += freq[K - d];
        }
        for(int d : dist){
            freq[d]++;
        }
    }
    for(auto &dist : all_dist){
        for(int d : dist){
            freq[d] = 0;
        }
    }

    freq[0] = 0;


    for(int v : adj[c]){
        if(!removed[v]){
            solve(v);
        }
    }


}
int main(){

    int n , k;
    cin >> n >> k;

    K = k;

    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1);

    cout << ans << endl;

}
