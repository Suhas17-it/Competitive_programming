#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int depth[N], sz[N], head[N], pos[N], val[N], heavy[N], parent[N];

int cur_pos = 0;

int SZ;
vector<long long> seg;

int dfs(int u, int p){
    sz[u] = 1;
    parent[u] = p;
    int max_sub = 0;

    for(int v : adj[u]){
        if(v == p) continue;

        depth[v] = depth[u] + 1;
        int sub = dfs(v, u);
        sz[u] += sub;

        if(sub > max_sub){
            max_sub = sub;
            heavy[u] = v;
        }
    }
    return sz[u];
}


void decompose(int u, int h){
    head[u] = h;
    pos[u] = ++cur_pos;

    if(heavy[u] != -1)
        decompose(heavy[u], h);

    for(int v : adj[u]){
        if(v == parent[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}


void build(int n){
    SZ = 1;
    while(SZ < n) SZ <<= 1;
    seg.assign(2 * SZ, LLONG_MIN);
}


void update(int idx, long long value){
    idx += SZ - 1;
    seg[idx] = value;

    while(idx > 1){
        idx /= 2;
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
    }
}


long long query(int l, int r){
    l += SZ - 1;
    r += SZ - 1;

    long long res = LLONG_MIN;

    while(l <= r){
        if(l % 2 == 1) res = max(res, seg[l++]);
        if(r % 2 == 0) res = max(res, seg[r--]);

        l /= 2;
        r /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> val[i];
        heavy[i] = -1;
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    decompose(1, 1);

    build(n);
    for(int i = 1; i <= n; i++){
        update(pos[i], val[i]);
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int u, x;
            cin >> u >> x;
            update(pos[u], x);
        }
        else{
            int a, b;
            cin >> a >> b;

            long long ans = LLONG_MIN;

            while(head[a] != head[b]){
                if(depth[head[a]] < depth[head[b]]) swap(a,b);

                ans = max(ans, query(pos[head[a]], pos[a]));
                a = parent[head[a]];
            }

            if(depth[a] > depth[b]) swap(a,b);

            ans = max(ans, query(pos[a], pos[b]));

            cout << ans << " ";
        }
    }
}