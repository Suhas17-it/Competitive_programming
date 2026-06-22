#include <bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin >> n;

    vector<int> diff(1e6 + 1 , 0);


    for(int i = 0 ; i < n ; i ++){

        int a , b;
        cin >> a >> b;

        diff[a] += 1;
        diff[b + 1] -= 1;
    }


    int ans = 0;
    int d = 0;
    for(int i = 0 ; i <= 1e6 ; i ++){
        d += diff[i];
        ans = max(ans,d);
    }

    cout << ans << endl;
}