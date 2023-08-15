int findSum(int i,int j,int freq[]){
    int sum=0;
    for(int k=i;k<=j;k++) sum += freq[k];
    return sum;
}

// int findOptimal(int i,int j,int freq[],int n){
//     if(i>j) return 0;
//      if(i==j) return freq[j];
//     int sum = findSum(i,j,freq);
//     int ans=INT_MAX;
//     for(int k=i;k<=j;k++){
//         ans = min(ans,findOptimal(i,k-1,freq,n)+findoptimal(k+1,j,freq,n));
//     }
//     return ans;
// }

int findOptimal(int i,int j,int freq[],int n,int dp[][]){
    if(i>j) return 0;
    if(i==j) return freq[j];
    if(dp[i][j]!=-1) return dp[i][j];
    int sum = findSum(i,j,freq);
    int ans=INT_MAX;
    for(int k=i;k<=j;k++){
        ans = min(ans,findOptimal(i,k-1,freq,n,dp)+findoptimal(k+1,j,freq,n,dp));
    }
    return dp[i][j]=ans;
}

int optimalSearchTree(int keys[], int freq[], int n){
    int dp[n][n]={-1};
    return findOptimal(0,n-1,freq,n,dp);
}