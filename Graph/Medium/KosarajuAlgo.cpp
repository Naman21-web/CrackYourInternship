void dfs(int node,vector<int> &vis,stack<int> &st,vector<vector<int>> &adj,bool firstcall){
	    vis[node]=1;
	    for(auto neighbour:adj[node]){
	        if(!vis[neighbour]){
	            dfs(neighbour,vis,st,adj,firstcall);
	        }
	    }
	    if(firstcall)st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj,true);
            }
        }
        vector<vector<int>> reversedGraph(V);
        for(int i=0;i<V;i++){
            for(auto node:adj[i]){
                reversedGraph[node].push_back(i);
            }
        }
        int cnt=0;
        // vis.resize(V,0);
        for(int i=0;i<V;i++) vis[i]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                dfs(node,vis,st,reversedGraph,false);
                cnt++;
            }
        }
        return cnt;
    }