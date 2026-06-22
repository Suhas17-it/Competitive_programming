#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0;  i < n ; i ++){
        cin >> arr[i];
    }


    unordered_map<int,int> mp; 
    // longest subarray with equal 0 and 1
    mp[0] = -1;

    int cnt = 0;
    int ans = 0;

    for(int i = 0 ; i < arr.size() ; i ++){
        if(arr[i] == 1){
            cnt += 1;
        }
        else{
            cnt -= 1;
        }

        if(mp.count(cnt)){
            ans = max(ans,i - mp[cnt]);
        }
        else{
            mp[cnt] = i;
        }
    }

    cout << ans << endl;
    return 0;
}