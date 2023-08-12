 // int solve(int i,int n,int k,vector<int> nums,int spaces){
    //     if(i==n) return 0;
    //     if(spaces==0){
    //         return solve(i+1,n,k,nums,nums[i]+1);
    //     }
    //     else{
    //         if((k-spaces)<nums[i]){
    //             // if(spaces==k+1) 
    //             spaces--;
    //             return (k-spaces)*(k-spaces) + solve(i+1,n,k,nums,nums[i]+1);
    //         }
    //         else{
    //             int take = solve(i+1,n,k,nums,spaces+nums[i]+1);
    //             spaces--;
    //             int notTake = (k-spaces)*(k-spaces) + solve(i+1,n,k,nums,nums[i]+1);
    //             return min(take,notTake);
    //         }
    //     }
    // }
    
    int solve(int i,int n,int k,vector<int> nums,int spaces,vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][spaces]!=-1) return dp[i][spaces];
        if(spaces==0){
            return dp[i][spaces]=solve(i+1,n,k,nums,nums[i]+1,dp);
        }
        else{
            if((k-spaces)<nums[i]){
                // if(spaces==k+1) 
                spaces--;
                return dp[i][spaces]=(k-spaces)*(k-spaces) + solve(i+1,n,k,nums,nums[i]+1,dp);
            }
            else{
                int take = solve(i+1,n,k,nums,spaces+nums[i]+1,dp);
                spaces--;
                int notTake = (k-spaces)*(k-spaces) + solve(i+1,n,k,nums,nums[i]+1,dp);
                return dp[i][spaces]=min(take,notTake);
            }
        }
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (k+2,-1));
        return solve(0,n,k,nums,0,dp);
    }