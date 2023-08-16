class Solution {
public:
    // void dfs(int n,int m,int oldc,int i,int j,vector<vector<int>> &image,vector<int> &x,vector<int> &y,int color){
    //     for(int k=0;k<4;k++){
    //         int nrow=i+x[k];
    //         int ncol=j+y[k];
    //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldc){
    //             image[nrow][ncol]=color;
    //             dfs(n,m,oldc,nrow,ncol,image,x,y,color);
    //         }
    //     }
    // }

        void bfs(int n,int m,int i,int j,int oldc,vector<vector<int>> &image,vector<int> &x,vector<int> &y,int color){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=a+x[k];
                int ncol=b+y[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldc){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldc=image[sr][sc];
        if(oldc==color) return image;
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        vector<int> x={1,0,-1,0};
        vector<int> y={0,1,0,-1};
        
        // dfs(n,m,oldc,sr,sc,image,x,y,color);
        bfs(n,m,oldc,sr,sc,image,x,y,color);
        return image;
    }
};