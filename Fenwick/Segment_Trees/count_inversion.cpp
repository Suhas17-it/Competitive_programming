

class Fenw{
    public:
        vector<int> bit;
        int n;
        Fenw(int n){
            this->n = n;
            bit.assign(n,0);
        }
        
        void update(int i,int val){
            for(; i < n ; i = i | (i + 1)){
                bit[i] += val;
            }
        }
        
        int q(int i){
            int sum = 0;
            for(; i >= 0 ; i = (i & (i + 1)) - 1){
                sum += bit[i];
            }
            
            return sum;
        }
};
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
       
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        
        int ans = 0;
        Fenw ft(temp.size());
        for(int i = n - 1 ; i >= 0 ; i --){
            
            int rank = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            
            ans += (rank > 0) ? ft.q(rank - 1) : 0;
            
            ft.update(rank,1);
        }
        
        return ans;
    }
};