#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k;


    ordered_set<int> s;

    for(int i = 1 ; i <= n ; i ++){
        s.insert(i);
    }

    long long pos = 0;

    while(!s.empty()){

        pos = (pos + k) % s.size();

        auto it = s.find_by_order(pos);

        cout << *it << " ";

        s.erase(it);

    }

   return 0;
}