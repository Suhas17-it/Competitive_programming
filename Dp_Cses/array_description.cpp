#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n , m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }


    vector<vector<long long>> dp(n,vector<long long>(m + 2));
    
    if(a[0] == 0){
        for(int v = 1 ; v <= m ; v++){
            dp[0][v] = 1;
        }
    
    }
    else{
        dp[0][a[0]] = 1;
    }


    for(int i = 1 ; i < n ; i ++){
        for(int v = 1 ; v <= m ; v ++){

            if(a[i] != 0 && a[i] != v) continue;

            dp[i][v] = dp[i - 1][v];

            if(v - 1 >= 0){
                dp[i][v] = ( dp[i][v] + dp[i - 1][v - 1]) % mod;
            }

            if(v + 1 <= m ){
                dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % mod;
            }
        }
    }

    long long ans = 0;

    for(int v = 1 ;  v <= m ; v ++){
        ans = (ans + dp[n - 1][v] )% mod;
    }

    cout<<ans<<endl;

}