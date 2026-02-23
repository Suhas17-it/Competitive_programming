#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n ;
        cin >> n;

        long long full = 1;
        long long split = 1;

        for(int i =  2 ; i <= n ; i ++){
            long long new_full =  (2 * full + split ) % mod;
            long long new_split =  (4 * split + full ) % mod;

            full = new_full;
            split = new_split;
        }

        cout << (full + split) % mod << endl;
    }
}