#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    vector<int> comp = arr;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
 
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();
    }
 
    vector<int> last(n, -1);
 
    int left = 0;
    int ans = 0;
 
    for(int right = 0; right < n; right++){
 
        if(last[arr[right]] != -1){
            left = max(left, last[arr[right]] + 1);
        }
 
        last[arr[right]] = right;
 
        ans = max(ans, right - left + 1);
    }
 
    cout << ans;
}