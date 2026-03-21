class Fenwick{
public:
    vector<int> bit;
    int n;
    Fenwick(int n){
        this-> n = n;
        bit.resize(n);
    }

    void update(int i,int val){
        for( ;i < n ; i = i | (i + 1) ){
            bit[i] += val;
        }
    }

    int query(int i){
        int sum = 0;
        for( ; i >= 0 ; i = (i & (i + 1)) - 1){
            sum += bit[i];
        }

        return sum;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        int id = 0;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        Fenwick ft(temp.size());
        unordered_map<int,int> comp;
        for(int val : temp){
            comp[val] = id++;
        }
        vector<int> ans(nums.size());
        for(int i = n - 1 ; i >= 0 ; i --){

            int rank = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();

            ans[i] = (rank > 0) ? ft.query(rank - 1) : 0;

            ft.update(rank,1);
        }

        return ans;
    }
};