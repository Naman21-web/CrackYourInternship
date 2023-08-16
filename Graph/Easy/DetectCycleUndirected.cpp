bool dfs(int node,int parent,vector<int> adj[],vector<int> &vis){
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=1;
                if(dfs(neighbour,node,adj,vis)) return true;
            }
            else if(neighbour != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i]=1;
                if(dfs(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }