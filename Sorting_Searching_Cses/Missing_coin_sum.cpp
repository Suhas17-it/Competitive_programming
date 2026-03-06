#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];
 
 
    long long val = 1;
    
    sort(arr.begin(),arr.end());
    
    for(int sum : arr){
        
        if(val < sum){
            cout << val << endl;
            return 0;
        }
        
        val += sum;
    }
    
    
    cout << val << endl;
 
 
}