class Solution {
public:
//     int func(int n,vector<int> &dp){
//         if(n==1 || n==2) return n;
//         if(dp[n]!=-1) return dp[n];
//         return dp[n]=func(n-1,dp)+func(n-2,dp);
//     }
//     int climbStairs(int n) {
//         // vector<int> dp(n+1);
//         // dp[0]=0;
//         // dp[1]=1;
//         // dp[2]=2;
//         // for(int i=3;i<=n;i++){
//         //     dp[i] = dp[i-1]+dp[i-2];
//         // }
//         if(n==1 || n==2) return n;
//         int prev2=1;
//         int prev1=2;
//         for(int i=3;i<=n;i++){
//             int cur = prev1+prev2;
//             prev2=prev1;
//             prev1=cur;
//         } 
// //        return dp[n];
//         return prev1;
//     }

//Recursion
// int climb(int n){
//     if(n==1 || n==2 || n==3) return n;
//     return climb(n-1)+climb(n-2);
// }

//Memoization
// int climb(int n,vector<int> &dp){
//     if(n==1 || n==2 || n==3) return n;
//     if(dp[n] != -1)return dp[n];
//     return dp[n]=climb(n-1)+climb(n-2);
// }

//Tabulation
// int climb(int n,vector<int> &dp){
//     dp[0]=0;
//     dp[1]=1;
//     dp[2]=2;
//     dp[3]=3;
//     for(int i=4;i<=n;i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }

//Space Efficient
int climb(int n){
    int prev1=3,prev2=2;
    int curr;
    for(int i=4;i<=n;i++){
        curr = prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int climbStairs(int n){
    //return climb(n);
   
    // vector<int> dp(n+1,-1);
   // return climb(n,dp);

//    if(n==1 || n==2 || n==3) return n;
//    vector<int> dp(n+1);
//     return climb(n,dp);

    if(n==1 || n==2 || n==3) return n;
    return climb(n);
}
};