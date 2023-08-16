void dfs(int node,vector<int> adj[],stack<int> &st,vector<int> &vis){
	    for(auto neighbour:adj[node]){
	        if(!vis[neighbour]){
	            vis[neighbour]=1;
	            dfs(neighbour,adj,st,vis);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // vector<int> indeg(V,0),ans;
	   // queue<int> q;
	   // for(int i=0;i<V;i++){
	   //     for(auto node:adj[i]){
	   //         indeg[node]++;
	   //     }
	   // }
	   // for(int i=0;i<V;i++){
	   //     if(indeg[i]==0) q.push(i);
	   // }
	   // while(!q.empty()){
	   //     int node = q.front();
	   //     q.pop();
	   //     ans.push_back(node);
	   //     for(auto neighbour:adj[node]){
	   //         indeg[neighbour]--;
	   //         if(indeg[neighbour]==0) q.push(neighbour);
	   //     }
	   // }
	   // return ans;
	   stack<int> st;
	   vector<int> vis(V,0),ans;
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           vis[i]=1;
	           dfs(i,adj,st,vis);
	       }
	   }
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
	}