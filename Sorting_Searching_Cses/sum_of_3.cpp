#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n , x;
    cin >> n >> x;

    vector<pair<long long,int>> arr(n);

    for(int i = 0 ; i < n ; i ++){
        long long val;
        cin >> val;
        arr[i] = {val,i};
    }

    sort(arr.begin(),arr.end());

    for(int i = 0 ; i < n ; i ++){
        if(i > 0 && arr[i] == arr[i - 1]) continue;

        long long l = i + 1;
        long long r = n - 1;

        while(l < r){

            long long mid = (l + r) / 2;

            long long sum = arr[i].first + arr[l].first + arr[r].first;

            if(sum > x){
                r -= 1;
            }
            else if(sum < x){
                l += 1;
            }
            else{
                // cout << sum << endl;
                cout << arr[i].second + 1 << " " << arr[l].second + 1 << " " << arr[r].second + 1 << endl;
                // cout << i + 1 << " " << l + 1 << " " << r + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}