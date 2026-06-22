
#include <bits/stdc++.h>
using namespace std;

struct State{
    long long l , r , idx;
};
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    vector<State> arr(n); 

    for(int i = 0 ; i < n ; i ++){
        long long l ,r;
        cin >> l >> r;
        arr[i]= {l,r,i};
    }

    sort(arr.begin(),arr.end(),[](State &a , State &b){
        
        if(a.l == b.l) return a.r > b . r;

        return a.l < b.l;
    });


    vector<int> contains(n) , contained(n,0);
    long long max_r = 0;
    for(int i = 0 ; i < n ; i ++){
        if(arr[i].r <= max_r){
            contained[arr[i].idx] = 1;
        }
        max_r = max(max_r,arr[i].r);
    }

    long long min_r = INT_MAX;

    for(int i = n - 1 ; i >= 0 ; i --){
        if(arr[i].r >= min_r){
            contains[arr[i].idx] = 1;
        }
        min_r = min(min_r,arr[i].r);
    }


    for(int x : contains) cout << x << " ";
    cout << endl;
    
    for(int x : contained) cout << x << " ";
    cout << endl;
   



}