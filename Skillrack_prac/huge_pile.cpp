#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;


    while(t--){
        
        long long n , k;
        cin >> n >> k;

        long long ans = 0;

        int l = n , r = n;

        while(r != 1){

            if(l <= k && r >= k){
                // cout << ans << endl;
                break;
            }

            ans += 1;
            l /= 2;
            r = (r / 2) + (r % 2);
        }
        
        if(l <= k && r >= k){
            cout << ans << endl;
        }
        else{   
            cout << -1 << endl;
        }
    }

    return 0;
}

