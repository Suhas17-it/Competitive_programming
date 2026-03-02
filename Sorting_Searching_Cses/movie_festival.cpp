#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int,int>> movies(n);
    for(int i = 0 ; i < n ; i ++){
        int a , b;
        cin >> a >> b;
        movies[i] = {a,b};
    }

    sort(movies.begin(),movies.end(),[](const pair<int,int>& a , const pair<int,int>& b){
        return a.second < b.second;
    });

    int end = 0 , ans = 0;

    for(int i = 0 ; i < n ; i ++){
        if(movies[i].first >= end){
            ans += 1;
            end = movies[i].second;
        }
    }

    cout << ans << endl;
}