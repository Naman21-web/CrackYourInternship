class Solution 
{
    public:
    bool check(int A[],int N,int M,int mid){
        int no=1;
        int sum=0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum>mid){
                sum=A[i];
                no++;
            }
        }
        return (no>M);
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int hi=0;
        int lo=INT_MIN;
        for(int i=0;i<N;i++){
            if(A[i]>lo){
                lo=A[i];
            }
            hi += A[i];
        }
        int ans=-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(A,N,M,mid)){
                lo=mid+1;
            }
            else {ans=mid;hi=mid-1;}
        }
        return ans;
    }
};