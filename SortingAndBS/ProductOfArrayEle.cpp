class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here       
        // int n=nums.size();
        vector<long long int> ans(n);
        long long int temp=nums[0];
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=temp;
            temp *= nums[i];
        }
        temp=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] *= temp;
            temp *= nums[i]; 
        }
        return ans;
    }
};