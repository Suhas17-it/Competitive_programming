#include <bits/stdc++.h>
using namespace std;


int main(){
    int n , m , q;
    cin >> n >> m >> q;


    vector<vector<long long>> dist(n + 1 , vector<long long>(n + 1, LLONG_MAX));

    for(int i = 0 ; i < m ; i ++){
        long long u , v , wt;
        cin >> u >> v >> wt;

        dist[u][v] = min(dist[u][v],wt);
        dist[v][u] = min(dist[v][u],wt);
    }

    for(int i = 1 ; i <= n ; i ++){
        dist[i][i] = 0;
    }
    for(int k = 1 ; k <= n ; k ++){
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= n ; j ++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<int> ans(q,-1);
    for(int i = 0 ; i < q ; i ++){
        int src , dest;
        cin >> src >> dest;
        ans[i] = dist[src][dest] == LLONG_MAX ? -1 : dist[src][dest];
    }

    for(auto it : ans) cout<<it<<" ";
    cout<<endl;

   
}