class Fenw{
    public:
        vector<long long> bit;
        int n;

        Fenw(int n){
            this->n = n;
            bit.resize(n,0);
        }


        void u(int i,long long v){
            
            for(; i < n ; i = i | (i + 1)){
                bit[i] += v;
            }
        }

        long long q(int i){
            long long sum = 0;
            for(; i >= 0 ; i = (i & (i + 1)) -1){
                sum += bit[i];
            }
            return sum;
        }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
       
       vector<long long> temp;
       for(auto x : nums) temp.push_back(x);
       sort(temp.begin(),temp.end());
       temp.erase(unique(temp.begin(),temp.end()),temp.end());
        int sz = temp.size();
        for(int i = 0 ; i < sz ;i ++){
            temp.push_back(temp[i] * 2);
        }

        Fenw ft(temp.size());
        int n = nums.size();
        int ans = 0 ;
        for(int i = n - 1 ; i >= 0 ; i --){

            long long rank = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();

            ans += (rank > 0) ? ft.q(rank - 1) : 0;

            long long rank2 = lower_bound(temp.begin(),temp.end(),1LL * nums[i] * 2) - temp.begin();
            ft.u(rank2,1);
        }

        return ans;
    }
};