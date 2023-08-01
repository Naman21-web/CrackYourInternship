class NumArray {
public:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node] = tree[2*node]+tree[2*node+1];
    }

    int query1(int node,int st,int en,int l,int r){
        if(st>r || en<l) return 0;
        if(l<=st && en<=r){
            return tree[node];
        }
        int mid = (st+en)/2;
        int q1 = query1(2*node,st,mid,l,r);
        int q2 = query1(2*node+1,mid+1,en,l,r);
        return q1+q2;
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        tree.resize(4*n);
        build(1,0,n-1);
    }
    int sumRange(int left, int right) {
        return query1(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */