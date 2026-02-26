
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    int total = 0;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
        total += arr[i];
    }


    vector<bool> dp(total + 1 , false);

    dp[0] = true;

    for(int num : arr){
        for(int sum = total ; sum >= num ; sum --){
           if(dp[sum - num]){
            dp[sum] = true;
           }
        }
    }

    vector<int> ans;
    
    for(int s = 1 ; s <= total ; s ++){
        if(dp[s]){
            ans.push_back(s);
        }
    }

    cout<<ans.size()<<"\n";
    for(int x : ans){
        cout<<x<<" ";
    }

}