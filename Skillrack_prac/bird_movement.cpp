#include <bits/stdc++.h>
using namespace std;
int main(){
  
    
    int n , q;
    cin >> n >> q;
    vector<int> arr(n + 1,1);
    long long count = 0;
    unordered_map<int,int> birds;

    for(int i = 1; i <= n; i++){
      birds[i] = i;
    }
    
    while(q--){
      
      int x;
      cin >> x;
      
      if(x == 2){
        cout << count << endl;
      }
      else{
        int l , r;
        cin >> l >> r;
        
        int oldpos = birds[l];
        arr[oldpos] -= 1;
        if(arr[oldpos] == 1){
          count -= 1;
        }
        
        int newpos = r;
        birds[l] = newpos;
        arr[newpos] += 1;
        if(arr[newpos] == 2){
          count += 1;
        }
      }
      
    }
}