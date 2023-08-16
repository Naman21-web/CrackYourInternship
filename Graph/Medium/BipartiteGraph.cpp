bool bfs(vector<int> &color,int node,vector<int> adj[]){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            for(auto neighbour:adj[currnode]){
                if(color[neighbour]==-1){
                    color[neighbour] = color[currnode]^1;
                    q.push(neighbour);
                }
                else if(color[neighbour]==color[currnode]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            color[i]=1;
	            if(!bfs(color,i,adj)) return false;
	        }
	    }
	    return true;
	}