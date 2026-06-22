#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long x;
    cin >> x;

    vector<long long> arr(n);

    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }


    map<long long,long long> mp;
    mp[0] = 1;

    long long cnt = 0;
    long long pref = 0LL;
    for(long long val : arr){
        pref += val;

        if(mp.count(pref - x)){
            cnt += mp[pref - x];
        }
        mp[pref] += 1; 
    }

    cout << cnt << endl;
}