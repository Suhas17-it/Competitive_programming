#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;


    vector<vector<char>> grid(n,vector<char>(n));

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin >> grid[i][j];
        }
    }

    string ans = "";
    ans += grid[0][0];

    vector<pair<int,int>> curr = {{0,0}};
    vector<vector<bool>> vis(n,vector<bool>(n));

    vis[0][0] = 1;

    for(int step = 1 ; step < 2 * n - 1 ;  step ++){

        vector<pair<int,int>> next;

        char best = 'Z';

        for(auto [u,v] : curr){
            
            if(u + 1 < n){
                best = min(best,grid[u +1 ][v]);
            }

            if(v + 1 < n){
                best = min(best,grid[u][v + 1]);
            }
        }
        for(auto [u,v] : curr){
            if(u + 1 < n && grid[u + 1][v] == best && !vis[u+1][v]){
                vis[u+1][v] = true;
                next.push_back({u + 1 , v});
            }

            if(v + 1 < n && grid[u][v+1] == best && !vis[u][v + 1]){
                vis[u][v+1] = true;
                next.push_back({u,v+1});
            }
        }


        curr = next;
        ans += best;
    }

    cout<<ans<<"\n";


}