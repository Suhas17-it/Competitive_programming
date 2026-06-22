#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x , n;
    cin >> x >> n;

    set<long long> pos;
    multiset<long long> len;


    pos.insert(0);
    pos.insert(x);

    len.insert(x);


    while(n--){

        long long p;
        cin >> p;

        auto it = pos.upper_bound(p);

        long long left = *prev(it);
        long long right = *it;

        len.erase(len.find(right - left));


        len.insert(p - left);
        len.insert(right - p);

        pos.insert(p);

        cout << *len.rbegin() << " ";


    }
    return 0;
}