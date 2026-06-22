#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    map<long long,long long> mp;

    for(int i = 0 ; i < n ; i ++){
        long long x;
        cin >> x;

        mp[x] += 1;
    }

    long long ans = 1;
    
    const int mod = 1e9 + 7;
    for(auto [val , f] : mp){
        
        ans = (ans * (f + 1)) % mod;

    }

    ans = (ans - 1 + mod) % mod;

    cout << ans << endl;
}