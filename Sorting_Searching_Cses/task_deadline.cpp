#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<long long,long long>> arr(n);
    for(int i = 0 ; i < n ; i ++){
        long long l , r;
        cin >> l >> r;
        arr[i] = {l,r};
    }


    sort(arr.begin(),arr.end());

    long long currTime = 0;
    long long reward = 0;

    for(int i = 0; i < n ; i ++){
        currTime += arr[i].first;
        reward += arr[i].second - currTime;
    }

    cout << reward << endl;
}