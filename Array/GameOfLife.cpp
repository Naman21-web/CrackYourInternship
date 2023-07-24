class Solution {
public:
    vector<int> x={-1,-1,-1,0,0,1,1,1};
    vector<int> y={-1,0,1,-1,1,-1,0,1};
    int cnt(int i,int j,int n,int m,vector<vector<int>> &board){
        int ans=0;
        for(int k=0;k<8;k++){
            int dx=i+x[k],dy=j+y[k];
            if(dx>=0 && dy>=0 && dx<n && dy<m){
                ans += board[dx][dy] & 1;
            }
        }
        return ans;
    }

    int check(int cnto,int curr){
        if(curr==0 && cnto==3) return 1;
        if(curr==1){
            if(cnto==1 || cnto>3) return 0;
            if(cnto==2 || cnto==3) return 1;
        }
        return 0;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> res=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnto = cnt(i,j,n,m,board);
                int x = check(cnto,board[i][j]);
                if(x==1) board[i][j] |= 2;
            }
        }
        board=res;
    }
};