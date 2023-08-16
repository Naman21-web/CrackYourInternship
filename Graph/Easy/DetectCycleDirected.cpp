bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &path){
        path[node]=1;
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                // path[neighbour]=1;
                vis[neighbour]=1;
                if(dfs(neighbour,adj,vis,path)) return true;
                // path[neighbour]=0;
            }
            else if(path[neighbour]) return true;
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> path(V,0),vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i]=1;
                if(dfs(i,adj,vis,path)) return true;
            }
        }
        return false;
    }