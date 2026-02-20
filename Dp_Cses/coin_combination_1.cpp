// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
// For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

// 2+2+5
// 2+5+2
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , target;
    cin >> n >> target;

    const int mod = 1e9 + 7;
    vector<long long> dp(target + 1);
    dp[0] = 1;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    for(int sum = 1 ; sum <= target ; sum ++){
        for(int num : arr){
            if(sum - num >= 0){
                dp[sum] = (dp[sum] + dp[sum - num]) % mod;
            }
        }
    }

    cout<<dp[target]<<endl;
}