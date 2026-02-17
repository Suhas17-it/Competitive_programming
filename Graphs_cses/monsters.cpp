#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m ;
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> grid[i][j];
        }
    }

    int srcx = -1  , srcy = -1;
    vector<vector<int>> monster(n,vector<int>(m,INT_MAX));
    queue<array<int,3>> q;
    for(int i = 0 ; i <  n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(grid[i][j] == 'M'){
                q.push({i,j,0});
                monster[i][j] = 0;
            }
            else if(grid[i][j] == 'A'){
                srcx = i;
                srcy = j;
            }
        }
    }

    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    while(!q.empty()){

        auto [i,j,steps] = q.front();
        q.pop();

        for(auto [u,v] : dir){
            int nx = u + i;
            int ny = v + j;


            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && 1 + steps < monster[nx][ny]){
                monster[nx][ny] = 1 + steps;
                q.push({nx,ny,1+steps});
            } 
        }
    }


    vector<vector<int>> player(n,vector<int>(m,INT_MAX));
    vector<vector<int>> parent(n,vector<int>(m,-1));
    player[srcx][srcy] = 0;
    queue<array<int,3>> dq;

    dq.push({srcx,srcy,0});

    vector<char> dirC = {'R','L','D','U'};
    int destx = -1 , desty = -1;
    while(!dq.empty()){

        auto [i,j,steps] = dq.front();
        dq.pop();
        
        if(i == 0 || j == 0 || i == n - 1 || j == m - 1 ){
            destx = i , desty = j;
            cout<<"YES"<<endl;
            cout<<steps<<endl;
            break;
        }
        int k = 0;
        for(auto [u,v] : dir){
            int nx = i + u;
            int ny = j + v;


            if(nx >= 0  && ny >= 0 && nx < n && ny < m &&  grid[nx][ny] != '#' && 1 + steps < monster[nx][ny] && 1 + steps < player[nx][ny]){
                player[nx][ny] = 1 + steps;
                parent[nx][ny] = dirC[k];
                dq.push({nx,ny,steps + 1});
            }
            k++;
        }
    }
    
    if(destx == -1  || desty == -1){
        cout<<"NO";
        return 0;
    }
    // cout<<destx<<" "<<desty<<endl;
    int x = destx , y = desty;

    string ans = "";

    while(x != srcx || y != srcy){
        char d = parent[x][y];
        ans += d;
        // cout<<"HI";
        if(d == 'U'){
            x++;
        }
        else if(d == 'D'){
            x--;
        }
        else if(d == 'L'){
            y++;
        }
        else if(d == 'R'){
            y--;
        }
    }

    reverse(ans.begin(),ans.end()); 
    // cout<<ans.empty();
    for(auto it : ans) cout<<it<<"";
    cout<<endl;

    
    
}