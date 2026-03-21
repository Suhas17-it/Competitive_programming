/* The functions which
builds the segment tree */
class Seg{
    public:
        vector<int> seg;
        int n;
        Seg(int n,int a[]){
            seg.resize(4 * n , 0);
            vector<int> arr;
            for(int i = 0 ; i < n ; i ++) arr.push_back(a[i]);
            built(0,0,n-1,arr);
        }
        
        void built(int idx,int l,int r,vector<int>& arr){
            if(r == l){
                seg[idx] = arr[l];
                return;
            }
            
            int mid = (l + r) / 2;
            built(2 * idx + 1 , l , mid , arr);
            built(2 * idx + 2 , mid + 1 , r , arr);
            
            seg[idx] = min(seg[2 * idx + 1],seg[2 * idx + 2]);
        }
        
        int query(int idx,int l,int r,int ql,int qr){
            if(l > qr || r < ql) return INT_MAX;
            
            if(l >= ql && r <= qr) {
                return seg[idx];
            }
            
            int mid = (l + r) / 2;
            
            return min(query(2 * idx + 1 , l , mid , ql,qr),query(2 * idx + 2 , mid + 1 , r , ql , qr));
        }
        
        void up(int idx,int l,int r,int id,int val){
            if(l == r){
                seg[idx] = val;
            }
            
            int mid = (l + r) / 2;
            
            if(id <= mid){
                up(2 * idx + 1,l,mid , id, val);
            }
            else{
                up(2 * idx + 2 , mid + 1 ,r ,id , val);
            }
            
            seg[idx] = min(seg[2 * idx + 1],seg[2 * idx + 2]);
        }
};
Seg *sg;
int *constructST(int arr[], int n) {
    // Your code here
    sg = new Seg(n,arr);
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    return sg->query(0,0,n-1,a,b);
}