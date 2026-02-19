#include <bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin >> n;

    const int mod = 1e9 + 7;
    
    vector<long long> dp(n + 1);
    dp[0] = 1;

    for(int sum = 1; sum <= n ; sum ++){
        for(int dice = 1 ; dice <= 6 ; dice ++){
            if(sum - dice >= 0){
                dp[sum] = (dp[sum] + dp[sum - dice]) % mod;
            }
        }
    }

    cout<<dp[n]<<endl;

}