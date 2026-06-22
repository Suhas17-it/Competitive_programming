#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n , c;
    cin >> n >> c;

    map<long long,long long> mp;
    for(int i = 0 ; i < n ;  i++){

        long long a , b , cc;
        cin >> a >> b >> cc;

        mp[a] += cc;
        mp[b + 1] -= cc;
    }


    long long total = 0LL , prev = -1;

    long long curr = 0;
    for(auto& [pos,delta] : mp){

        if(prev != -1){
            total += (pos - prev) * min(c,curr);
        }

        curr += delta;
        prev = pos;
    }

    cout << total << endl;
}