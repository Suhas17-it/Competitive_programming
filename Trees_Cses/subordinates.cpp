#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        tree[p-1].push_back(i);
    }
    vector<int> subordinates(n);
    function<void(int)> dfs = [&](int node){
        for(int child : tree[node]){
            dfs(child);
            subordinates[node] += subordinates[child] + 1;
        }
    };

    
    dfs(0);
    for(int i = 0; i < n; i++){
        cout << subordinates[i] << " ";
    }

    cout << endl;
}