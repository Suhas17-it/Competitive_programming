#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i ++) cin >> arr[i];
 
    unordered_map<int,int> mp;
    for(int i = 0 ; i < n ; i ++){
        mp[arr[i]] = i;
    }
 
 
    int i = 1 , steps = 0;
    int prev = -1;
    while(i <= n){
        steps++;
        while(mp[i] > prev){
            prev = mp[i];
            i++;
        }
        prev = -1;
        
    }
 
    cout << steps << endl;
}