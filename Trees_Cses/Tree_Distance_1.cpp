#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj[N];
int distA[N], distB[N];
void dfs(int u,int p,int dist, int distArr[]){
    distArr[u] = dist;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u,dist + 1, distArr);
    }
}

int main(){

    int n;
    cin >> n;


    for(int i = 1 ; i < n ; i ++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1,0,distA);
    int A = max_element(distA, distA + n + 1) - distA;

    dfs(A,-1,0,distA);
    int B = max_element(distA, distA + n + 1) - distA   ;

    // dfs(A,-1,0,distA);
    dfs(B,-1,0,distB);

    for(int i = 1; i <= n; i++){
        cout << max(distA[i], distB[i]) << " ";
    }

}