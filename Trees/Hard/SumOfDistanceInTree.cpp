class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>> &graph,vector<int> &count,vector<int> &subtree){
        for(auto child:graph[node]){
            if(child!=parent){
                dfs(child,node,graph,count,subtree);
                count[node] += count[child];
                subtree[node] += subtree[child] + count[child];
            }
        }
        count[node] += 1;
    }
    void dfs2(int node,int parent,vector<int> &count,vector<int> &ans,vector<vector<int>> &graph,int n){
        // ans[node] = ans[parent] + count[parent] - count[node] - count[node];
        for(auto child:graph[node]){
            if(child!=parent){
                ans[child] = ans[node] +  n - count[child] - count[child];
                dfs2(child,node,count,ans,graph,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> count(n,0),subtree(n,0);
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,graph,count,subtree);
        vector<int> ans(n);
        ans[0] = subtree[0];
        cout<<ans[0]<<" ";
        dfs2(0,-1,count,ans,graph,n);
        // for(auto child:graph[0]){
        //     dfs2(child,0,count,ans,graph);
        // }
        return ans;
    }
};