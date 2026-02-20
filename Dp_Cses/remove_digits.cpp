// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input
// The only input line has an integer n.
// Output
// Print one integer: the minimum number of steps.
// Constraints

// 1 \le n \le 10^6
// 27  take 7 and subtract 20
// takae 2 20 - 2 = 18
// like wise 5 steps needed
#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;

    using ll = long long;
    vector<ll> dp(n + 1 , 1e9);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i ++){

        int x = i;
        while(x){
            int d = x % 10;
            dp[i] = min(dp[i],dp[i - d] + 1);
            x/=10;
        }
    }

    cout<<dp[n]<<endl;
}