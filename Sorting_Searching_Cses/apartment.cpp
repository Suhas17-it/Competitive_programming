#include <bits/stdc++.h>
using namespace std;

int main(){

    int n , m , k ;
    cin >> n  >> m >> k;


    vector<int> person(n);

    for(int i = 0 ; i < n ; i ++){
        cin >> person[i];
    }

    vector<int> sz(m);

    for(int i = 0  ; i < m ; i ++){
        cin >> sz[i];
    }


    sort(person.begin(),person.end());
    sort(sz.begin(),sz.end());
    int ans = 0;
    
    int i  = 0 , j = 0;

    while(i < n && j < m){
        if(abs(person[i] - sz[j]) <= k){
            ans += 1;
            i ++;
            j++;
        }
        else if(sz[j] < person[i] - k){
            j++;
        }
        else{
            i++;
        }
    }

    cout << ans << endl;

}