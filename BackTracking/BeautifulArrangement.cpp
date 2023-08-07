class Solution {
public:
    int cnt=0;
    void solve(int i,int n,vector<int> &vis){
        if(i>n){
             cnt++;
        }
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                if((j%i)==0 || (i%j)==0){
                    vis[j]=1;
                    solve(i+1,n,vis);
                    vis[j]=0;
                }
            }
        }
    }
    int countArrangement(int n) {
        vector<int> vis(n+1,0);
        solve(1,n,vis);
        return cnt;
    }
};