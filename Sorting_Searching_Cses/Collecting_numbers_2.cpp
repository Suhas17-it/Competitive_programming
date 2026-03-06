#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n , m;
    cin >> n >> m;
 
    vector<int> arr(n + 1);
    
    unordered_map<int,int> mp;
    vector<int> pos(n+1);
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }
 
    int points = 1;
    for(int i = 1 ; i < n ; i ++){
        if(pos[i]  > pos[i + 1]){
            points++;
        }
    }
 
 
    for(int i = 0 ; i < m ; i ++){
        int a , b;
        cin >> a >> b;
        // a-- , b --;
 
        int x = arr[a] , y = arr[b];
 
        set<int> s;
        s.insert(x - 1);
        s.insert(x);
        s.insert(y - 1);
        s.insert(y);
 
        for(int v : s){
            if(v >= 1 && v < n){
                if(pos[v] > pos[v + 1]) points--;
            }
        }
 
        swap(arr[a],arr[b]);
        swap(pos[x],pos[y]);
 
        for(int v : s){
            if(v >= 1 && v < n){
                if(pos[v] > pos[v + 1]) points++;
            }
        }
 
        cout << points << endl;
    }
 
 
}