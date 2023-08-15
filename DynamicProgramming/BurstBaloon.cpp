class Solution {
public:
    // int burst(int i,int j,vector<int> &nums){
    //     if(i>j) return 0;
    //     int ans=0;
    //     for(int k=i;k<=j;k++){
    //         ans = max(ans,nums[i-1]*nums[k]*nums[j+1]+burst(i,k-1,nums)+burst(k+1,j,nums));
    //     }
    //     return ans;
    // }

    // int burst(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=0;
    //     for(int k=i;k<=j;k++){
    //         ans = max(ans,nums[i-1]*nums[k]*nums[j+1]+burst(i,k-1,nums,dp)+burst(k+1,j,nums,dp));
    //     }
    //     return dp[i][j]=ans;
    // }

    int burst(int n,vector<int> &nums,vector<vector<int>> &dp){
        for(int i=n;i>0;i--){
            for(int j=1;j<=n;j++){
                if(i>j) {dp[i][j]=0; continue;}
                int ans=0;
                for(int k=i;k<=j;k++){
                    ans = max(ans,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        // return burst(1,n,nums,dp);
        return burst(n,nums,dp);
    }
};