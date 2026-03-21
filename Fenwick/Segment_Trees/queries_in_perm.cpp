class Fenw{
    public:
        vector<int> bit;
        int n;
        Fenw(int n){
            this->n = n;
            bit.resize(n,0);
        }

        void up(int i,int val){
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
    vector<int> processQueries(vector<int>& queries, int m) {

        int n = queries.size();
        Fenw ft (n + m);

        vector<int> pos(m + 1);
        for(int i = 1 ; i <= m ; i ++){
            pos[i] = n + i - 1;
            ft.up(pos[i],1);
        }


        vector<int> ans;
        int front = n - 1;
        for(int qq : queries){

            int idx = pos[qq];

            ans.push_back(ft.q(idx - 1));

            ft.up(idx,-1);

            int newIdx = front;
            pos[qq] = newIdx;
            ft.up(newIdx,1);
            front--;
        }

    return ans;
    }
};