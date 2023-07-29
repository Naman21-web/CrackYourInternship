class Solution {
public:
    int find(vector<vector<int>>& matrix,int no,int n){
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            int lo=0,hi=n-1;
            int ans=-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(matrix[i][mid]<=no){
                    ans=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }
            cnt += ans+1;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int lo=matrix[0][0],hi=matrix[n-1][n-1];
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(find(matrix,mid,n)>=k) {hi=mid-1;ans=mid;}
            // else if(find(matrix,mid)==k) return mid;
            else {lo=mid+1;}
        }
        return ans;
    }
    ~Solution(int x){
        
    }
};