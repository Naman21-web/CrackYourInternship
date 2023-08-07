class Solution{
public:
    int solve(int i,int n,int arr[],int target){
        if(target==0) return 1;
        if(i==n) return 0;
        int take=0;
        if(target>=arr[i]) take = solve(i+1,n,arr,target-arr[i]);
        int notTake = solve(i+1,n,arr,target);
        return take || notTake;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++) sum += arr[i];
        if(sum%2!=0) return 0;
        return solve(0,N,arr,sum/2);
    }
};