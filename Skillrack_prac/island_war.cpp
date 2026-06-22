#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n , m;
  cin >> n >> m;
  
  vector<pair<int,int>> q;
  for(int i = 0 ; i < m ; i ++){
    int a , b;
    cin >> a >> b;
    q.push_back({a,b});
  }
  
  
  sort(q.begin(),q.end(),[](pair<int,int>&a , pair<int,int>& b){
      
      if(a.second == b.second){
        return a.first < b.first;
      }
      return a.second < b.second;
  });
  
  int last = 0 , ans = 0;
  
  for(int i = 0 ; i < m ; i ++){
    if(q[i].first >= last){
      last = q[i].second;
      ans += 1;
    }
  }
  
  cout << ans << endl;
}