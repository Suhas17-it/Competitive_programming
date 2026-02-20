// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
// For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

// 2+2+5
// 3+3+3
// 2+2+2+3

// Input
// The first input line has two integers n and x: the number of coins and the desired sum of money.
// The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
// Output
// Print one integer: the number of ways modulo 10^9+7.
#include <bits/stdc++.h>
using namespace std;

int main(){


    int n , x;
    cin >> n >> x;

    using ll = long long;
    vector<int> arr(n);
    const int mod = 1e9 + 7;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    vector<ll> dp(x + 1);
    dp[0] = 1;

    for(int num : arr){
        for(int sum = num ; sum <= x ; sum ++){
            dp[sum] = ( dp[sum] + dp[sum - num] ) % mod;
        }
    }

    cout<<dp[x]<<endl;
}