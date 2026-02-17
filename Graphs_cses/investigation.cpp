#include <bits/stdc++.h>
using namespace std;

const long long inf = 4e18;
const int mod = 1e9 + 7;
int main(){

    int n , m;
    cin >> n >> m;


    vector<vector<pair<int,long long>>> adj(n + 1);
    for(int i = 0 ; i < m ; i ++){
        int u , v , wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
    }

    vector<long long> dist(n + 1 , inf);
    vector<long long> ways(n + 1 , 0);
    vector<long long> mn(n + 1 , inf) , mx(n + 1 , -inf);

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;

    pq.push({0,1}); // cost , node

    dist[1] = 0 , ways[1] = 1;
    mn[1] = mx[1] = 0;
    while(!pq.empty()){
        auto [cost,node] = pq.top();
        pq.pop();

        for(auto [next,wt] : adj[node]){

            long long newWt = cost + wt;

            if(newWt < dist[next]){
                dist[next] = newWt;
                mn[next] = mn[node] + 1;
                mx[next] = mx[node] + 1;
                pq.push({newWt,next});
                ways[next] = ways[node];
            }
            else if(newWt == dist[next]){
                ways[next] = (ways[next] + ways[node]) % mod;
                mn[next] = min(mn[next],mn[node] + 1);
                mx[next] = max(mx[next],mx[node] + 1);
            }
        }
    }


    cout<<dist[n]<<" "<<ways[n]<<" "<<mn[n]<<" "<<mx[n]<<endl;
    cout<<endl;
}