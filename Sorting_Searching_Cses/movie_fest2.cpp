#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k;

    vector<pair<long long,long long>> arr(n);

    for(int i = 0 ; i < n ; i ++){
        long long x , y;
        cin >> x >> y;
        arr[i] = {y,x};
    }

    sort(arr.begin(),arr.end());

    multiset<long long> st;

    for(int i = 0 ; i < k ; i ++){
        st.insert(0);
    }   

    long long ans = 0;

    for(int i = 0 ; i < n ; i ++){
        long long x = arr[i].second , y = arr[i].first;
        auto it = st.lower_bound(x);
        if(it == st.begin() && *it > x) continue;
        if(it != st.begin())--it;

        st.erase(it);

        ans += 1;
        st.insert(y);
    }

    cout << ans << endl;

   
}