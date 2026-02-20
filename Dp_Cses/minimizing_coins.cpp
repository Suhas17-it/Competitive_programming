// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
// Input
// The first input line has two integers n and x: the number of coins and the desired sum of money.
// The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
// Output
// Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){

    int n , target;
    cin >> n >> target;


    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }


    vector<long long> dp(target + 1 , 1e9);
    dp[0] = 0;

    for(int num : arr){
        for(int sum = num ; sum <= target; sum ++){
            dp[sum] = min(dp[sum],dp[sum - num] + 1);
        }
    }

    if(dp[target] == 1e9){
        cout<<"-1\n";
        return 0;
    }
    cout<<dp[target]<<endl;
}   