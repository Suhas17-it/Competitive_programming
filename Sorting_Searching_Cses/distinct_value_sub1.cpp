#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }   

    long long ans = 0;

    int l = 0;
    map<long long,int> freq;

    for(int r = 0 ; r < n ; r ++){

        freq[arr[r]] += 1;

        while(l <= r && freq[arr[r]] > 1){
            freq[arr[l]] -= 1;
            if(freq[arr[l]] == 0){
                freq.erase(arr[l]);
            }
            l += 1;
        }

       ans += (r - l + 1);
    }


   cout << ans << endl;

   return 0;
}