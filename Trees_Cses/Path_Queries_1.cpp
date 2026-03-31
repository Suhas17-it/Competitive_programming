#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
long long seg[4 * N];
long long heavy[N] , head[N] , pos[N];
long long depth[N] , val[N] , sz[N] , parent[N];

int curr_pos = 0;
void update(int idx,long long val,int node,int start,int end){
    if(start == end){
        seg[node] = val;
        return;
    }

    int mid = (start + end) / 2;

    if(idx <= mid){
        update(idx,val,2 * node,start,mid);
    }else{
        update(idx,val,2 * node + 1,mid + 1,end);
    }

    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

long long query(int l,int r,int node,int start,int end){
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return seg[node];

    int mid = (start + end) / 2;

    long long p1 = query(l,r,2 * node,start,mid);
    long long p2 = query(l,r,2 * node + 1,mid + 1,end);

    return p1 + p2;
}

int main(){
    int n , q;
    cin >> n >> q;

    for(int i = 1 ; i <= n ; i ++){
        cin >> val[i];
        heavy[i] = -1;
    }

    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    function<int(int,int)> dfs = [&](int u,int p){
        sz[u] = 1;
        int max_subtree = 0;
        parent[u] = p;
        for(int v : adj[u]){
            if(v == p) continue;
            depth[v] = depth[u] + 1;
            int subtree_size = dfs(v,u);
            sz[u] += subtree_size;

            if(subtree_size > max_subtree){
                max_subtree = subtree_size;
                heavy[u] = v;
            }
        }

        return sz[u];
    };

    dfs(1, -1);

    function<void(int,int,int)> decompose = [&](int u,int h,int p){
        head[u] = h;
        pos[u] = ++curr_pos;

        if(heavy[u] != -1){
            decompose(heavy[u], h, u);
        }

        for(int v : adj[u]){
            if(v == p || v == heavy[u]) continue;
            decompose(v, v, u);
        }
    };

    decompose(1, 1, -1);

    for(int i = 1 ; i <= n ; i ++){
        update(pos[i], val[i], 1, 1, n);
    }

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int u , x;
            cin >> u >> x;
            update(pos[u],x,1,1,n);
        }else{
            int v ;
            cin >> v ;
            
            int u = 1;
            long long ans = 0;

            while(head[u] != head[v]){
                if(depth[head[u]] < depth[head[v]]) swap(u,v);
                ans += query(pos[head[u]], pos[u], 1, 1, n);
                u = parent[head[u]];
            }

            if(depth[u] > depth[v]) swap(u,v);
            ans += query(pos[u], pos[v], 1, 1, n);
            cout << ans << '\n';
        }
    }
   
    return 0;
}