#include <bits/stdc++.h>
using namespace std;

struct State{
    int x1,y1,x2,y2,dist;
};

int main() {

    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    vector<pair<int,int>> start,endp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j]=='s')
                start.push_back({i,j});

            if(grid[i][j]=='S')
                endp.push_back({i,j});
        }
    }

    int sx1=start[0].first;
    int sy1=start[0].second;
    int sx2=start[1].first;
    int sy2=start[1].second;

    int dx1=endp[0].first;
    int dy1=endp[0].second;
    int dx2=endp[1].first;
    int dy2=endp[1].second;

    auto valid = [&](int x,int y){
        return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='H';
    };

    vector<vector<vector<vector<bool>>>> vis(
        n,
        vector<vector<vector<bool>>>(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(m,false)
            )
        )
    );

    queue<State> q;

    vis[sx1][sy1][sx2][sy2]=true;
    q.push({sx1,sy1,sx2,sy2,0});

    while(!q.empty()){

        auto cur=q.front();
        q.pop();

        int x1=cur.x1;
        int y1=cur.y1;
        int x2=cur.x2;
        int y2=cur.y2;
        int dist=cur.dist;

        bool reached =
            (x1==dx1 && y1==dy1 && x2==dx2 && y2==dy2) ||
            (x1==dx2 && y1==dy2 && x2==dx1 && y2==dy1);

        if(reached){
            cout<<dist<<"\n";
            return 0;
        }


        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        for(auto &[dx,dy]:dir){

            int nx1=x1+dx;
            int ny1=y1+dy;

            int nx2=x2+dx;
            int ny2=y2+dy;

            if(valid(nx1,ny1) && valid(nx2,ny2)
               && !vis[nx1][ny1][nx2][ny2]){

                vis[nx1][ny1][nx2][ny2]=true;
                q.push({nx1,ny1,nx2,ny2,dist+1});
            }
        }



        // horizontal sofa
        if(x1==x2){

            int row=x1;
            int c=min(y1,y2);

            // rotate downward
            if(row+1<n &&
               valid(row,c) &&
               valid(row,c+1) &&
               valid(row+1,c) &&
               valid(row+1,c+1))
            {
                if(!vis[row][c][row+1][c]){
                    vis[row][c][row+1][c]=true;
                    q.push({row,c,row+1,c,dist+1});
                }

                if(!vis[row][c+1][row+1][c+1]){
                    vis[row][c+1][row+1][c+1]=true;
                    q.push({row,c+1,row+1,c+1,dist+1});
                }
            }

            // rotate upward
            if(row-1>=0 &&
               valid(row,c) &&
               valid(row,c+1) &&
               valid(row-1,c) &&
               valid(row-1,c+1))
            {
                if(!vis[row-1][c][row][c]){
                    vis[row-1][c][row][c]=true;
                    q.push({row-1,c,row,c,dist+1});
                }

                if(!vis[row-1][c+1][row][c+1]){
                    vis[row-1][c+1][row][c+1]=true;
                    q.push({row-1,c+1,row,c+1,dist+1});
                }
            }
        }

        // vertical sofa
        else{

            int col=y1;
            int r=min(x1,x2);

            // rotate right
            if(col+1<m &&
               valid(r,col) &&
               valid(r+1,col) &&
               valid(r,col+1) &&
               valid(r+1,col+1))
            {
                if(!vis[r][col][r][col+1]){
                    vis[r][col][r][col+1]=true;
                    q.push({r,col,r,col+1,dist+1});
                }

                if(!vis[r+1][col][r+1][col+1]){
                    vis[r+1][col][r+1][col+1]=true;
                    q.push({r+1,col,r+1,col+1,dist+1});
                }
            }

            // rotate left
            if(col-1>=0 &&
               valid(r,col) &&
               valid(r+1,col) &&
               valid(r,col-1) &&
               valid(r+1,col-1))
            {
                if(!vis[r][col-1][r][col]){
                    vis[r][col-1][r][col]=true;
                    q.push({r,col-1,r,col,dist+1});
                }

                if(!vis[r+1][col-1][r+1][col]){
                    vis[r+1][col-1][r+1][col]=true;
                    q.push({r+1,col-1,r+1,col,dist+1});
                }
            }
        }
    }

    cout << -1 << "\n";
}