#include <bits/stdc++.h>
using namespace std;

struct State{
    long long l , r , idx;
};

class Fenw{
    public:
        vector<long long> bit;
        int n;
        
        Fenw(int n){
            this->n = n;
            bit.resize(n,0);
        }

        void add(int idx,int val){
            
            while(idx < n){
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int sum(int idx){
            int val = 0;
            while(idx > 0){
                val += bit[idx];
                idx -= idx & -idx;
            }
            return val;
        }
    
};

int getPos(long long idx,vector<long long>& vals){
    return lower_bound(vals.begin(),vals.end(),idx) - vals.begin() + 1;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    vector<State> arr(n);

    vector<long long> vals;
    for(int i = 0 ; i < n ; i ++){
        long long l , r;
        cin >> l >> r;
        arr[i] = {l,r,i};
        vals.push_back(r);

    }

    sort(arr.begin(),arr.end(),[](State &a , State &b){
        if(a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });

    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    
    vector<long long> contains(n,0) , contained(n,0);

    Fenw fenw(n + 1);
    for(int i = n - 1 ; i >= 0 ; i --){
        int pos = getPos(arr[i].r,vals);

        contains[arr[i].idx] += fenw.sum(pos);

        fenw.add(pos,1);
    }

    long long processes = 0;
    Fenw fenw2(n + 1);
    for(int i = 0 ; i < n ; i ++){
        int pos = getPos(arr[i].r,vals);
        contained[arr[i].idx] = processes - fenw2.sum(pos - 1);
        fenw2.add(pos,1);
        processes += 1;
    }
    
    for(long long x : contains){
        cout << x << " ";
    }

    cout << endl;

    for(long long x : contained){
        cout << x << " ";
    }
    cout << endl;


}