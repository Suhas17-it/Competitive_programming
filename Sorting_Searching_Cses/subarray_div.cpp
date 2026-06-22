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

    long long pref = 0LL;

    map<long long,long long> mp;
    mp[0] = 1;
    long long ans = 0;
    for(long long x : arr){
        pref += x;

        long long rem = ((pref % n) + n) % n;

        ans += mp[rem];

        mp[rem] += 1;
    }

    cout << ans << endl;
}