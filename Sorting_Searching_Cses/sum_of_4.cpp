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
        
        // int j = i + 1;

        for(int j = i + 1 ; j < n ; j ++){
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;

            int l = j + 1;
            int r = n - 1;

            while(l < r){

                int mid = (l + r) / 2;

                long long sum = arr[i].first + arr[j].first + arr[l].first + arr[r].first;

                if(sum > x){
                    r-=1;
                    while(r >= l && arr[r] == arr[r + 1]){
                        r-=1;
                    }
                }

                else if(sum < x){
                    l += 1;
                    while(l <= r && arr[l] == arr[l + 1]){
                        l += 1;
                    }
                }
                else{
                    cout << arr[i].second + 1 << " "<< arr[j].second + 1 << " "<< arr[l].second + 1 << " " << arr[r].second + 1 << endl;
                    return 0;
                }
            }
        }

    }

    cout << "IMPOSSIBLE\n";


}