#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n , d;
  cin >> n >> d;
  
  long long maxT = 2e5 + 1;
  
  vector<int> diff(1e6 + 2);
  for(int i = 0 ; i < n ; i ++){
    long long s , t;
    cin >> s >> t;
    
    maxT = max(maxT , t + 1);
    if((t - d) < s) continue;
    
    diff[s] += 1;
    diff[t - d + 1] -= 1;
  }
  
  long long active = 0 , res = 0;
  for(int i = 1 ; i <=1e6 ; i ++){
    active += diff[i];
    res += (((active) * (active -1)) / 2 );
  }
    cout << res << endl;
}