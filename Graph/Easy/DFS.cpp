class Solution {
  public:
    void dfs(vector<int> adj[],int i,vector<int> &vis,vector<int> &ans){
        ans.push_back(i);
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(adj,x,vis,ans);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans,vis(V,0);
        dfs(adj,0,vis,ans);
        return ans;
    }
};