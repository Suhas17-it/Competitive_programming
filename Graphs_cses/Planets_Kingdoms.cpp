// A game has n planets, connected by m teleporters. Two planets a and b belong to the same kingdom exactly when there is a route both from a to b and from b to a. Your task is to determine for each planet its kingdom.
// Input
// The first input line has two integers n and m: the number of planets and teleporters. The planets are numbered 1,2,\dots,n.
// After this, there are m lines describing the teleporters. Each line has two integers a and b: you can travel from planet a to planet b through a teleporter.
// Output
// First print an integer k: the number of kingdoms. After this, print for each planet a kingdom label between 1 and k. You can print any valid solution.
#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){

    vis[node] = 1;

    for(int v : adj[node]){
        if(!vis[v]){
            dfs(v,adj,vis);
        }
    }

    st.push(node);

}

void dfs2(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& comp,int id){
    vis[node] = 1;
    comp[node] = id;
    for(int v : adj[node]){
        if(!vis[v]){
            dfs2(v,adj,vis,comp,id);
        }
    }
}
int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);
    for(int i = 0 ; i < m ; i ++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<int> vis(n + 1);
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i]){
            dfs(i,adj,vis);
        }
    }


    int id = 0;
    vector<int> visComp(n + 1);
    vector<int> ans(n + 1);
    
    while(!st.empty()){
        int comp = st.top();
        st.pop();
        if(!visComp[comp]){
            id++;
            dfs2(comp,rev,visComp,ans,id);
        }
    }

    
    cout<<id<<endl;
    for(int i = 1 ; i <= n ; i ++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}