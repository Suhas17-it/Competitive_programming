#include <bits/stdc++.h>
using namespace std;
int main(){

    long long n , k , q;
    cin >> n >> k >> q;

    vector<long long> temp(2e5 + 2 , 0);
    
    for(int i = 0 ; i < n ; i ++){
        long long x , y;
        cin >> x >> y;
        temp[x] += 1;
        temp[y + 1] -= 1;
    }

    for(int i = 1 ; i <= 2e5 + 1 ; i ++){
        temp[i] += temp[i - 1];
    }

    for(int i = 0 ; i <= 2e5 + 1; i ++){
        if(temp[i] >= k){
            temp[i] = 1;
        }
        else{
            temp[i] = 0;
        }
    }

    for(int i = 1 ; i <= 2e5 + 1; i ++){
        temp[i] += temp[i - 1];
    }



    for(int i = 0 ; i < q ; i ++){
        long long a , b;
        cin >> a >> b;

        
        if(a == 1){
            cout << temp[b] << endl;
            continue;
        }
        long long ans = temp[b] - temp[a - 1];
        cout << ans << endl;
    }

}