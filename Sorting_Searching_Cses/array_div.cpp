#include <bits/stdc++.h>
using namespace std;


bool can(vector<long long>& arr,long long limit,long long x){

    long long taken = 1 , sum = 0;

    for(int i = 0 ; i < arr.size() ; i ++){
        if(sum + arr[i] > limit){
            taken += 1;
            sum = arr[i];
        }
        else{
            sum += arr[i];
        }
    }

    return taken <= x;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long x;
    cin >> x;

    vector<long long> arr(n);

    long long total = 0 , mx = 0;

    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
        total += arr[i];
        mx = max(mx,arr[i]);
    }

    
    long long low = mx , high = total;

    long long ans = 0LL;
    while(low <= high){

        long long mid =  low + (high - low) / 2;

        if(can(arr,mid,x)){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }

    cout << ans << endl;

}