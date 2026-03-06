#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
 
    vector<int> arr(n);
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    long long max_sum = LLONG_MIN, current_sum = 0;
 
    for(int i = 0; i < n; i++){
        current_sum += arr[i];
 
        if(current_sum > max_sum){
            max_sum = current_sum;
        }
 
        if(current_sum < 0){
            current_sum = 0;
        }
    }
 
    cout << max_sum << endl;
}