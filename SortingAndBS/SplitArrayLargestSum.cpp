class Solution {
public:
    vector<int> sum;
    // int split(int k,int i,int n,vector<int> &nums){
    //     if(k==0){
    //         return sum[i];
    //     }
    //     if(i==n){
    //         return INT_MAX;
    //     }
    //     int sum=0,mini=INT_MAX;
    //     for(int j=i;j<n-k;j++){
    //         sum += nums[j];
    //         int cost=split(k-1,j+1,n,nums);
    //         int ans=max(sum,cost);
    //         mini = min(mini,ans);
    //     }
    //     return mini;
    // }

    // int split(int k,int i,int n,vector<int> &nums,vector<vector<int>> &dp){
    //     if(k==0){
    //         return sum[i];
    //     }
    //     if(i==n){
    //         return INT_MAX;
    //     }
    //     if(dp[i][k] != -1) return dp[i][k];
    //     int sum=0,mini=INT_MAX;
    //     for(int j=i;j<n-k;j++){
    //         sum += nums[j];
    //         int cost=split(k-1,j+1,n,nums,dp);
    //         int ans=max(sum,cost);
    //         mini = min(mini,ans);
    //     }
    //     return dp[i][k]=mini;
    // }

    // int split(int k,int n,vector<int> &nums,vector<vector<int>> &dp){
    //     for(int i=0;i<n;i++) dp[i][0]=sum[i];
    //     for(int part=0;part<k;part++) dp[n][part]=INT_MAX;

    //     for(int i=n-1;i>=0;i--){
    //         for(int part=1;part<k;part++){
    //             int sum=0,mini=INT_MAX;
    //             for(int j=i;j<n-part;j++){
    //                 sum += nums[j];
    //                 int cost=dp[j+1][part-1];
    //                 int ans=max(sum,cost);
    //                 mini = min(mini,ans);
    //             }
    //             dp[i][part]=mini;
    //         }
    //     }
    //     return dp[0][k-1];
    // }

    int check(int k,int mid,vector<int> &nums,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum>mid){
                sum=nums[i];
                if(sum>mid) return false;
                k--;
                if(k==0) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // int n=nums.size();
        // sum.resize(n);
        // sum[n-1]=nums[n-1];
        // for(int i=n-2;i>=0;i--){
        //     sum[i] = sum[i+1]+nums[i];
        // }
        // // vector<vector<int>> dp(n,vector<int> (k,-1));
        // vector<vector<int>> dp(n+1,vector<int> (k+1,0));
        // // return split(k-1,0,n,nums,dp);   
        // return split(k,n,nums,dp);  

        int n=nums.size();
        int lo=0,hi=INT_MAX,ans=-1;
        // int size = n/k;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(k,mid,nums,n)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }          
        return ans;
    }
};