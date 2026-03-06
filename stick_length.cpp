#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];
 
 
    long long res = 0LL;
    sort(arr.begin(),arr.end());
    int mid = (n / 2);
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] != arr[mid]){
            res += abs(arr[i] - arr[mid]);
        }
    }
 
    cout << res << endl;
 
 
}