class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0),ans;
        queue<int> q;
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int top=q.front();
            ans.push_back(top);
            q.pop();
            for(auto x:adj[top]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        return ans;
    }
};