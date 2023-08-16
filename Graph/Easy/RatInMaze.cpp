// User function template for C++

class Solution{
    public:
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};
    char check(int k){
        if(k==0) return 'U';
        if(k==1) return 'D';
        if(k==2) return 'L';
        if(k==3) return 'R';
    }
    void find(int i,int j,int n,vector<vector<int>> &m,vector<vector<int>> &vis,vector<string> &ans,string &s){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        for(int k=0;k<4;k++){
            int dx = x[k]+i;
            int dy = y[k]+j;
            if(dx>=0 && dy>=0 && dx<n && dy<n && vis[dx][dy]==0 && m[dx][dy]==1){
                s += check(k);
                vis[dx][dy]=1;
                find(dx,dy,n,m,vis,ans,s);
                vis[dx][dy]=0;
                s.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int> (n,0));
        string s;
        if(m[0][0]==0) return ans;
        vis[0][0]=1;
        find(0,0,n,m,vis,ans,s);
        return ans;
    }
};

    