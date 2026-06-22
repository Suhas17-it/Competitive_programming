#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;


    map<long long,long long> mp;
    
    for(int i = 0 ; i < n ; i ++){

        long long a , b;
        cin >> a >> b;

        mp[a] += 1;
        mp[a + b] -= 1;
    }

    long long active = 0LL , prev =-1;

    vector<long long> ans(n + 1 , 0LL);

    for(auto& [pos,delta] : mp){

        if(prev != -1){
            ans[active] += (pos - prev);
        }
        active += delta;
        prev = pos;
    }


    for(int i = 1 ; i <= n ; i ++){
        cout << ans[i] << " ";
    }
    cout << endl;
}