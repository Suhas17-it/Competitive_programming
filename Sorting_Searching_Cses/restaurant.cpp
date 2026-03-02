#include <bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(NULL);

    int n;
    cin >> n;

    map<int,int> mp;

    for(int i = 0 ; i < n ; i ++){
        int a , b ;
        cin >> a >> b;
        mp[a] += 1;
        mp[b + 1] -= 1;
    }

    int curr =  0;
    int maxVal = 0;
    for(auto [val,points] : mp){
        curr += points;
        maxVal = max(maxVal,curr);
    }

    cout << maxVal << endl;


}