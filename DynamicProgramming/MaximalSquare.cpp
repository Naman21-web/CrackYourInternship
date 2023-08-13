class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> prev(m,0),curr(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(matrix[i][0]=='1') curr[0]=1;
            else curr[0]=0;
            ans = max(ans,curr[0]);
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    curr[j] = 1 + min(prev[j-1],min(prev[j],curr[j-1]));
                }
                else curr[j]=0;
                // cout<<curr[j]<<" ";
                ans = max(ans,curr[j]);
            }
            // cout<<endl;
            prev=curr;
        }
        return ans*ans;
    }
};