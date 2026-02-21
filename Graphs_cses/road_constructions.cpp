#include <bits/stdc++.h>
using namespace std;

class Disjoint{
    public:
        vector<int> parent,sz;
        int components;
        int last;
        int maxSize;
        Disjoint(int n){
            parent.resize(n);
            components = n;
            last = n - 1;
            maxSize = 1;
            iota(parent.begin(),parent.end(),0);
            sz.resize(n,1);
        }

        int find(int x){
            return (x == parent[x]) ? x : parent[x] = find(parent[x]);
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
            maxSize = max(maxSize,sz[x]);
            return true;
        }

        int getComponents(){
            return components;
        }

        int maxComponent(){
           return maxSize;
        }
};
int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    Disjoint ds(n + 1);
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        ds.unite(u,v);
        cout<<ds.getComponents() - 1<<" "<<ds.maxComponent()<<endl;
    }
}