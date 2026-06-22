#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;


    vector<array<long long,3>> customers;

    for(int i = 0 ; i < n ; i ++){  

        long long l , r ;
        cin >> l >> r;

        customers.push_back({l,r,i});
    }

    sort(customers.begin(),customers.end());


    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
    
    vector<long long> ans(n);
    long long rooms = 0;
    for(auto &c : customers){

        long long st = c[0] , end = c[1] , idx = c[2];

        if(!pq.empty() && pq.top().first < st){

            long long room = pq.top().second;
            pq.pop();

            ans[idx] = room;
            pq.push({end,room});
        }
        else{

            rooms += 1;
            ans[idx] = rooms;
            pq.push({end,rooms});
        }
    }

    cout << rooms << endl;

    for(int i = 0 ; i < n ; i ++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
    }