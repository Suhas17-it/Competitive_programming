#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , a , b;
    cin  >> n >> a >> b;


    vector<long long> arr(n);
    
    vector<long long> pref(n + 1,0LL);
    for(int i = 0 ; i< n ; i ++){
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }

    long long ans = LLONG_MIN;

    multiset<long long> ms;
    for(int i = a ; i <= n ; i ++){
        ms.insert(pref[i - a]);
        if(i > b){
            ms.erase(ms.find(pref[i - b - 1]));
        }

        if(!ms.empty()){
            ans = max(ans,pref[i] - *ms.begin());
        }
    }

    cout << ans << endl;

}