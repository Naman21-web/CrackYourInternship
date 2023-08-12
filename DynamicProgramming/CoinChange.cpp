class Solution {
public:
    // int change(int i,vector<int>& coins, int amount,int n){
    //     if(i==n) return 1e9;
    //     if(amount<0) return 1e9;
    //     if(amount==0) return 0;
    //     //nt mini=1e8;
    //     return min(1+change(i,coins,amount-coins[i],n),change(i+1,coins,amount,n));
    // }

    // int change(int i,vector<int>& coins, int amount,int n,vector<vector<int>> &dp){
    //     if(amount<0 || i==n) return 1e9;
    //     //if(i==n) return 1e9;
    //     if(amount==0) return 0;
    //     //nt mini=1e8;
    //     if(dp[i][amount]!=-1) return dp[i][amount];
    //     return dp[i][amount]= min(1+change(i,coins,amount-coins[i],n,dp),change(i+1,coins,amount,n,dp));
    //}
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int x = change(0,coins,amount,n,dp);
        if(x>=1e9) return -1;
        return x;
    }
};