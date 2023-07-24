class Solution {
public:
    // bool func(int i,int n,vector<int> &nums,vector<vector<int>> &dp){
    //     if(i>=n-1){
    //         return true;
    //     }
    //     for(int j=1;j<=nums[i];j++){
    //         if(dp[i][j]==-1){
    //             if(func(i+j,n,nums,dp)==true) dp[i][j]=1;
    //             else dp[i][j] = 0;
    //         }
    //         if(dp[i][j]==1){
    //             return true;
    //             break;
    //         }
    //     }
    //     return false;
    // }
    // bool canJump(vector<int>& nums) {
    //     // int n=nums.size();
    //     // int x = 1e5;
    //     // vector<vector<int>> dp(n,vector<int> (x,-1));
    //     // // if(n==1 && nums[0]==0){
    //     // //     return true;
    //     // // }
    //     // return func(0,n,nums,dp);
    //     int res = nums[0];
    //     for(int i=0;i<nums.size();i++){
    //         if(i>res) return false;
    //         res =max(res,i+nums[i]);
    //     }
    //     return true;
    // }

//Recursion
    // int jump(int i,vector<int> &nums,int n){
    //     if(i>=n) return true;
    //     for(int j=1;j<=nums[i];j++){
    //         if(jump(i+j,nums,n)) return true;
    //     }
    //     return false;
    // }

//Memoization
    // int jump(int i,vector<int> &nums,int n,vector<int> &dp){
    //     if(i>=n-1) return true;
    //     if(dp[i] != -1) return dp[i];
    //     for(int j=1;j<=nums[i];j++){
    //         if(jump(i+j,nums,n,dp)) return dp[i]= true;
    //     }
    //     return dp[i] = false;
    // }

//Tabulation
    int jump(vector<int> &nums,int n,vector<bool> &dp){
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if(i+j>n-1 || dp[i+j]==true) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }

    bool canJump(vector<int> &nums){
        int n=nums.size();
        if(n==1) return true;

        // return jump(0,nums,n);

        // vector<int> dp(n+1,-1);
        // return jump(0,nums,n,dp);

        vector<bool> dp(n+1,false);
        return jump(nums,n,dp);
        
        
    }
};