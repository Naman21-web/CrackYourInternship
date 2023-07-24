class Solution {
public:
    // int profit(int i,int n,vector<int>& prices,bool flag){
    //     if(i==n)return 0;
    //     if(flag){
    //         return max(-prices[i]+profit(i+1,n,prices,!flag),profit(i+1,n,prices,flag));
    //     }
    //     else{
    //        return max(prices[i]+profit(i+1,n,prices,!flag),profit(i+1,n,prices,flag)); 
    //     }
    // }
    // int profit(int i,int n,vector<int>& prices,bool flag,vector<vector<int>> &dp){
    //     if(i==n)return 0;
    //     if(dp[i][flag]!=-1)return dp[i][flag];
    //     if(flag){
    //         return dp[i][flag]=max(-prices[i]+profit(i+1,n,prices,!flag,dp),profit(i+1,n,prices,flag,dp));
    //     }
    //     else{
    //        return dp[i][flag]=max(prices[i]+profit(i+1,n,prices,!flag,dp),profit(i+1,n,prices,flag,dp)); 
    //     }
    // }
    // int profit(int n,vector<int>& prices,vector<vector<int>> &dp){
        
    //     for(int i=n-1;i>=0;i--){
    //         for(int flag=0;flag<2;flag++){
    //             if(flag){
    //                 dp[i][flag]=max(-prices[i]+dp[i+1][!flag],dp[i+1][flag]); 
    //             }
    //             else{
    //                 dp[i][flag]=max(prices[i]+dp[i+1][!flag],dp[i+1][flag]); 
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }

    int profit(int n,vector<int>& prices){
        vector<int> curr(2,0),next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int flag=0;flag<2;flag++){
                if(flag){
                    curr[flag]=max(-prices[i]+next[!flag],next[flag]); 
                }
                else{
                    curr[flag]=max(prices[i]+next[!flag],next[flag]); 
                }
            }
            next=curr;
        }
        return curr[1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int> (2,-1));
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        // return profit(0,n,prices,true,dp);
        // return profit(n,prices,dp);
        return profit(n,prices);

    }
};