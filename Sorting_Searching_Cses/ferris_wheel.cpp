#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , x ;
    cin >> n >> x;

    vector<int> w(n);

    for(int i = 0 ; i < n ; i ++){
        cin >> w[i];
    }

    sort(w.begin(),w.end());

    int ans = 0;

    int i  = 0 , j = n - 1;

    while(i <= j){
        if(w[i] + w[j] <= x){
            ans += 1;
            i ++;
            j--;
        }
        else{
            ans += 1;
            j--;
        }
    }

    cout << ans << endl;
}