#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m;
    cin >> n >> m;


    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1 , 0);
    vector<int> dp(n + 1 , -1e18);
    vector<int> indegree(n + 1 , 0);
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
            if(dp[x] + 1 > dp[v]){
                parent[v] = x;
                dp[v] = dp[x] + 1;
            }
        }
    }
  
    if(dp[n] < 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dp[n]<<endl;
    vector<int> ans;
    for(int i = n; i != 1 ; i = parent[i]){
        ans.push_back(i);
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());

    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
}