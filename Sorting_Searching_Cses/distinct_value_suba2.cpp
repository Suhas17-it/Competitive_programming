#include <bits/stdc++.h>
using namespace std;

int main(){


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k , n;
    cin >> k >> n;

    vector<long long> arr(k);
    for(int i = 0 ; i < k ; i ++){
        cin >> arr[i];
    }

    map<long long,int> freq;

    int l = 0;
    long long ans = 0;
    for(int r = 0 ; r < k ; r ++){
        freq[arr[r]] += 1;

        while(l <= r && freq.size() > n){
            freq[arr[l]] -= 1;

            if(freq[arr[l]] == 0){
                freq.erase(arr[l]);
            }
            l += 1;
        }
        // cout << r << " " << l << endl;
        ans +=  ((r - l) + 1);
    }

    cout << ans << endl;


}