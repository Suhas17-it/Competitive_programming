class Fenw{
    public:
        vector<int> bit;
        int n;
        Fenw(int n){
            this->n = n;
            bit.resize(n);
        }

        void up(int i,int val){
            for(; i < n ; i = i | (i + 1)){
                bit[i] += val;
            }
        }

        int q(int i){
            int s = 0;
            for(; i >= 0 ; i = (i & (i + 1)) - 1){
                s += bit[i];
            }
            return s;
        }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        vector<long long> arr;
        int n = nums1.size();
        for(int i = 0 ; i < n ; i ++){
            arr.push_back(nums1[i] - nums2[i]);
        }

        vector<long long> temp = arr;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        int sz = temp.size();
        for(int i = 0 ; i < sz ; i ++) temp.push_back(temp[i] + diff);

        Fenw ft(temp.size());
        long long ans = 0;
        for(int i = 0 ; i < n ; i ++){

            int target = arr[i] + diff;
            int idx = upper_bound(temp.begin(),temp.end(),target) - temp.begin() - 1;

            if(idx >= 0){
                ans += ft.q(idx);
            }

            int idx2 = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            ft.up(idx2,1);
        }

        return ans;
    }
};