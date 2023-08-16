class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> newgraph(n);
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto node:graph[i]){
                newgraph[node].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour:newgraph[node]){
                indeg[neighbour]--;
                if(indeg[neighbour]==0) q.push(neighbour);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};