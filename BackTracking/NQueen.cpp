class Solution {
public:
    // bool isSafe(int row,int col,vector<string> &board,int n){
    //     int duprow=row;
    //     int dupcol=col;
    //     while(duprow>=0 && dupcol>=0){
    //         if(board[duprow][dupcol]=='Q') return false;
    //         duprow--;
    //         dupcol--;
    //     }
    //     duprow=row;
    //     dupcol=col;
    //     while(duprow<n && dupcol>=0){
    //         if(board[duprow][dupcol]=='Q') return false;
    //         duprow++;
    //         dupcol--;
    //     }
    //     duprow=row;
    //     dupcol=col;
    //     while(dupcol>=0){
    //         if(board[duprow][dupcol]=='Q')return false;
    //         dupcol--;
    //     }
    //     return true;
    // }
    // void solve(int i,int n,vector<vector<string>> &ans,vector<string> &board){
    //     if(i==n){
    //         ans.push_back(board);
    //         return;
    //     }
    //     for(int row=0;row<n;row++){
    //         if(isSafe(row,i,board,n)){
    //             board[row][i]='Q';
    //             solve(i+1,n,ans,board);
    //             board[row][i]='.';
    //         }
    //     }
    // }
    bool isSafe(int row,int col,vector<int> &l,vector<int> &ld,vector<int> &ud,int n){
        if(l[row]==0 && ld[row+col]==0 && ud[row-col+n-1]==0) return true;
        return false;
    }

    void solve(int i,int n,vector<vector<string>> &ans,vector<string> &board,vector<int> &l,vector<int> &ld,vector<int> &ud){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,i,l,ld,ud,n)){
                l[row]=1;
                ld[row+i]=1;
                ud[row-i+n-1]=1;
                board[row][i]='Q';
                solve(i+1,n,ans,board,l,ld,ud);
                l[row]=0;
                ld[row+i]=0;
                ud[row-i+n-1]=0;
                board[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s;
        for(int i=0;i<n;i++) s += '.'; 
        vector<string> board(n,s);
        vector<int> l(n,0),ud(2*n-1,0),ld(2*n-1,0);
        // solve(0,n,ans,board);
        solve(0,n,ans,board,l,ld,ud);
        return ans;
    }
};