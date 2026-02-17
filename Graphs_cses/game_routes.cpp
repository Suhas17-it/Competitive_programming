#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1 , 0);
    vector<long long> dp(n + 1 , 0);
     for(int i = 0 ; i < m ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }


    queue<int> q;
    for(int i = 1 ; i <= n ; i ++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> anss;
    while(!q.empty()){

        int node = q.front();
        q.pop();
        anss.push_back(node);

        for(int v : adj[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    dp[1] = 1;
    for(int x : anss){
        if(dp[x] < 0) continue;
        for(int v : adj[x]){
            dp[v] = (dp[v] + dp[x]) % mod;
        }
    }

    cout<<dp[n]<<endl;


}