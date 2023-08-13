class Solution {
public:
    // int lis(int ind,int n,int prev,vector<int> &nums){
    //     if(ind==n) return 0;
    //     int len = lis(ind+1,n,prev,nums);
    //     if(prev==-1 || nums[ind]>nums[prev]){
    //         len = max(len,1+lis(ind+1,n,ind,nums));
    //     }
    //     return len;
    // }


    // int lis(int ind,int n,int prev,vector<int> &nums,vector<vector<int>> &dp){
    //     if(ind==n) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int len = lis(ind+1,n,prev,nums,dp);
    //     if(prev==-1 || nums[ind]>nums[prev]){
    //         len = max(len,1+lis(ind+1,n,ind,nums,dp));
    //     }
    //     return dp[ind][prev+1]=len;
    // }

    // int lis(int n,vector<int> &nums,vector<vector<int>> &dp){
        
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev=ind-1;prev>=-1;prev--){
    //             int len = dp[ind+1][prev+1];
    //             if(prev==-1 || nums[ind]>nums[prev]){
    //                 len = max(len,1+dp[ind+1][ind+1]);
    //             }
    //             dp[ind][prev+1]=len;
    //         }
    //     }
    //     return dp[0][-1+1];
    // }

    // int lis(int n,vector<int> &nums){
    //     vector<int> curr(n+1,0),next(n+1,0);
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev=ind-1;prev>=-1;prev--){
    //             int len = next[prev+1];
    //             if(prev==-1 || nums[ind]>nums[prev]){
    //                 len = max(len,1+next[ind+1]);
    //             }
    //             curr[prev+1]=len;
    //         }
    //         next=curr;
    //     }
    //     return next[-1+1];
    // }

    // int lis(int n,vector<int> &nums){
    //     vector<int> dp(n,1);
    //     int maxi=1;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[i]>nums[j])dp[i]=max(dp[i],1+dp[j]);
    //         }
    //         maxi=max(maxi,dp[i]);
    //     }
    //     return maxi;
    // }
    int binary(vector<int> nums,int len,int target){
        int lo=0,hi=len;
        int ans=-1;
        while(lo<=hi){
            int mid = lo+((hi-lo)/2);
            if(nums[mid]>=target){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }

    int lis(int n,vector<int> &nums){
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp[len-1]){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                // int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                int ind = binary(temp,len,nums[i]);
                temp[ind]=nums[i];
            }
        }
        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        return lis(0,n,n,nums,dp);
        // return lis(n,nums,dp);
        return lis(n,nums);
    }
};