#include <bits/stdc++.h>
using namespace std;

int main(){

    int n ,m , q;
    cin >> n >> m >> q;

    vector<long long> arr(n + 1, 0);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    vector<vector<long long>> op;
    for(int i = 0 ; i < m ; i ++){
        int l , r, d;
        cin >> l >> r >> d;
        op.push_back({l , r, d});
    }

    vector<pair<long long,long long>> query(q);

    for(int i = 0 ; i < q ; i ++){
        int x , y;
        cin >> x >> y;
        query[i] = {x , y};
    }


    vector<long long> op_count(m + 1 , 0);

    for(int i = 0 ; i < q ; i ++){
        int x = query[i].first;
        int y = query[i].second;

        op_count[x - 1] += 1;
        op_count[y] -= 1;
    }

    for(int i = 1 ; i <= m ; i ++){
        op_count[i] += op_count[i - 1];
    }

    vector<long long> ans(n + 1 , 0);
    for(int i = 0 ; i < m ; i ++){
        int l = op[i][0];
        int r = op[i][1];
        int d = op[i][2];

        ans[l - 1] += d * op_count[i] * 1LL;
        ans[r] -= d * op_count[i] * 1LL;
    }

    for(int i = 1 ; i < n ; i ++){
        ans[i] += ans[i - 1];
    }

    
    for(int i = 0 ; i < n ; i ++){
        cout << ans[i]  + arr[i] << " ";
    }

    return 0;
}