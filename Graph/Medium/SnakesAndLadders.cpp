// class Solution {
// public:
//     // int sal(int i,int j,int n,vector<vector<int>> &board){
//     //     if(i<=0 && j>=n) return 0;
//     //     if(board[i][j]!=-1){
//     //         int x = board[i][j];
//     //         i=x/n;
//     //         if(i%2==0) j = (x%n);
//     //         else j= n-(x%n);
//     //     }
//     //     int mini=INT_MAX;;
//     //     for(int k=1;k<7;k++){
//     //         int a=j+k;
//     //         if(a>=n && i>0){
//     //             a = a%n;
//     //             if((i-1)%2!=0) a = n-a;
//     //             // else a = n-a;
//     //             mini = min(mini,1+sal(i-1,a,n,board));
//     //         }
//     //         else mini = min(mini,1+sal(i,a,n,board));
//     //     }
//     //     return mini;
//     // }

//     int sal(int i,int j,int n,vector<vector<int>> &board,vector<vector<int>> &dp){
//         if(i<=0 && j>=n) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(board[i][j]!=-1){
//             int x = board[i][j];
//             i=x/n;
//             if(i%2==0) j = (x%n);
//             else j= n-(x%n);
//         }
//         int mini=INT_MAX;;
//         for(int k=1;k<7;k++){
//             int a=j+k;
//             if(a>=n && i>0){
//                 a = a%n;
//                 if((i-1)%2!=0) a = n-a;
//                 // else a = n-a;
//                 mini = min(mini,1+sal(i-1,a,n,board,dp));
//             }
//             else mini = min(mini,1+sal(i,a,n,board,dp));
//         }
//         return dp[i][j]=mini;
//     }

//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n = board.size();

//         vector<vector<int>> dp(n,vector<int> (n,-1));
//         return sal(n-1,0,n,board,dp);
//     }
// };

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int sz = board.size(); int target = sz * sz ;
        unordered_map<int, int> moves; 
        moves[1] = 0; // Zero(No) moves when we are in square 1
        queue<int> q ; q.push(1); //BFS method
        
        while(!q.empty())
        {
            int current_sq = q.front(); q.pop();
            
            for(int i=1; i<=6; i++)
            {
                int next_sq = current_sq + i ; 
                if(next_sq > target){break;}
                
                int row = (next_sq - 1)/sz ;
                int col = (row % 2 == 0) ? (next_sq - 1) % sz : sz - 1 - ((next_sq-1) % sz)  ;
                
                if(board[sz-1-row][col] != -1)
                {
                    next_sq = board[sz-1-row][col] ;
                }
                if(moves.count(next_sq) == 0)
                {
                    moves[next_sq] = moves[current_sq] + 1;
                    if(next_sq == target){return moves[next_sq];}
                    q.push(next_sq);
                }
            }
        }
        
        return -1 ;
    }
};