#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0 ; i < m ; i ++){
        int  u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    vector<int> indegree(n + 1 , 0);

    for(int i = 1 ; i <= n ; i ++){
        for(int v : adj[i]){
            indegree[v]++;
        }
    }


    queue<int> q;
    for(int i = 1 ; i <= n ; i ++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int v : adj[node]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }

    }

    if(ans.size() != n) cout<<"IMPOSSIBLE"<<endl;
    else{
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
    }
}
