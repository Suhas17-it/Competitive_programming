#include <bits/stdc++.h>
using namespace std;
int maxSum = 0;

long long solve(vector<int>& a,int i,int j,vector<vector<long long>>& dp){

    if(i > j){
        return 0;
    }


    if(dp[i][j] != -1){
        return dp[i][j];
    }

    long long l = a[i] + min(solve(a,i+2,j,dp),solve(a,i+1,j-1,dp));
    long long r = a[j] + min(solve(a,i,j-2,dp),solve(a,i+1,j-1,dp));


    return dp[i][j] = max(l,r);
}
int main(){

    int n;
    cin >> n;

    vector<int> a(n);

    long long total = 0;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
        total += a[i];
    }
    
    vector<vector<long long>> dp(n,vector<long long>(n,-1));

    long long ans = solve(a,0,n-1,dp);


    cout << ans << endl;




}