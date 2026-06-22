#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int n , k , m;
  cin >> n >> k >> m;

  vector<pair<long long,long long>> arr;
  for(int i = 0 ; i < n ; i ++){
      long long c , v;
      cin >> c >> v;
      arr.push_back({c,v});
  }
  
  sort(arr.begin(),arr.end(),[](pair<long long,long long> &a,pair<long long,long long> &b){
    return a.second > b.second;
  });
  
  unordered_map<long long,long long> taken;
  
  int picked = 0;
  long long ans = 0;
  for(int i = 0 ; i < n ; i ++){
    long long color = arr[i].first , val = arr[i].second;
    if(!taken.count(color)){
      taken[color] = i;
      ans += val;
      picked += 1;
    }
    
    if(picked == m){
      break;
    }
  }
  
  int rem = k - picked;
  
  for(int i = 0 ;i < n && rem > 0; i ++){
    long long color = arr[i].first , val = arr[i].second;
    
    if(taken.count(color) && taken[color] == i) continue;
    ans += val;
    rem -=1;
    if(rem == 0){
      break;
    }
  }
  cout << ans << endl;
}