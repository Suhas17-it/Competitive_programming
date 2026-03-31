#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int sz[N], heavy[N], parent[N];
int color[N], freq[N], ans[N];

int distinct_cnt = 0;

void dfs1(int u, int p){
    sz[u] = 1;
    parent[u] = p;
    heavy[u] = -1;

    int max_sz = 0;

    for(int v : adj[u]){
        if(v == p) continue;

        dfs1(v, u);
        sz[u] += sz[v];

        if(sz[v] > max_sz){
            max_sz = sz[v];
            heavy[u] = v;
        }
    }
}


void add(int u, int p, int val){
    stack<pair<int,int>> st;
    st.push({u, p});

    while(!st.empty()){
        auto [node, par] = st.top();
        st.pop();

        int c = color[node];

        if(val == 1){
            if(++freq[c] == 1) distinct_cnt++;
        } else {
            if(--freq[c] == 0) distinct_cnt--;
        }

        for(int v : adj[node]){
            if(v == par) continue;
            st.push({v, node});
        }
    }
}


void dfs2(int u, int p, bool keep){

    for(int v : adj[u]){
        if(v == p || v == heavy[u]) continue;
        dfs2(v, u, false);
    }

  
    if(heavy[u] != -1){
        dfs2(heavy[u], u, true);
    }

    for(int v : adj[u]){
        if(v == p || v == heavy[u]) continue;
        add(v, u, +1);
    }

 
    int c = color[u];
    if(++freq[c] == 1) distinct_cnt++;

    ans[u] = distinct_cnt;

    if(!keep){
        add(u, p, -1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> color[i];
    }

  
    vector<int> comp(color + 1, color + n + 1);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for(int i = 1; i <= n; i++){
        color[i] = lower_bound(comp.begin(), comp.end(), color[i]) - comp.begin() + 1;
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, true);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}