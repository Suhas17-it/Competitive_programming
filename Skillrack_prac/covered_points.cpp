#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    cin >> n;

    map<long long,long long> mp;

    int mini = 0;

    for(int i = 0 ; i < n ; i ++){
        long long a , b;
        cin >> a >> b;

        mp[a] += 1;
        mp[b + 1] -= 1;


    }


    long long active = 0 , prev = 0;
    vector<long long> ans(n + 1 , 0);
    for(auto &[pos , delta] : mp){
        
        if(prev != -1){
            ans[active] += pos - prev;
        }

        active += delta;
        prev = pos;
    }


    for(int k = 1 ; k <= n ; k ++){
        cout << ans[k] << " ";
    }


}