#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n , q;
    cin >> n >> q;

    int LOG = 60;
    vector<vector<int>> up(LOG, vector<int>(n+1, 0));
    for(int i = 1 ; i <= n ; i ++){
        cin >> up[0][i];
    }

    for(int j = 1 ; j < LOG; j ++){
        for(int i = 1 ; i <= n ; i ++){
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    for(int i = 0 ; i < q ; i ++){
        long long x , k;
        cin >> x >> k;

        for(int j = 0; j < LOG ; j ++){
            if(k & (1LL << j)){
                x = up[j][x];
            }
        }
        cout<<x<<endl;
    }
}