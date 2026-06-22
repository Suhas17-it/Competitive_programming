#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;

    set<int> s;


    for(int i = 1 ; i <= n ; i ++){
        s.insert(i);
    }

    auto it = s.begin();

    while(!s.empty()){

        it ++;

        if(it == s.end()){
            it = s.begin();
        }

        cout << *it << " ";

        auto to_erase = it;
        it ++;
        s.erase(to_erase);

        if(it == s.end()){
            it = s.begin();
        }
    }

    
}