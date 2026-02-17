#include <bits/stdc++.h>
using namespace std;
int main(){


    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<char>> parent(n,vector<char>(m));

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            cin >> grid[i][j];
        }
    }

    int srcx = -1 , srcy = -1 , destx = -1 , desty = -1;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(grid[i][j] == 'A'){
                srcx = i;
                srcy = j;
            }
            if(grid[i][j] == 'B'){
                destx = i;
                desty = j;
            }
        }
    }

    queue<pair<int,int>> q;

    string path = "";
    int moves = 0;
    q.push({srcx,srcy});

    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<char> dirC = {'R','L','D','U'};
    while(!q.empty()){

        int sz = q.size();

        while(sz--){
            auto [i,j] = q.front();
            q.pop();

            int t = 0;
            for(auto [x,y]: dir){

                int nx = i + x;
                int ny = j + y;

                char d = (t == 0) ? 'R' : (t == 1) ? 'L' : (t == 2) ? 'D' : 'U';
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#'){
                    grid[nx][ny] = '#';
                    parent[nx][ny] = dirC[t];
                    q.push({nx,ny});
                }
                t++;
            }

        }
        moves++;
    }

    if(!parent[destx][desty]){
        cout<<"NO"<<endl;
        return 0;
    }

    int x = destx , y = desty;

    string ans = "";

    while(x != srcx || y != srcy){
        char d = parent[x][y];
        ans += d;
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
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;

}