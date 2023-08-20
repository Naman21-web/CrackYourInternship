vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,1,-1};
 
class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    void unionBySize(int a,int b){
        int par1 = findParent(a);
        int par2 = findParent(b);
        if(par1==par2) return;
        if(size[par1]>=size[par2]){
            size[par1] += size[par2];
            parent[par2] = par1;
        }
        else{
            size[par2] += size[par1];
            parent[par1] = par2;
        }
    }
    int findSize(int num){
        return size[num];
    }
    int findParent(int num){
        if(parent[num]==num) return num;
        return parent[num] = findParent(parent[num]);
    }
};

class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &vis,DSU *ds){
        queue<pair<int,int>> q;
        int no = i*m+j;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newr = r + x[k];
                int newc = c + y[k];
                if(newc>=0 && newr>=0 && newr<n && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
                    vis[newr][newc]=1;
                    ds->unionBySize(no,newr*m+newc);
                    q.push({newr,newc});
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n*m;
        DSU *ds = new DSU(sz);
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    bfs(i,j,n,m,grid,vis,ds);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int sz=1;
                    unordered_map<int,int> mp;
                    for(int k=0;k<4;k++){
                        int newr = i + x[k];
                        int newc = j + y[k];
                        if(newc>=0 && newr>=0 && newr<n && newc<m && grid[newr][newc]==1){
                            int par = ds->findParent(newr*m+newc);
                            // cout<<par<<" ";
                            if(mp.find(par)==mp.end()){
                                sz += ds->findSize(par);
                                mp[par]=1;
                            }
                        }
                    }
                    ans = max(ans,sz);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,ds->findSize(ds->findParent(i*m+j)));
            }
        }
        return ans;
    }
};