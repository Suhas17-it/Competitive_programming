#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    
    int r , c , k; 
    cin >> r >> c >> k;
    
    vector<vector<int>> grid(r,vector<int>(c,0));
    
    for(int i = 0 ; i < r ; i ++){
      string s;
      cin >> s;
      for(int j = 0 ; j < c ; j ++){
        grid[i][j] = s[j] - '0';
      }
    }
      
    long long ans = 0;
    
    for(int left = 0 ; left < c ; left ++){

      vector<long long> row(r,0);
      for(int right = left ; right < c ; right ++){
        
        for(int i = 0 ; i < r ; i ++){
          row[i] += grid[i][right];
        }

        vector<long long> freq(250001,0);
        freq[0] = 1;
        long long pref = 0;
        for(int num : row){
          pref += num;
          if(pref - k >= 0){
            ans += freq[pref - k];
          }

          freq[pref] += 1;
        }
      }
    }

    cout << ans << endl;

}
