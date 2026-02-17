#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){

    if(i < 0 || j < 0 || i >= n  || j >= m || grid[i][j] == '#'){
        return;
    }

    grid[i][j] = '#';

    dfs(i+1,j,n,m,grid);
    dfs(i,j+1,n,m,grid);
    dfs(i-1,j,n,m,grid);
    dfs(i,j-1,n,m,grid);
}
int main(){
    

    int n , m;
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));
    
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(grid[i][j] == '.'){
                cnt++;
                dfs(i,j,n,m,grid);
            }
        }
    }

    cout<<cnt;
}