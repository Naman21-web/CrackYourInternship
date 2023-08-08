class Solution{
  public:
    bool solve(int i,int a[],int n,int k,int target,int sum){
        if(target==sum){
            k--;
            sum=0;
        }
        if(i==n){
            if(k==0) return 1;
            return 0;
        }
        bool ans = false;
        for(int j=i;j<n;j++){
            if(a[j]<=target-sum){
                sum += a[j];
                swap(a[i],a[j]);
                ans = ans || solve(i+1,a,n,k,target,sum);
                if(ans==true) return true;
                swap(a[j],a[i]);
                sum -= a[j];
            }
        }
        return ans;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++){
             sum += a[i];
         }
         if((sum%k)!=0) return false;
         int target = sum/k;
         return solve(0,a,n,k,target,0);
    }
};