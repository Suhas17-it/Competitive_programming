#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
const int mod = 1e9 + 7;
int solve(int i,int j,vector<vector<char>>& grid,int n){
    if(i >= n  || j >= n || grid[i][j] == '*'){
        return 0;
    }


    if(i == n - 1 && j == n - 1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solve(i + 1,j,grid,n);
    int down = solve(i,j+1,grid,n);

    return dp[i][j] = (right + down) % mod;
}
int main(){
    
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin >> grid[i][j];
        }
    }

    dp.resize(n,vector<int>(n,-1));
    
    cout << solve(0,0,grid,n) << endl;
    return 0;
}