#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> in(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        in[b].push_back(a);
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    dp[1][0] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {

        if (!(mask & 1)) continue;

        if ((mask & (1 << (n - 1))) && mask != (1 << n) - 1)
            continue;

        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;

            int prev_mask = mask ^ (1 << u);

            for (int v : in[u]) {
                if (prev_mask & (1 << v)) {
                    dp[mask][u] = (dp[mask][u] + dp[prev_mask][v]) % MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}