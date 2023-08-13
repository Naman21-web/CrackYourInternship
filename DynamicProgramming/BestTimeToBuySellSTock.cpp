class Solution {
public:
    // int profit(int i,int n,vector<int>& prices,int cap){
    //     if(i==n)return 0;
    //     if(cap==0) return 0;
    //     if(cap%2==0){
    //         return max(-prices[i]+profit(i+1,n,prices,cap-1),profit(i+1,n,prices,cap));
    //     }
    //     else{
    //        return max(prices[i]+profit(i+1,n,prices,cap-1),profit(i+1,n,prices,cap)); 
    //     }
    // }

    // int profit(int i,int n,vector<int>& prices,int cap,vector<vector<int>> &dp){
    //     if(i==n)return 0;
    //     if(cap==0) return 0;
    //     if(dp[i][cap]!=-1) return dp[i][cap];
    //     if(cap%2==0){
    //         return dp[i][cap]=max(-prices[i]+profit(i+1,n,prices,cap-1,dp),profit(i+1,n,prices,cap,dp));
    //     }
    //     else{
    //        return dp[i][cap]=max(prices[i]+profit(i+1,n,prices,cap-1,dp),profit(i+1,n,prices,cap,dp)); 
    //     }
    // }

    // int profit(int n,vector<int>& prices,int k,vector<vector<int>> &dp){

    //     for(int i=n-1;i>=0;i--){
    //         for(int cap=1;cap<=2*k;cap++){
    //             if(cap%2==0){
    //                 dp[i][cap]=max(-prices[i]+dp[i+1][cap-1],dp[i+1][cap]);
    //             }
    //             else{
    //                 dp[i][cap]=max(prices[i]+dp[i+1][cap-1],dp[i+1][cap]);
    //             }
    //         }
    //     }
    //     return dp[0][2*k];
    // }

   int profit(int n,vector<int>& prices,int k){

       vector<int> curr(2*k+1,0),next(2*k+1,0);
        for(int i=n-1;i>=0;i--){
            for(int cap=1;cap<=2*k;cap++){
                if(cap%2==0){
                    curr[cap]=max(-prices[i]+next[cap-1],next[cap]);
                }
                else{
                    curr[cap]=max(prices[i]+next[cap-1],next[cap]);
                }
            }
            next=curr;
        }
        return curr[2*k];
    }

    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int> ((2*k)+1,-1));
        // vector<vector<int>> dp(n+1,vector<int> ((2*k)+1,0));
        // return profit(0,n,prices,2*k);
        // return profit(0,n,prices,2*k,dp);
        // return profit(n,prices,k,dp);
        return profit(n,prices,k);

    }
};