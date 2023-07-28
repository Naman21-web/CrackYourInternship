class Solution {
public:
    void bfs(int n,int m,vector<vector<int>> &mat,vector<vector<int>> &ans,vector<int> &x,vector<int> &y){
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j = q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=i+x[k];
                int ncol=j+y[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && ans[nrow][ncol]==-1){
                    ans[nrow][ncol]=t+1;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,-1));
        vector<int> x={1,0,-1,0};
        vector<int> y={0,1,0,-1};

        bfs(n,m,mat,ans,x,y);
        return ans;
    }
};