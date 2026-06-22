#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n , t;
    cin >> n >> t;

    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    long long l = 1 , r = 1e18;
    long long ans = -1;

    while(l <= r){
        
        long long mid = l + (r - l) / 2;

        long long total = 0;
        for(int i = 0 ; i < n ; i ++){
            total += mid / arr[i];
            if(total >= t) break;
        }

        if(total >= t){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout<<ans<<endl;
}