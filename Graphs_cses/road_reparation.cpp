#include <bits/stdc++.h>
using namespace std;

class Disjoint{
    public :
        vector<int> parent,sz;
        int components;
        Disjoint(int n){
            components = n;
            parent.resize(n);
            iota(parent.begin(),parent.end(),0);
            sz.resize(n,1);
        }


        int find(int x){
            return x == parent[x] ? parent[x] : parent[x] = find(parent[x]);
        }

        bool unite(int a,int b){
            int x = find(a);
            int y = find(b);

            if(x == y){
                return false;
            }

            if(sz[x] < sz[y]) swap(x,y);

            sz[x] += sz[y];
            parent[y] = x;
            components--;
            return true;
        }

        int getComponents(){
            return components;
        }
};
int main(){


    int n , m;
    cin >> n >> m;

    vector<vector<long long>> edges;

    for(int i = 0 ; i < m ; i ++){
        long long u , v;
        long long wt;

        cin >> u >> v >> wt;
        edges.push_back({wt,u,v});
    }

    sort(edges.begin(),edges.end());

    Disjoint ds(n + 1);
    long long ans = 0LL;
    set<long long> vis;
    for(int i = 0 ; i < m ; i ++){

        long long u = edges[i][1];
        long long v = edges[i][2];
        long long wt = edges[i][0];

        if(ds.unite(u,v)){
            vis.insert(u);
            vis.insert(v);
            ans += wt;
        }
    }

    if(ds.getComponents() > 2){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<ans<<endl;
}