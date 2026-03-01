#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tickets.insert(x);
    }

    for(int i = 0; i < m; i++){
        int p;
        cin >> p;

        auto it = tickets.upper_bound(p);

        if(it == tickets.begin()){
            cout << -1 << "\n";
        }
        else{
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}