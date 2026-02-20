#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> cost(n), pages(n);
    for(int i = 0; i < n; i++)
        cin >> cost[i];

    for(int i = 0; i < n; i++)
        cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for(int i = 0; i < n; i++){
        for(int j = x; j >= cost[i]; j--){
            dp[j] = max(dp[j], dp[j - cost[i]] + pages[i]);
        }
    }

    cout << dp[x] << endl;
}