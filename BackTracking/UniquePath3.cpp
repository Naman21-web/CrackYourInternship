class Solution {
public:
    int findPath(int row,int col,int &zero,vector<vector<int>> &grid,int n,int m){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]==-1) return 0;
        if(grid[row][col]==2){
            if(zero==-1) return 1;
            return 0;
        }
        grid[row][col]=-1;
        zero--;
        int right = findPath(row,col+1,zero,grid,n,m);
        int left = findPath(row,col-1,zero,grid,n,m);
        int up = findPath(row-1,col,zero,grid,n,m);
        int down = findPath(row+1,col,zero,grid,n,m);
        zero++;
        grid[row][col]=0;
        return right+left+up+down;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int startx,starty,zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
            }
        }
        return findPath(startx,starty,zero,grid,n,m);
    }
};