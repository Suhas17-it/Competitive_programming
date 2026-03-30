#include <bits/stdc++.h>
using namespace std;
int ways = 0LL;
set<vector<vector<char>>> seen;
bool isSafe(vector<vector<char>>& mat,int i,int j){

    for(int r = 0 ; r < i ; r ++){
        if(mat[r][j] == 'Q') return false;
    }

    for(int r = i - 1 , c = j - 1 ; r >=0 && c >= 0 ; r--,c--){
        if(mat[r][c] == 'Q') return false;
    }

    for(int r = i - 1 , c = j + 1 ; r >= 0 && c < 8; r -- , c ++){
        if(mat[r][c] == 'Q') return false;
    }

    return true;
}
void solve(int row , vector<vector<char>>& mat){
    if(row >= 8){
        seen.insert(mat);
        ways += 1;
        return ;
    }

    for(int col = 0 ; col < 8 ; col ++){
        if(isSafe(mat,row,col) && mat[row][col] != '*'){
            mat[row][col] = 'Q';
            solve(row + 1 , mat);
            mat[row][col] = '.';
        }
    }


}
int main(){

    vector<vector<char>> mat(8,vector<char>(8));

    for(int i = 0 ; i < 8 ; i ++){
        for(int j = 0 ; j < 8 ; j ++){
            cin >> mat[i][j];
        }
    }

    solve(0,mat);
    
    cout << seen.size() << endl;
    
}